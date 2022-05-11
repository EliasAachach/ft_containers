#include "../includes/stack.hpp"
#include "../includes/vector.hpp"
#include "../includes/Iterator_traits.hpp"
#include "../includes/random_access_iterator.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/Utils.hpp"

#include <stack>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>

# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"

#ifndef NS
# define NS	ft
#endif

using namespace NS;

#define SIZE 52

template <typename T>
void	printInfosStack(NS::stack<T, NS::vector<T> >& stack)
{
	std::cout << BLUE3 << "infos of stack : " << END << std::endl;
	std::cout << "size : " << stack.size() << std::endl;
}

void	S_testConstructors(void)
{
	std::cout << BLUE1 << "/*__________________________CONSTRUCTORS__________________________*/" << END << std::endl;

	NS::stack< int, NS::vector<int> >	stack1;
	NS::vector<int>						vector(3, 5);
	NS::stack<int, NS::vector<int >	>	stack2(vector);

	printInfosStack(stack2);

	std::cout << std::endl << BLUE1 << "/*________________________FUNCTION EMPTY______________________*/" << END << std::endl;

	std::cout << BLUE3 << "infos of stack : " << END << std::endl;
	if (stack1.empty())
		std::cout << "stack1 is empty" << std::endl;
	else 
		std::cout << "stack1 is filled" << std::endl;

	std::cout << BLUE3 << "infos of stack : " << END << std::endl;
	if (stack2.empty())
		std::cout << "stack2 is empty" << std::endl;
	else 
		std::cout << "stack2 is filled" << std::endl;

}

void	S_testTop(void)
{
	std::cout << std::endl << BLUE1 << "/*________________________FUNCTION TOP______________________*/" << END << std::endl;

	ft::vector<int> my_vector(3, 5);
	ft::stack < int, ft::vector<int> > my_stack(my_vector);

	std::cout << BLUE3 << "the top of my_stack is " << std::endl << END << my_stack.top() << std::endl;

	std::vector<int> std_vector(3, 5);
	std::stack < int, std::vector<int> > std_stack(std_vector);

	std::cout << BLUE3 << "the top of std_stack is " << std::endl << END << std_stack.top() << std::endl;
}

void	S_testPush_Pop(void)
{
	std::cout << std::endl << BLUE1 << "/*________________________FUNCTION PUSH_____________________*/" << END << std::endl;

	NS::stack<int, NS::vector<int> > stack;

	for(int i = 0; i < 10; i++) {
		stack.push(i);
	}

	std::cout << BLUE3 << "the top of stack is " << std::endl << END << stack.top() << std::endl;

	std::cout << BLUE3 << "Popping out elements..." << END;
	while (!stack.empty()) {
		std::cout << ' ' << stack.top();
		stack.pop();
	}
	std::cout << std::endl;
}

void	S_testRelationalOperators(void)
{
	std::cout << std::endl << BLUE1 << "/*________________________RELATIONAL OPERATORS_____________________*/" << END << std::endl;

	NS::vector<int>	vector1(3, 9);
	NS::stack<int, NS::vector<int> > stack1(vector1);

	NS::vector<int>	vector2(3, 9);
	NS::stack<int, NS::vector<int> > stack2(vector2);

	std::cout << BLUE2 << "_____EQUALITY" << END << std::endl;
	if (stack1 == stack2)
		std::cout << "stack1 is the same than stack2" << std::endl;

	
	std::cout << BLUE2 << "_____DIFFERENCE" << END << std::endl;
	stack1.push(15);
	if (stack1 != stack2)
		std::cout << "stack1 is different than stack2" << std::endl;


	std::cout << BLUE2 << "_____SMALLER" << END << std::endl;
	stack1.pop();
	stack1.pop();
	if (stack1 < stack2)
		std::cout << "stack1 is smaller than stack2" << std::endl;


	std::cout << BLUE2 << "_____BIGGER" << END << std::endl;
	if (stack2 > stack1)
		std::cout << "stack2 is bigger than stack1" << std::endl;


	std::cout << BLUE2 << "_____SMALLER OR EQUAL" << END << std::endl;
	stack1.push(3);
	if (stack1 < stack2)
		std::cout << "stack1 is smaller or equal than stack2" << std::endl;


	std::cout << BLUE2 << "_____BIGGER OR EQUAL" << END << std::endl;
	stack1.push(15);
	stack1.push(54);
	if (stack2 > stack1)
		std::cout << "stack2 is bigger or equal than stack1" << std::endl;
}


static void	printTitle(std::string title)
{
	static int		first;
	std::string		toPrint;
	unsigned int	size = (SIZE > 10 ? SIZE : 10);
	char			c = '=';
	unsigned int	n;

	if (first > 0)
		std::cout << std::endl;
	else
		first++;

	toPrint = " " + title + " ";
	for (int i = 0; toPrint[i]; i++)
		toPrint[i] = toupper(toPrint[i]);
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << PURPLE << std::setfill(c) << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n - n / 2);
	std::cout << std::setfill(c) << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill(c) << std::setw(size) << "" << END << std::endl << std::endl;
}

int	main(void)
{
	/* ------------------------------------------------------------- */
	/* -------------------------- STACK ---------------------------- */	
	/* ------------------------------------------------------------- */

	printTitle("stack");

	S_testConstructors();
	std::cout << std::endl;

	S_testTop();
	std::cout << std::endl;

	S_testPush_Pop();
	std::cout << std::endl;

	S_testRelationalOperators();
	std::cout << std::endl;

	std::cout << std::endl;

	return (0);
}