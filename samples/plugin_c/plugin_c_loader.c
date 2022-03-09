#include "plugin_c_loader.h"

int32_t load_plugin_c(const char* path, PluginCLibrary* lib) {
    lib->hinstance = LoadLibrary(path);
    if (lib->hinstance == 0) {
        return 1;
    }

    lib->create_plugin_context = (PFN_create_plugin_context)GetProcAddress(lib->hinstance, "fn_create_plugin_context");
    if (lib->create_plugin_context == 0) {
        return 1;
    }

    lib->destroy_plugin_context = (PFN_destroy_plugin_context)GetProcAddress(lib->hinstance, "fn_destroy_plugin_context");
    if (lib->destroy_plugin_context == 0) {
        return 1;
    }
    return 0;
}

int32_t unload_plugin_c(PluginCLibrary* lib) { return FreeLibrary(lib->hinstance); }