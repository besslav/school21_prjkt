#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid argument" << std::endl;
        return (1);
    }
    Convert convert = Convert(argv[1]);
    convert.printValue();
}
