#include "../includes/map.hpp"
#include "../includes/containers_test/srcs/map/common.hpp"
#include <list>

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	mp.printMap();

	// TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	// for (int i = 0; it != ite; ++it)
	// 	it->second = ++i * 5;

	// it = mp.begin(); ite = --(--mp.end());
	// TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	// for (int i = 0; it != ite; ++it)
	// 	it->second = ++i * 7;

	// std::cout << "\t-- PART ONE --" << std::endl;
	// printSize(mp);
	// printSize(mp_range);
	// printSize(mp_copy);

	// mp = mp_copy;
	// mp_copy = mp_range;
	// mp_range.clear();

	// std::cout << "\t-- PART TWO --" << std::endl;
	// printSize(mp);
	// printSize(mp_range);
	// printSize(mp_copy);
	return (0);
}