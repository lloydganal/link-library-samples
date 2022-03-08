#include "plugin_impl_one.hpp"

PluginONE::PluginONE() {}

PluginONE::~PluginONE() {}

const char* PluginONE::get_name() { return "Plugin ONE"; }

Plugin* create_plugin() { return new PluginONE(); }

void destroy_plugin(Plugin** plugin) {
    delete *plugin;
    *plugin = nullptr;
}

const char * get_version_major() { return "0"; }

const char * get_version_minor() { return "1"; }

const char * get_version_patch() { return "0"; }