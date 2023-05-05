#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	(void)argv;
//	if (argc != 2) {
//		std::cout << "Error: could not open file." << std::endl;
//		exit(1);
//	}
	BitcoinExchange biter = BitcoinExchange();
	biter.readData();
	biter.checkInput(argv[1]);
	return 0;
}
