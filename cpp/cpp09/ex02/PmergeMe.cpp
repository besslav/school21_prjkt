//
// Created by Price Skip on 4/12/23.
//

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j] != '\0'; j++) {
			if (av[i][j] < 48 || av[i][j] > 57) {
				std::cout << "Error: bad input." << std::endl;
				exit(1);
			}
		}
		int num = std::atoi(av[i]);
		if (num <= 0) {
			std::cout << "Error: Input sequence must only contain positive integers." << std::endl;
			exit(1);
		}
		_vec.push_back(num);
		_lst.push_back(num);
	}
}

void 	PmergeMe::showLst(const std::string&	status) {
	int count = 0;
	std::cout << status << ": ";
	for (std::list<int>::const_iterator it = _lst.begin(); it != _lst.end(); ++it) {
		std::cout << *it << " ";
		count +=1;
		if (count == 5) {
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

void 	PmergeMe::showVector(const std::string&	status) {
	int count = 0;
	std::cout << status << ": ";
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << " ";
		count +=1;
		if (count == 5) {
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

void 	PmergeMe::insertionSortVector(int p, int q) {
	for (int i = p + 1; i <= q; i++) {
		if (_vec[i] < _vec[i - 1]) {
			int temp = _vec[i];
			for (int j = p; j <= i; j++) {
				if (_vec[i] < _vec[j]){
					for (int k = i; k > j; k--) {
						_vec[k] = _vec[k - 1];
					}
					_vec[j] = temp;
					break;
				}
			}
		}
	}
}

void 	PmergeMe::mergeVector(int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> LA(n1), RA(n2);
	for (int i = 0; i < n1; i++) {
		LA[i] = _vec[p + i];
	}
	for (int i = 0; i < n2; i++) {
		RA[i] = _vec[q + 1 + i];
	}
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2) {
			_vec[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			_vec[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			_vec[i] = LA[LIDX];
			LIDX++;
		} else {
			_vec[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void 	PmergeMe::sortVector(int p, int r) {
	if (r - p > 5) {
		int q = (p + r) / 2;
		sortVector(q + 1, r);
		sortVector(p, q);
		mergeVector(p, q, r);
	} else {
		insertionSortVector(p, r);
	}
}


void 	PmergeMe::sortVectorWithTimer() {
	int n = _vec.size();
	std::clock_t start_vec = std::clock();
	sortVector(0, n-1);
	std::clock_t end_vec = std::clock();
	double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
	showVector("After");
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with vector merge-insert sort: " << elapsed_vec
			  << " us" << std::endl;
}

void 	PmergeMe::sortListWithTimer(){
	int n = _lst.size();
	std::clock_t start_lst = std::clock();
	sortList(0, n - 1);
	std::clock_t end_lst = std::clock();
	double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _lst.size()
		  << " elements with list merge-insert sort: " << elapsed_lst
		  << " us" << std::endl;
}


void PmergeMe::insertionSortList(int p, int q) {
	std::list<int>::iterator iti, itj;
	for (int i = p; i < q; i++) {
		iti = _lst.begin();
		advance(iti, i + 1);
		int tempVal = *iti;
		int j = i + 1;
		itj = _lst.begin();
		advance(itj, i);
		while (j > p && *itj > tempVal) {j--; itj--; }
		_lst.erase(iti);
		//_lst.emplace(++itj, tempVal);
		_lst.insert(++itj, 1, tempVal);
		iti++;
	}
}

void PmergeMe::mergeList(int p, int q, int r) {
	std::list<int>::iterator iti, itj;
	for (int i = q; i < r; i++) {
		iti = _lst.begin();
		advance(iti, i + 1);
		int tempVal = *iti;
		int j = i + 1;
		itj = _lst.begin();
		advance(itj, i);
		while (j > p && *itj > tempVal) {j--; itj--; }
		_lst.erase(iti);
		//_lst.emplace(++itj, tempVal);
		_lst.insert(++itj, 1, tempVal);
		iti++;
	}
}

void PmergeMe::sortList(int p, int r) {
	if (r - p > 5) {
		int q = (p + r) / 2;
		sortList( p, q);
		sortList( q + 1, r);
		mergeList(p, q, r);
	} else {
		insertionSortList( p, r);
	}
}



