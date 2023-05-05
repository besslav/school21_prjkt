#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided." << std::endl;
		return EXIT_FAILURE;
	}

	PmergeMe sorter = PmergeMe(argc, argv);
	sorter.showVector("Before");
	sorter.sortVectorWithTimer();


	sorter.sortListWithTimer();



}
