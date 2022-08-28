#include "singleton.hpp"

Singleton::Singleton() {}

Singleton::~Singleton() {}

Singleton* Singleton::get_instance() {
    if (!m_instance) {
        m_instance = new Singleton();
    }
    return m_instance;
}

void Singleton::test() {}