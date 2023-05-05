//
// Created by Price Skip on 4/12/23.
//

#ifndef EX02_PMERGEME_HPP
#define EX02_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>

class PmergeMe {
private:
	std::vector<int>	_vec;
	std::list<int>		_lst;

public:
	PmergeMe(int ac, char **av);
	void 	showVector(const std::string&	status);

	void 	sortVector(int beg, int end);
	void 	sortVectorWithTimer();
	void	mergeVector(int, int, int);
	void	insertionSortVector(int, int);

	void 	showLst(const std::string&	status);

	void 	sortListWithTimer();
	void	insertionSortList(int p, int q);
	void	mergeList(int p, int q, int r);
	void	sortList(int p, int r);

};


#endif //EX02_PMERGEME_HPP
