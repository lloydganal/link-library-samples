#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#ifdef LIBRARY_EXPORT
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

class Plugin {
  public:
    virtual const char *get_name() = 0;
};

typedef Plugin *(*fp_create_plugin)();
typedef void (*fp_destroy_plugin)(Plugin **);
typedef const char *(*fp_get_version_major)();
typedef const char *(*fp_get_version_minor)();
typedef const char *(*fp_get_version_patch)();

#endif  // PLUGIN_HPP