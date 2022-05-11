#include "../includes/pair.hpp"
#include "../includes/rbTree.hpp"
#include "../includes/rbTreeNode.hpp"
#include "../includes/map.hpp"

#include <map>
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

using namespace NS;

#define SIZE 52

template<typename T_MAP>
void	printMap(T_MAP const &my_map)
{
	std::cout << BLUE3 << "content of my_map : " << END << std::endl;
	typename T_MAP::const_iterator it;
	for(it = my_map.begin(); it != my_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size :" << my_map.size() << std::endl;
	std::cout << std::endl;
}


template <typename T1, typename T2>
void	M_printContentPair(NS::pair<T1, T2>& pair)
{
	std::cout << BLUE3 << "content of pair : " << END << std::endl;
	std::cout << "first element is : " << pair.first << std::endl;
	std::cout << "second element is : " << pair.second << std::endl;
	
	std::cout << std::endl;
}

void	M_testPairConstructors(void) 
{
	std::cout << BLUE1 << "/*__________________________Constructors pair __________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Constructors: " << END << std::endl;
	NS::pair < std::string, std::string > pair1;				//default constructor
	NS::pair < std::string, int > pair2("temperature", 25);		//value init
	NS::pair < std::string, int > pair3(pair2);					//copy constuctor


	M_printContentPair(pair1);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(pair2);
	std::cout << "___________________________________" << std::endl;
	M_printContentPair(pair3);

	std::cout << BLUE3 << "Operator= : " << END << std::endl;
	NS::pair <std::string, int> pair4;
	pair4 = pair3;

	M_printContentPair(pair4);

}

void	M_testPairComparaisons(void)
{
	std::cout << BLUE1 << "/*__________________________Comparaisons__________________________*/" << END << std::endl;

	std::cout << BLUE3 << "Operator==: " << END << std::endl;
	NS::pair < int, char> pair1_1(1, 'a');
	NS::pair < int, char> pair1_2(1, 'a');
	NS::pair < int, char > pair2(2, 'b');
	NS::pair < float, char > pair3(4.6, 'c');

	std::cout << "1 - ";
	if (pair1_1 == pair1_2) 
		std::cout << "my pairs are equals";

	std::cout << std::endl << "2 - ";
	if (pair1_1 == pair2) 
		std::cout << "my pairs are equals";

	//NE PEUT PAS COMPILER - comportement normal
	// std::cout << std::endl << "3 - ";
	// if (pair1_1 == pair3) 
	// 	std::cout << "my pairs are equal";
	
	std::cout << std::endl << std::endl;

	std::cout << BLUE3 << "Operator!=: " << END << std::endl;

	std::cout << "4 - ";
	if (pair1_1 != pair2) 
		std::cout << "my pairs are differents";

	std::cout << std::endl;
}

// void	M_testRBTInsertAndDelete(void)
// {

// 	std::cout << BLUE1 << "/*_________________________ INSERTION _________________________*/" << END << std::endl;

// 	ft::RBTree<int, NS::pair<int, std::string> >	rbt1;
// 	ft::RBTree<int, NS::pair<int, int> >			rbt2;


// 	std::cout << BLUE3 << std::endl << "/* increasing insertion with int and string*/" << END << std::endl;
// 	rbt1.insert(NS::make_pair<int, std::string> (1, "un"));
// 	rbt1.insert(NS::make_pair<int, std::string>(2, "deux"));
// 	rbt1.insert(NS::make_pair<int, std::string>(3, "trois"));	
// 	rbt1.insert(NS::make_pair<int, std::string>(4, "quatre"));
	
// 	std::cout << "INSERT - rbt1" << std::endl;
// 	rbt1.printTree();

// 	std::cout << BLUE3 << std::endl << "/* insertion with pair of int */" << END << std::endl;
// 	rbt2.insert(NS::make_pair<int, int>(1, 1));
// 	rbt2.insert(NS::make_pair<int, int>(5, 5));

// 	std::cout << "INSERT - rbt2" << std::endl;
// 	rbt2.printTree();
// 	rbt2.delete_node(NS::make_pair <int, int>(1, 1));
// 	rbt2.delete_node(NS::make_pair <int, int>(5, 5));
// 	std::cout << "check if empty : ";
// 	rbt2.printTree();

// 	std::cout << BLUE3 << std::endl << std::endl << "/* re insertion in the same tree (but empty) */" << END << std::endl;
// 	rbt2.insert(NS::make_pair<int, int>(3, 3));
// 	rbt2.insert(NS::make_pair<int, int>(4, 4));

// 	rbt2.printTree();

// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ DELETION _________________________*/" << END << std::endl;

// 	std::cout << BLUE3 << std::endl << "/* delete node with pair value */" << END << std::endl;
// 	rbt1.delete_node(NS::make_pair <int, std::string> (2, "deux"));

// 	std::cout << "DELETE NODE - rbt1" << std::endl;
// 	rbt1.printTree();

// 	std::cout << BLUE3 << std::endl << "/* delete all node of the tree without using delete_tree */" << END << std::endl;
// 	rbt2.printTree();
// 	rbt2.delete_node(NS::make_pair <int, int> (3, 3));
// 	rbt2.delete_node(NS::make_pair <int, int> (4, 4));
// 	std::cout << "check if empty :";
// 	rbt2.printTree();
// }

// void	M_testRBTFixInsertionAndFixDeletion() 
// {
// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ FIX INSERTION _________________________*/" << END << std::endl;

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with croissant value (int) */" << END << std::endl;
// 	ft::RBTree<int, NS::pair<int, int> >	rbt1;
// 	int		int_array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
// 	int		int_array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

// 	for (int i = 0; i < 20; i++) {
// 		rbt1.insert(NS::make_pair(int_array1[i], int_array2[i]));
// 	}
// 	rbt1.printTree();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with random value (int) */" << END << std::endl;
// 	ft::RBTree<int, NS::pair<int, int> >	rbt2;

// 	int	int_array3[30];
// 	int	int_array4[30];
// 	srand(time(NULL));
// 	for (int i=0 ; i < 30; i++) {
// 		int_array3[i] = rand() % 100;
// 		int_array4[i] = rand() % 100;
// 	}

// 	for (int i = 0; i < 29; i++) {
// 		rbt2.insert(NS::make_pair(int_array3[i], int_array4[i]));
// 	}
// 	rbt2.printTree();

// 	std::cout << std::endl << std::endl << BLUE3 << "/* test with random value (int & std::string) */" << END << std::endl;
// 	ft::RBTree<int, NS::pair<int, std::string> >	rbt3;

// 	std::string	std_array1[5] = {"bonjour", "bonsoir", "salut", "hola", "hello"};

// 	for (int i = 0; i < 5; i++)
// 		rbt3.insert(NS::make_pair(int_array3[i], std_array1[i]));
	
// 	rbt3.printTree();

// 	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ FIX DELETION _________________________*/" << END << std::endl;

// 	rbt1.delete_node(NS::make_pair(7, 7));
// 	rbt1.printTree();
// }

// void	M_testRBTiterators(void)
// {
// 	ft::RBTree<int, NS::pair<int, int> >	rbt;

// 	for (int i = 0; i < 10; i++)
// 		rbt.insert(NS::make_pair(i, i));
	
// 	std::cout << "RBTree : " << std::endl;
// 	rbt.printTree();

// 	ft::RBTree<int, NS::pair<int, int> > copy_rbt(rbt);

// 	std::cout << "RBTree copy : " << std::endl;
// 	copy_rbt.printTree();
// }

void	M_testConstructors(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ CONSTRUCTORS _________________________*/" << END << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* default constructor */" << END << std::endl;
	NS::map<int, int> 	map;


	std::cout << std::endl << std::endl << BLUE3 << "/* range constructor */" << END << std::endl;
	int		int_array[5] = {1, 2, 3, 4, 5};

  	for (int i = 0; i < 5; i++) {
		map.insert(NS::make_pair(int_array[i], int_array[i]));
	}


	std::cout << "My MAP 1 : " << std::endl;
	printMap(map);
  	NS::map<int,int> map2 (map.begin(),map.end());

	std::cout << "My MAP 2 : " << std::endl;
	printMap(map2);


	std::cout << std::endl << std::endl << BLUE3 << "/* copy constructor */" << END << std::endl;
	map2.insert(NS::make_pair<int, int>(6, 6));

	std::cout << "My MAP 2 + 1 node: " << std::endl;
	printMap(map2);

	NS::map<int, int> map3(map2);
	std::cout << "My MAP 3 : " << std::endl;
	printMap(map3); 


	std::cout << std::endl << std::endl << BLUE3 << "/* assign operator */" << END << std::endl;
	map3.insert(NS::make_pair<int, int> (7, 7));

	std::cout << "My MAP 3 + 1 node : " << std::endl;
	printMap(map3); 
	NS::map<int, int> map4;
	map4 = map3;

	std::cout << "My MAP 4 : " << std::endl;
	printMap(map4); 
}


void	M_testElementAccess(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ ELEMENT ACCESS _________________________*/" << END << std::endl;

	NS::map<char, int> map;

	char	char_array[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int		int_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for(int i = 0; i < 10; i++)
		map.insert(NS::make_pair<char, int> (char_array[i], int_array[i]));
	
	printMap(map);

	std::cout << std::endl << std::endl << BLUE3 << "/* operator[] - print element */" << END << std::endl;

	std::cout << "map['a'] is " << map['a'] << std::endl;
	std::cout << "map['b'] is " << map['b'] << std::endl;
	std::cout << "map['c'] is " << map['c'] << std::endl;
	std::cout << "map['d'] is " << map['d'] << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator[] - insert element if it doesn't exist*/" << END << std::endl;

	std::cout << "map['k'] is " << map['k'] << std::endl << std::endl;

	map['l'] = 12;

	printMap(map);
}

void	M_testCapacity(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ CAPACITY _________________________*/" << END << std::endl;

	NS::map<std::string, std::string>	map;
	NS::map<int, int> 					empty_map;

	std::string		string_array1[5] = {"bonjour", "hello", "hola", "hallo", "ciao"};
	std::string		string_array2[5] = {"FR", "EN", "ES", "GE", "IT"};

	for (int i = 0; i < 5; i++)
		map.insert(NS::make_pair(string_array1[i], string_array2[i]));

	printMap(map);

	std::cout << std::endl << std::endl << BLUE3 << "/* check if empty */" << END << std::endl;
	
	if (map.empty() == 0)
		std::cout << "map not empty" << std::endl;
	else 
		std::cout << "map empty" << std::endl;

	if (empty_map.empty() == 0)
		std::cout << "map not empty" << std::endl;
	else 
		std::cout << "map empty" << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* check size */" << END << std::endl;

	std::cout << "size of map : " << map.size() << std::endl;
	std::cout << "size of empty_map : " << empty_map.size() << std::endl;
}

void	M_testInsertAndErase(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ INSERT _________________________*/" << END << std::endl;

	NS::map<int, int> map;
	std::cout << std::endl << std::endl << BLUE3 << "/* insert with value */" << END << std::endl;

	map.insert(NS::make_pair<int, int>(1, 1));
	map.insert(NS::make_pair<int, int>(2, 2));
	map.insert(NS::make_pair<int, int>(3, 3));
	map.insert(NS::make_pair<int, int>(4, 4));
	map.insert(NS::make_pair<int, int>(5, 5));

	printMap(map);

	std::cout << std::endl << std::endl << BLUE3 << "/* insert range */" << END << std::endl;
	NS::map<int, int> map2(map.begin(), map.end());
	printMap(map2);

	std::cout << std::endl << std::endl << BLUE3 << "/* insert with value & position*/" << END << std::endl;
	NS::map<int, int> map3;
	map3.insert (map.begin(), NS::make_pair<int,int>(6, 6)); 
	map3.insert (map.begin(), NS::make_pair<int,int>(7, 7)); 
	printMap(map3);


	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ ERASE _________________________*/" << END << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* erase with position */" << END << std::endl;

	std::cout << "first print : " << std::endl;
	printMap(map);

	std::cout << std::endl << "erase of map.begin() " << std::endl;
	map.erase(map.begin());

	std::cout << std::endl << "second print : " << std::endl;
	printMap(map);

	std::cout << std::endl << std::endl << BLUE3 << "/* erase range */" << END << std::endl;

	NS::map<int, int>::iterator it = map2.begin();

	it++;
	it++;
	std::cout << "first print : " << std::endl;
	printMap(map2);

	std::cout << std::endl << "erase of range between map.begin() & mapbegin()++ " << std::endl;
	map2.erase(map2.begin(), it);

	std::cout << std::endl << "second print : " << std::endl;
	printMap(map2);

	std::cout << std::endl << std::endl << BLUE3 << "/* erase with key */" << END << std::endl;

	std::cout << "first print : " << std::endl;
	printMap(map3);

	std::cout << std::endl << "erase of 6" << std::endl;
	map3.erase(6);

	std::cout << std::endl << "second print : " << std::endl;
	printMap(map3);

}

void	M_testSwap(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ SWAP _________________________*/" << END << std::endl;

	NS::map<char, char> map1;
	NS::map<char, char> map2;

	char	char_array1_1[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
	char	char_array1_2[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
	char	char_array2_1[] = {'s', 'a', 'l', 'u', 't', 'y', 'o'};
	char	char_array2_2[] = {'s', 'a', 'l', 'u', 't', 'y', 'o'};

	for(int i = 0; i < 7; i++) {
		map1.insert(NS::make_pair(char_array1_1[i], char_array1_2[i]));
		map2.insert(NS::make_pair(char_array2_1[i], char_array2_2[i]));
	}


    std::cout << "BEFORE SWAP" << std::endl;
	std::cout << " map1 :" << std::endl;
	printMap(map1);
	std::cout << std::endl << " map2 :" << std::endl;
	printMap(map2);

	map1.swap(map2);

    std::cout << "AFTER SWAP" << std::endl;
	std::cout << std::endl << " map1 :" << std::endl;
	printMap(map1);

	std::cout << std::endl << " map2 :" << std::endl;
	printMap(map2);

}

void	M_testRelationalOperators(void)
{
	std::cout << BLUE1 << std::endl << std::endl << "/*_________________________ RELATIONAL OPERATORS _________________________*/" << END << std::endl;

	NS::map<char, int> my_map1;
	NS::map<char, int> my_map2;
	NS::map<char, int> my_map3;


	my_map1['a'] = 2; my_map1['b'] = 3; my_map1['c'] = 4; my_map1['d'] = 5;
	my_map2['a'] = 2; my_map2['b'] = 3; my_map2['c'] = 4; my_map2['d'] = 5;
	my_map3['a'] = 2;  my_map3['b'] = 3; my_map3['c'] = 4; my_map3['e'] = 6;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator== */" << END << std::endl;
	std::cout << "(my_map1 == my_map2) = " << (my_map1 == my_map2) << std::endl;
	std::cout << "(my_map1 == my_map3) = " << (my_map1 == my_map3) << std::endl;
	
	std::cout << std::endl << std::endl << BLUE3 << "/* operator!= */" << END << std::endl;
	std::cout << "(my_map1 != my_map2) = " << (my_map1 != my_map2) << std::endl;
	std::cout << "(my_map1 != my_map3) = " << (my_map1 != my_map3) << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator< */" << END << std::endl;
	std::cout << "(my_map1 < my_map2) = " << (my_map1 < my_map2) << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator<= */" << END << std::endl;
	std::cout << "(my_map1 <= my_map2) = " << (my_map1 <= my_map2) << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator> */" << END << std::endl;
	std::cout << "(my_map1 > my_map2) = " << (my_map1 > my_map2) << std::endl;

	std::cout << std::endl << std::endl << BLUE3 << "/* operator>= */" << END << std::endl;
	std::cout << "(my_map1 >= my_map2)  = " << (my_map1 >= my_map2) << std::endl;
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

	printTitle("map");

	/* ------------------------------------------------------------- */
	/* --------------------------- PAIR ---------------------------- */	
	/* ------------------------------------------------------------- */

	/*____________________________ ft::pair ____________________________ */

	M_testPairConstructors();
	std::cout << std::endl;

	M_testPairComparaisons();
	std::cout << std::endl;

	// /* ------------------------------------------------------------- */
	// /* --------------------------- RBTree -------------------------- */	
	// /* ------------------------------------------------------------- */

	// M_testRBTInsertAndDelete();
	// std::cout << std::endl;

	// M_testRBTFixInsertionAndFixDeletion();
	// std::cout << std::endl;

	// M_testRBTiterators();
	// std::cout << std::endl;

	// /* ------------------------------------------------------------- */
	// /* --------------------------- MAP ----------------------------- */	
	// /* ------------------------------------------------------------- */

	M_testConstructors();
	std::cout << std::endl;

	M_testElementAccess();
	std::cout << std::endl;

	M_testCapacity();
	std::cout << std::endl;

	M_testInsertAndErase();
	std::cout << std::endl;

	M_testSwap();
	std::cout << std::endl;

	M_testRelationalOperators();
	std::cout << std::endl;

	std::cout << std::endl;

	return (0);
}