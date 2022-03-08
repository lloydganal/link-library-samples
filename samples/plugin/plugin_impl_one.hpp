#ifndef PLUGIN_IMPL_ONE_HPP
#define PLUGIN_IMPL_ONE_HPP

#include "plugin.hpp"

class PluginONE : public Plugin {
  public:
    PluginONE();

    ~PluginONE();

    virtual const char *get_name() override;
};

extern "C" LIBRARY_API Plugin *create_plugin();

extern "C" LIBRARY_API void destroy_plugin(Plugin **);

extern "C" LIBRARY_API const char *get_version_major();

extern "C" LIBRARY_API const char *get_version_minor();

extern "C" LIBRARY_API const char *get_version_patch();

#endif  // PLUGIN_IMPL_ONE_HPP