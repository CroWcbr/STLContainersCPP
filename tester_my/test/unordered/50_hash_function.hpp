#pragma once

#include "../_define.hpp"
#include "../_utils.hpp"

template<class FT, class STD>
bool test_all()
{
#if defined(UNORDERED_SET)
	typedef ft::unordered_set<int, std::hash<int> >	FT2;
	typedef std::unordered_set<int, std::hash<int> >	STD2;
#elif defined(UNORDERED_MULTISET)
	typedef ft::unordered_multiset<int, std::hash<int> >	FT2;
	typedef std::unordered_multiset<int, std::hash<int> >	STD2;
#elif defined(UNORDERED_MAP)
	typedef ft::unordered_map<int, int, std::hash<int> >	FT2;
	typedef std::unordered_map<int, int, std::hash<int> >	STD2;
#elif defined(UNORDERED_MULTIMAP)
	typedef ft::unordered_multimap<int, int, std::hash<int> >	FT2;
	typedef std::unordered_multimap<int, int, std::hash<int> >	STD2;
#endif

	FT2 ft;
	STD2 std;
	for (int i = 0; i < T_COUNT; ++i)
	{
		int v = rand();
		if (std.hash_function()(v) != ft.hash_function()(v))
		{
			return false;
		}
	}
	return true;
}

template<class FT, class STD>
void	test_time(bool leaks, time_t& start_ft, time_t& start_std, time_t& end_ft, time_t& end_std)
{
#if defined(UNORDERED_SET)
	typedef ft::unordered_set<int, ft::hash_compare<int>, std::greater<int> >	FT2;
	typedef std::unordered_set<int, std::hash<int>, std::greater<int> >	STD2;
#elif defined(UNORDERED_MULTISET)
	typedef ft::unordered_multiset<int, ft::hash_compare<int>, std::greater<int> >	FT2;
	typedef std::unordered_multiset<int, std::hash<int>, std::greater<int> >	STD2;
#elif defined(UNORDERED_MAP)
	typedef ft::unordered_map<int, int, ft::hash_compare<int>, std::greater<int> >	FT2;
	typedef std::unordered_map<int, int, std::hash<int>, std::greater<int> >	STD2;
#elif defined(UNORDERED_MULTIMAP)
	typedef ft::unordered_multimap<int, int, ft::hash_compare<int>, std::greater<int> >	FT2;
	typedef std::unordered_multimap<int, int, std::hash<int>, std::greater<int> >	STD2;
#endif

	FT2 ft;
	STD2 std; 
	int v[T_COUNT];
	fill_array_random(v, T_COUNT, 0, RAND_MAX);

	if (!leaks)
	{
		start_std = timer();
		for (int i = 0; i < T_COUNT; ++i)
		{
			std.hash_function()(v[i]);
		}
		end_std = timer();
	}

	if (!leaks)
		start_ft = timer();
	for (int i = 0; i < T_COUNT; ++i)
	{
		ft.hash_function()(v[i]);
	}
	if (!leaks)
		end_ft = timer();
}
