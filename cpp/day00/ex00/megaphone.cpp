#include <iostream>

int main(int argc, char **argv)
{
    std::string	str;

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
        str.append(argv[i]);
    for (int i = 0; i < (int)str.length(); ++i)
        str[i] = toupper(str[i]);
    std::cout << str << std::endl;
    return 0;
}
