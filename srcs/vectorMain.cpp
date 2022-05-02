#include "../includes/stack.hpp"

#include <stack>
#include <vector>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"


template <typename T>
void	printInfosStack(ft::stack<T, ft::vector<T> >& my_stack, std::stack<T, std::vector<T> > std_stack)
{
	std::cout << BLUE3 << "infos of my stack : " << END << std::endl;
	std::cout << "size : " << my_stack.size() << std::endl;

	std::cout << BLUE3 << "infos of std stack : " << END << std::endl;
	std::cout << "size : " << std_stack.size() << std::endl;
}

void	S_testConstructors(void)
{
	std::cout << BLUE1 << "/*__________________________CONSTRUCTORS__________________________*/" << END << std::endl;

	ft::stack< int, ft::vector<int> >	my_stack1;
	ft::vector<int>						my_vector(3, 5);
	ft::stack<int, ft::vector<int >	>	my_stack2(my_vector);

	std::stack< int, std::vector<int> >		std_stack1;
	std::vector<int>						std_vector(3, 5);
	std::stack<int, std::vector<int >	>	std_stack2(std_vector);

	printInfosStack(my_stack2, std_stack2);

	std::cout << std::endl << BLUE1 << "/*________________________FUNCTION EMPTY______________________*/" << END << std::endl;

	std::cout << BLUE3 << "infos of my stack : " << END << std::endl;
	if (my_stack1.empty())
		std::cout << "my_stack1 is empty" << std::endl;
	else 
		std::cout << "my_stack1 is filled" << std::endl;

	std::cout << BLUE3 << "infos of std stack : " << END << std::endl;
	if (std_stack1.empty())
		std::cout << "std_stack1 is empty" << std::endl << std::endl;
	else 
		std::cout << "std_stack1 is filled" << std::endl << std::endl;

	std::cout << BLUE3 << "infos of my stack : " << END << std::endl;
	if (my_stack2.empty())
		std::cout << "my_stack2 is empty" << std::endl;
	else 
		std::cout << "my_stack2 is filled" << std::endl;

	std::cout << BLUE3 << "infos of std stack : " << END << std::endl;
	if (std_stack2.empty())
		std::cout << "std_stack2 is empty" << std::endl << std::endl;
	else 
		std::cout << "std_stack2 is filled" << std::endl << std::endl;
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

	ft::stack<int, ft::vector<int> > my_stack;
	std::stack<int, ft::vector<int> > std_stack;

	for(int i = 0; i < 10; i++) {
		my_stack.push(i);
		std_stack.push(i);
	}

	std::cout << BLUE3 << "the top of my_stack is " << std::endl << END << my_stack.top() << std::endl;
	std::cout << BLUE3 << "the top of std_stack is " << std::endl << END << std_stack.top() << std::endl << std::endl;

	std::cout << BLUE3 << "Popping out elements..." << END;
	while (!my_stack.empty()) {
		std::cout << ' ' << my_stack.top();
		my_stack.pop();
	}
	std::cout << std::endl;

	std::cout << BLUE3 << "Popping out elements..." << END;
	while (!std_stack.empty()) {
		std::cout << ' ' << std_stack.top();
		std_stack.pop();
	}
	std::cout << std::endl;
}

void	S_testRelationalOperators(void)
{
	std::cout << std::endl << BLUE1 << "/*________________________RELATIONAL OPERATORS_____________________*/" << END << std::endl;

	ft::vector<int>	my_vector1(3, 9);
	ft::stack<int, ft::vector<int> > my_stack1(my_vector1);

	ft::vector<int>	my_vector2(3, 9);
	ft::stack<int, ft::vector<int> > my_stack2(my_vector2);

	std::vector<int>	std_vector1(3, 9);
	std::stack<int, std::vector<int> > std_stack1(std_vector1);

	std::vector<int>	std_vector2(3, 9);
	std::stack<int, std::vector<int> > std_stack2(std_vector2);


	std::cout << BLUE2 << "_____EQUALITY" << END << std::endl;
	if (my_stack1 == my_stack2)
		std::cout << "my_stack1 is the same than my_stack2" << std::endl;
	if (std_stack1 == std_stack2)
		std::cout << "std_stack1 is the same than std_stack2" << std::endl << std::endl;

	
	std::cout << BLUE2 << "_____DIFFERENCE" << END << std::endl;
	my_stack1.push(15);
	std_stack1.push(15);

	if (my_stack1 != my_stack2)
		std::cout << "my_stack1 is different than my_stack2" << std::endl;
	if (std_stack1 != std_stack2)
		std::cout << "std_stack1 is different than std_stack2" << std::endl << std::endl;


	std::cout << BLUE2 << "_____SMALLER" << END << std::endl;
	my_stack1.pop();
	std_stack1.pop();
	my_stack1.pop();
	std_stack1.pop();

	if (my_stack1 < my_stack2)
		std::cout << "my_stack1 is smaller than my_stack2" << std::endl;
	if (std_stack1 < std_stack2)
		std::cout << "std_stack1 is smaller than std_stack2" << std::endl << std::endl;


	std::cout << BLUE2 << "_____BIGGER" << END << std::endl;

	if (my_stack2 > my_stack1)
		std::cout << "my_stack2 is bigger than my_stack1" << std::endl;
	if (std_stack2 > std_stack1)
		std::cout << "std_stack2 is bigger than std_stack1" << std::endl << std::endl;


	std::cout << BLUE2 << "_____SMALLER OR EQUAL" << END << std::endl;

	my_stack1.push(3);
	std_stack1.push(3);

	if (my_stack1 < my_stack2)
		std::cout << "my_stack1 is smaller or equal than my_stack2" << std::endl;
	if (std_stack1 < std_stack2)
		std::cout << "std_stack1 is smaller or equal than std_stack2" << std::endl << std::endl;


	std::cout << BLUE2 << "_____BIGGER OR EQUAL" << END << std::endl;

	my_stack1.push(15);
	my_stack1.push(54);
	std_stack1.push(15);
	std_stack1.push(54);
	if (my_stack2 > my_stack1)
		std::cout << "my_stack2 is bigger or equal than my_stack1" << std::endl;
	if (std_stack2 > std_stack1)
		std::cout << "std_stack2 is bigger or equal than std_stack1" << std::endl << std::endl;
}

int	main(void)
{

	/* ------------------------------------------------------------- */
	/* -------------------------- STACK ---------------------------- */	
	/* ------------------------------------------------------------- */

	S_testConstructors();
	std::cout << std::endl;

	S_testTop();
	std::cout << std::endl;

	S_testPush_Pop();
	std::cout << std::endl;

	S_testRelationalOperators();
	std::cout << std::endl;
}