#include <iostream>

class Base {
public:
    virtual ~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate(void) {
    switch ((rand() * rand()) % 3) {
        case 0 : {
            std::cout << "Create A" << std::endl;
            return (new A());
        }
        case 1 : {
            std::cout << "Create B" << std::endl;
            return (new B());
        }
        default : {
            std::cout << "Create C" << std::endl;
            return (new C());
        }
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "It's A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "It's B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "It's C" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "It's A" << std::endl;
    } catch (...) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "It's B" << std::endl;
        } catch (...) {
            std::cout << "It's C" << std::endl;
        }
    }
}

int main() {
    Base *base1 = generate();
    Base *base2 = generate();
    Base *base3 = generate();
    Base *base4 = generate();

    std::cout << std::endl;

    identify(base1);
    identify(base2);
    identify(base3);
    identify(base4);

    std::cout << std::endl;

    identify(*base1);
    identify(*base2);
    identify(*base3);
    identify(*base4);
}
