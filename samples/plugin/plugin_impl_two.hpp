#ifndef PLUGIN_IMPL_TWO_HPP
#define PLUGIN_IMPL_TWO_HPP

#include "plugin.hpp"

class PluginTWO : public Plugin {
  public:
    PluginTWO();

    ~PluginTWO();

    virtual const char *get_name() override;
};

extern "C" LIBRARY_API Plugin *create_plugin();

extern "C" LIBRARY_API void destroy_plugin(Plugin **);

#endif  // PLUGIN_IMPL_TWO_HPP