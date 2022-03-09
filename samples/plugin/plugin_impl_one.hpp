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

#endif  // PLUGIN_IMPL_ONE_HPP