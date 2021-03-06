#include <windows.h>

#include <iostream>

#include "plugin.hpp"

struct PluginLoader {
    HINSTANCE hinstance{nullptr};
    fp_create_plugin fn_create_plugin{nullptr};
    fp_destroy_plugin fn_destroy_plugin{nullptr};

    bool load(const char *library_path) {
        hinstance = LoadLibrary(library_path);
        if (hinstance == nullptr) {
            return false;
        }

        fn_create_plugin = (fp_create_plugin)GetProcAddress(hinstance, "create_plugin");
        if (fn_create_plugin == nullptr) {
            return false;
        }

        fn_destroy_plugin = (fp_destroy_plugin)GetProcAddress(hinstance, "destroy_plugin");
        if (fn_destroy_plugin == nullptr) {
            return false;
        }
        return true;
    }

    void unload() {
        BOOL free = FreeLibrary(hinstance);
    }
};

int main(int argc, char const *argv[]) {
    PluginLoader plugin_lib_one;
    plugin_lib_one.load("plugin_impl_one.dll");

    PluginLoader plugin_lib_two;
    plugin_lib_two.load("plugin_impl_two.dll");

    Plugin *plugin_one = plugin_lib_one.fn_create_plugin();
    std::cout << plugin_one->get_name() << std::endl;
    

    Plugin *plugin_two = plugin_lib_two.fn_create_plugin();
    std::cout << plugin_two->get_name() << std::endl;

    plugin_lib_one.fn_destroy_plugin(&plugin_one);
    plugin_lib_two.fn_destroy_plugin(&plugin_two);

    return 0;
}
