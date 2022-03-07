#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#ifdef LIBRARY_EXPORT
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

class LIBRARY_API Plugin {
  public:
    virtual const char* get_name() = 0;
};

#endif  // PLUGIN_HPP