#ifndef PLUGIN_C_HPP
#define PLUGIN_C_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef LIBRARY_EXPORT
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

enum PluginObjectType {
    obj_type_none,
    obj_type_human,
    obj_type_robot,
    obj_type_count,
};

typedef struct PluginContextS PluginContext;

typedef struct PluginObjectS PluginObject;

#ifdef __cplusplus
}
#endif

#endif  // PLUGIN_C_HPP