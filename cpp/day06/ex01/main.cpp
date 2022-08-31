#include <iostream>

struct Data {
    int i;
    char c;
    float f;
};

uintptr_t serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}

int main() {
    Data *data = new Data();
    Data *data2;
    uintptr_t uin;
    data->i = 42;
    data->f = 42.21;
    data->c = '$';

    uin = serialize(data);
    std::cout << "Data 1 - " << data << "; Uintptr - " << uin << std::endl;
    data2 = deserialize(uin);
    std::cout << "Data 1 - " << data << "; Data2 - " << data2 << std::endl;

    std::cout << std::endl;
    std::cout << "i = " << data2->i << "; c = " << data2->c << "; f = " << data2->f << std::endl;
    ++data2->i;
    ++data2->c;
    ++data2->f;
    std::cout << "i = " << data->i << "; c = " << data->c << "; f = " << data->f << std::endl;
}
