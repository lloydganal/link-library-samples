#ifndef PLUGIN_C_LOADER_H
#define PLUGIN_C_LOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

#include "plugin_c.h"

typedef PluginContext* (*PFN_create_plugin_context)();
typedef void (*PFN_destroy_plugin_context)(PluginContext** ctx);

typedef struct PluginCLibraryS {
    HINSTANCE hinstance;
    PFN_create_plugin_context create_plugin_context;
    PFN_destroy_plugin_context destroy_plugin_context;
} PluginCLibrary;

int32_t load_plugin_c(const char* path, PluginCLibrary* lib);

int32_t unload_plugin_c(PluginCLibrary* lib);

#ifdef __cplusplus
}
#endif

#endif  // PLUGIN_C_LOADER_H