#include "plugin_impl_two.hpp"

PluginTWO::PluginTWO() {}

PluginTWO::~PluginTWO() {}

const char* PluginTWO::get_name() { return "Plugin TWO"; }

Plugin* create_plugin() { return new PluginTWO(); }

void destroy_plugin(Plugin** plugin) {
    delete *plugin;
    *plugin = nullptr;
}

const char * get_version_major() { return "0"; }

const char * get_version_minor() { return "1"; }

const char * get_version_patch() { return "0"; }