#pragma once

#include "_define.hpp"
#include <cstdlib>
#include <sys/time.h>

#include <iostream>
#include <fstream>
#include <sstream>

time_t	timer()
{
	struct timeval start = {};
	gettimeofday(&start, NULL);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void	fill_array_random(int *array, int size, int min, int max)
{
	for(int i = 0; i < size; ++i)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

#if defined(MAP) || defined(MULTIMAP) || defined(UNORDERED_MAP) || defined(UNORDERED_MULTIMAP)
void	fill_array_random_pair(ft::pair<int,int> *ft_array, std::pair<int,int> *std_array, int size, int min, int max)
{
	for(int i = 0; i < size; ++i)
	{
		int key = rand() % (max - min + 1) + min;
		int value = rand() % (max - min + 1) + min;
		ft_array[i] = ft::pair<int, int>(key, value);
		std_array[i] = std::pair<int, int>(key, value);
	}
}
#endif

template<class CONT_FT, class CONT_STD>
bool	fill_array_conteiner_from_file(CONT_FT *ft_array, CONT_STD *std_array, int size)
{
	std::ifstream inputFile(_DATA_FILE);
	if (!inputFile)
	{
		std::cerr << "ERROR: " << (_DATA_FILE) << std::endl;
		return false;
	}

	std::string line;
	for (int i = 0; i < size; ++i)
	{
		std::getline(inputFile, line);
		std::stringstream  ss(line);
		int number;
		while (ss >> number)
		{
#if defined(VECTOR) || defined(LIST) || defined(DEQUE)
			ft_array[i].push_back(number);
			std_array[i].push_back(number);
#elif defined(SET) || defined(MULTISET) || defined(UNORDERED_SET) || defined(UNORDERED_MULTISET)
			ft_array[i].insert(number);
			std_array[i].insert(number);
#elif defined(STACK) || defined(QUEUE) || defined(PRIORITY_QUEUE)
			ft_array[i].push(number);
			std_array[i].push(number);
#elif defined(MAP) || defined(MULTIMAP)|| defined(UNORDERED_MAP) || defined(UNORDERED_MULTIMAP)
			int value;
			ss >> value;
			ft_array[i].insert(ft::pair<int, int>(number, value));
			std_array[i].insert(std::pair<int, int>(number, value));
#endif
		}
	}

	inputFile.close();
	return true;
}

template<class FT, class STD>
bool	check_equel_container(FT ft, STD std)
{
	if (ft.size() != std.size())
	{
		return false;
	}
#if defined(VECTOR) || defined(LIST) || defined(SET) || defined(MULTISET) || defined(MAP) || defined(MULTIMAP)
	typename FT::iterator	ft_it_s = ft.begin();
	typename FT::iterator	ft_it_e = ft.end();
	typename STD::iterator	std_it_s = std.begin();
	while (ft_it_s != ft_it_e)
	{
	#if defined(VECTOR) || defined(LIST) || defined(SET) || defined(MULTISET)
		if (*ft_it_s != *std_it_s)
	#elif defined(MAP) || defined(MULTIMAP)
		if ((*ft_it_s).first != (*std_it_s).first || (*ft_it_s).second != (*std_it_s).second)
	#endif
		{
			return false;
		}
		++ft_it_s;
		++std_it_s;
	}
#elif defined(STACK) || defined(QUEUE) || defined(PRIORITY_QUEUE)
	FT tmp_ft = ft;
	STD tmp_std = std;
	while (!tmp_ft.empty())
	{
	#if defined(STACK) || defined(PRIORITY_QUEUE)
		if (tmp_ft.top() != tmp_std.top())
	#elif defined(QUEUE)
		if (tmp_ft.front() != tmp_std.front())
	#endif
		{
			return false;
		}
		tmp_ft.pop();
		tmp_std.pop();
	}
#elif defined(UNORDERED_SET)
	ft::set<int>	ft_set(ft.begin(), ft.end());
	std::set<int>	std_set(std.begin(), std.end());
	typename ft::set<int>::iterator	ft_it_s = ft_set.begin();
	typename ft::set<int>::iterator	ft_it_e = ft_set.end();
	typename std::set<int>::iterator	std_it_s = std_set.begin();
	while (ft_it_s != ft_it_e)
	{
		if (*ft_it_s != *std_it_s)
		{
			return false;
		}
		++ft_it_s;
		++std_it_s;
	}
#elif defined(UNORDERED_MULTISET)
	ft::multiset<int>	ft_set(ft.begin(), ft.end());
	std::multiset<int>	std_set(std.begin(), std.end());
	typename ft::multiset<int>::iterator	ft_it_s = ft_set.begin();
	typename ft::multiset<int>::iterator	ft_it_e = ft_set.end();
	typename std::multiset<int>::iterator	std_it_s = std_set.begin();
	while (ft_it_s != ft_it_e)
	{
		if (*ft_it_s != *std_it_s)
		{		
			return false;
		}
		++ft_it_s;
		++std_it_s;
	}
#elif defined(UNORDERED_MAP)
	ft::map<int, int>	ft_map(ft.begin(), ft.end());
	std::map<int, int>	std_map(std.begin(), std.end());
	typename ft::map<int, int>::iterator		ft_it_s = ft_map.begin();
	typename ft::map<int, int>::iterator		ft_it_e = ft_map.end();
	typename std::map<int, int>::iterator		std_it_s = std_map.begin();
	while (ft_it_s != ft_it_e)
	{
		if ((*ft_it_s).first != (*std_it_s).first || (*ft_it_s).second != (*std_it_s).second)
		{
			return false;
		}
		++ft_it_s;
		++std_it_s;
	}
#elif defined(UNORDERED_MULTIMAP)
	ft::multimap<int, int>	ft_mmap(ft.begin(), ft.end());
	std::multimap<int, int>	std_mmap(std.begin(), std.end());
	typename ft::multimap<int, int>::iterator	ft_it_s = ft_mmap.begin();
	typename ft::multimap<int, int>::iterator	ft_it_e = ft_mmap.end();
	typename std::multimap<int, int>::iterator	std_tmp;
	while (ft_it_s != ft_it_e)
	{
		std_tmp = std_mmap.find(ft_it_s->first);
		if (std_tmp == std_mmap.end())
		{
			return false;
		}
		while (std_tmp !=  std_mmap.end() && std_tmp->first == ft_it_s->first)
		{
			if (std_tmp->second == ft_it_s->second)
			{
				break;
			}
			++std_tmp;
		}
		if (std_tmp ==  std_mmap.end() || std_tmp->first != ft_it_s->first)
		{
			return false;
		}
		++ft_it_s;
	}

#endif
	return true;
}
