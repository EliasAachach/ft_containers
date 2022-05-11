#include "../includes/vector.hpp"
#include "../includes/Iterator_traits.hpp"
#include "../includes/random_access_iterator.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/Utils.hpp"

#include <vector>
#include <list>
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
void	printContent(NS::vector<T>&vector)
{
	std::cout << BLUE3 << "content of vector : " << END << std::endl;
	typename NS::vector<T>::iterator it1;
	for	(it1 = vector.begin(); it1 != vector.end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl;
}

template <typename T>
void	printInfosVector(NS::vector<T>& vector)
{
	std::cout << BLUE3 << "infos of vector : " << END << std::endl;
	std::cout << "capacity : " << vector.capacity() << std::endl;
	std::cout << "size : " << vector.size() << std::endl;
}

void	V_testConstructors(void)
{

	std::cout << BLUE1 << "/*__________________________CONSTRUCTORS__________________________*/" << END << std::endl;

	std::cout << BLUE2 << "DEFAULT CONSTRUCTOR" << END << std::endl;
	NS::vector<int>		default_vector1;

	printContent(default_vector1);
	std::cout << std::endl;

	std::cout << BLUE2 << "FILL CONSTRUCTOR" << END << std::endl;
	std::cout << BLUE3 << "/* empty fill constructor */" << END << std::endl;
	NS::vector<int>		fill_vector1(0);

	printContent(fill_vector1);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* sized fill constructor */" << END << std::endl;
	NS::vector<int>		fill_vector2(6);

	printContent(fill_vector2);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* sized fill constructor with value */" << END << std::endl;
	NS::vector<int>		fill_vector3(6, 4);

	printContent(fill_vector3);
	std::cout << std::endl;

	std::cout << BLUE2 << "RANGE CONSTRUCTOR" << END << std::endl;
	NS::vector<int>		range_iterator(fill_vector3.begin() + 1, fill_vector3.end());

	printContent(range_iterator);
	std::cout << std::endl;
}

void	V_testReserve(void)
{

	std::cout << BLUE1 << "/*__________________________CAPACITY__________________________*/"<< END << std::endl;
	
	NS::vector<int> 		vector(3, 8);


	std::cout << BLUE2 << "BEFORE RESERVE" << END << std::endl;
	printInfosVector(vector);
	vector.reserve(46);


	std::cout << std::endl << BLUE2 << "AFTER RESERVE" << END << std::endl;
	printInfosVector(vector);

	std::cout << std::endl << BLUE2 << "TRY MAX SIZE" << END << std::endl;
	try
	{
		std::cout << BLUE3 << "try max_size vector" << END << std::endl;
		vector.reserve(vector.max_size() + 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


void	V_testElementAccess(void)
{
	std::cout << BLUE1 << "/*________________________ELEMENT ACCESS________________________*/"<< END << std::endl;
	NS::vector<int>		vector(5, 3);

	std::cout << BLUE2 << "BEFORE ELEMENT ACCESS" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;

	std::cout << BLUE3 << "/* operator[] */" << END << std::endl;
	std::cout << "vector[3] is : " << vector[3] << std::endl;

	NS::vector<int>::iterator it1 = vector.insert(vector.begin() + 1, 155);
	printContent(vector);

	std::cout << BLUE3 << "/* function at */" << END << std::endl;
	std::cout << "vector at position 2 is : " << vector.at(1) << std::endl;

	it1 = vector.insert(vector.begin(), 12);
	printContent(vector);

	std::cout << BLUE3 << "/* function front */" << END << std::endl;
	std::cout << "first element of vector : " << vector.front() << std::endl;

	it1 = vector.insert(vector.end(), 369);
	printContent(vector);

	std::cout << BLUE3 << "/* function back */" << END << std::endl;
	std::cout << "last element of vector : " << vector.back() << std::endl;

}

void	V_testAssign(void)
{
	std::cout << BLUE1 << "/*________________________ASSIGN________________________*/"<< END << std::endl;
	NS::vector<int>		vector;

	std::cout << std::endl << BLUE3 << "BEFORE ASSIGN" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);

	std::cout << std::endl << BLUE3 << "AFTER ASSIGN" << END << std::endl;
	vector.assign(6, 100);

	printContent(vector);
	printInfosVector(vector);
}

void	V_testResize(void)
{
	std::cout << BLUE1 << "/*________________________RESIZE________________________*/"<< END << std::endl;
	NS::vector<int>		vector(10, 15);

	std::cout << BLUE2 << "BEFORE RESIZE" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;

	std::cout << BLUE3 << std::endl << "/* resize to less than size */" << END << std::endl;
	vector.resize(5); 

	printContent(vector);
	printInfosVector(vector);

	std::cout << BLUE3 << std::endl << "/* resize to more than size */" << END << std::endl;
	vector.resize(15);

	printContent(vector);
	printInfosVector(vector);

	std::cout << BLUE3 << std::endl << "/* resize to more than size & val specified*/" << END << std::endl;
	vector.resize(15, 5);

	printContent(vector);
	printInfosVector(vector);
}

void	V_testPop_Push_Back(void)
{
	std::cout << BLUE1 << "/*________________________POP & PUSH BACK ________________________*/"<< END << std::endl;
	NS::vector<int>		vector(1, 50);

	std::cout << BLUE2 << "BEFORE PUSH & POP BACK" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;

	std::cout << BLUE2 << "AFTER PUSH BACK" << END << std::endl;
	vector.push_back(60);
	vector.push_back(70);
	vector.push_back(80);
	vector.push_back(90);
	vector.push_back(100);


	printContent(vector);
	printInfosVector(vector);

	std::cout << BLUE2 << "AFTER POP BACK" << END << std::endl;
	vector.pop_back();
	vector.pop_back();
	vector.pop_back();
	vector.pop_back();
	vector.pop_back();

	printContent(vector);
	printInfosVector(vector);
}

void	V_testInsert(void)
{
	std::cout << BLUE1 << "/*__________________________INSERT__________________________*/"<< END << std::endl;
	NS::vector<int>		vector(6, 10);

	std::cout << BLUE2 << "BEFORE INSERT" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;
	
	std::cout << BLUE3 << "/* function insert with 1 value */" << END;
	vector.insert(vector.begin() + 1, 12);

	printContent(vector);
	printInfosVector(vector);

	std::cout << BLUE3 << std::endl << "/* function insert with several values */" << END;
	vector.insert(vector.begin(), 3, 30);

	printContent(vector);
	printInfosVector(vector);
}

void	V_testSwap(void)
{
	std::cout << BLUE1 << "/*__________________________SWAP__________________________*/"<< END << std::endl;
	NS::vector<int> vector (3,100);
	NS::vector<int> new_vector (5,200); 	

	std::cout << BLUE2 << "BEFORE SWAP" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;

	vector.swap(new_vector);

	std::cout << BLUE2 << "AFTER INSERT" << END << std::endl;
	printContent(vector);
	printInfosVector(vector);
	std::cout << std::endl;
}

void	V_testRelationalOperators(void)
{
	std::cout << BLUE1 << "/*__________________________RELATIONAL OPERATORS__________________________*/"<< END << std::endl;
	NS::vector<int>		first_vector (20, 30);
	NS::vector<int>		second_vector(20, 30);
	NS::vector<int>		third_vector(10, 6);
	NS::vector<int>		fourth_vector(50, 3);

	std::cout << "__________FIRST VECTOR" << std::endl;
	printContent(first_vector);
	std::cout << "__________SECOND VECTOR" << std::endl;
	printContent(second_vector);
	std::cout << std::endl;

	std::cout << BLUE2 << " MY OPERATOR== : " << END << (first_vector == second_vector);

	std::cout << BLUE2 << " MY OPERATOR!= : " << END << (first_vector != second_vector);

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (first_vector < second_vector);

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (first_vector < third_vector);

	std::cout << BLUE2 << " MY OPERATOR<  : " << END << (first_vector < fourth_vector);

	std::cout << BLUE2 << " MY OPERATOR<= : " << END << (first_vector <= second_vector);

	std::cout << BLUE2 << " MY OPERATOR<= : " << END << (first_vector <= third_vector);

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (first_vector > second_vector);

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (first_vector > third_vector);

	std::cout << BLUE2 << " MY OPERATOR>  : " << END << (first_vector > fourth_vector);

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (first_vector > second_vector);

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (first_vector > third_vector);

	std::cout << BLUE2 << " MY OPERATOR>= : " << END << (first_vector > fourth_vector);
}

void	V_testReverseIterator(void)
{
	std::cout << BLUE1 << "/*__________________________REVERSE ITERATORS__________________________*/"<< END << std::endl;
	NS::vector<int> vct;
	NS::vector<int>::iterator it = vct.begin();
	NS::vector<int>::iterator cit = vct.begin();

	NS::vector<int>::reverse_iterator rit(it);

	NS::vector<int>::const_reverse_iterator crit(rit);
	NS::vector<int>::const_reverse_iterator crit_(it);
	NS::vector<int>::const_reverse_iterator crit_2(cit);

	NS::vector<int> vector (5);  // 5 default-constructed ints

	NS::vector<int>::reverse_iterator rit1 = vector.rbegin();

	int i=0;
	for (rit1 = vector.rbegin(); rit1 != vector.rend(); ++rit1)
	*rit1 = ++i;

	printContent(vector);

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

int		main(void)
{
	/* ------------------------------------------------------------- */
	/* -------------------------- VECTOR ---------------------------- */	
	/* ------------------------------------------------------------- */
	
	printTitle("vector");

	V_testConstructors();
	std::cout << std::endl;

	V_testResize();
	std::cout << std::endl;
	
	V_testReserve();
	std::cout << std::endl;

	V_testElementAccess();
	std::cout << std::endl;

	V_testPop_Push_Back();
	std::cout << std::endl;

	V_testInsert();
	std::cout << std::endl;

	V_testSwap();
	std::cout << std::endl;

	V_testRelationalOperators();
	std::cout << std::endl;

	V_testReverseIterator();
	std::cout << std::endl;
	
	V_testAssign();
	std::cout << std::endl;

	std::cout << std::endl;

	return (0);
} 
