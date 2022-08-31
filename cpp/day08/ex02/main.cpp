#include "MutantStack.h"
#include "list"

int main()
{
	{
		std::cout << std::endl << "BLOCK 1" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::rev_iterator it = mstack.begin();
		MutantStack<int>::rev_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl << "BLOCK 2" << std::endl;
		std::list<int> mstack;
		mstack.push_front(5);
		mstack.push_front(17);
		std::cout << *mstack.begin() << std::endl;
		mstack.remove(*mstack.begin());
		std::cout << mstack.size() << std::endl;
		mstack.push_front(3);
		mstack.push_front(5);
		mstack.push_front(737);
		mstack.push_front(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	return 0;
}