#include <stdio.h>
#pragma warning(suppress : 5105)
#include "plugin_c_loader.h"

int main(int argc, char const *argv[]) {
    PluginCLibrary plugin_one;
    load_plugin_c("plugin_c_one.dll", &plugin_one);

    PluginContext *ctx = plugin_one.create_plugin_context();
    plugin_one.destroy_plugin_context(&ctx);

    unload_plugin_c(&plugin_one);
    return 0;
}
