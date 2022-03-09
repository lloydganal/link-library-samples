#include "plugin_impl_one.hpp"

PluginONE::PluginONE() {}

PluginONE::~PluginONE() {}

const char* PluginONE::get_name() { return "Plugin ONE"; }

Plugin* create_plugin() { return new PluginONE(); }

void destroy_plugin(Plugin** plugin) {
    delete *plugin;
    *plugin = nullptr;
}