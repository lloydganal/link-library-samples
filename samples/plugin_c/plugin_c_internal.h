#ifndef PLUGIN_C_INTERNAL_HPP
#define PLUGIN_C_INTERNAL_HPP

#include "plugin_c.h"

struct PluginContextS {
    PluginObject* objects;
};

struct PluginObjectS {
    int32_t type;
    const char * name;
    PluginObject* next;
};

LIBRARY_API PluginContext * fn_create_plugin_context();

LIBRARY_API void fn_destroy_plugin_context(PluginContext ** ctx);


#endif  // PLUGIN_C_INTERNAL_HPP