#ifndef SINGLETON_HPP
#define SINGLETON_HPP

class Singleton {
  public:
    ~Singleton();

    Singleton* get_instance();

    void test();

  private:
    Singleton();

    Singleton* m_instance{nullptr};
};

#endif  // SINGLETON_HPP