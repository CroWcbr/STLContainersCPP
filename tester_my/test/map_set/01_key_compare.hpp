#pragma once

#include "../_define.hpp"
#include "../_utils.hpp"

template<class FT, class STD>
bool test_all()
{
#if defined(SET)
	typedef ft::set<int, std::greater<int> >	FT2;
	typedef std::set<int, std::greater<int> >	STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return false;
#elif defined(MULTISET)
	typedef ft::multiset<int, std::greater<int> > FT2;
	typedef std::multiset<int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
#elif defined(MAP)
	typedef ft::map<int, int, std::greater<int> > FT2;
	typedef std::map<int, int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
#elif defined(MULTIMAP)
	typedef ft::multimap<int, int, std::greater<int> > FT2;
	typedef std::multimap<int, int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
#elif defined(UNORDERED_SET)
	typedef ft::unordered_set<int, std::greater<int> >	FT2;
	typedef std::unordered_set<int, std::greater<int> >	STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return false;
#endif

	for (int i = 0; i < T_COUNT; ++i)
	{
		if (!check_equel_container(FT_new[i], STD_new[i]))
		{
			return false;
		}
	}
	return true;
}

template<class FT, class STD>
void	test_time(bool leaks, time_t& start_ft, time_t& start_std, time_t& end_ft, time_t& end_std)
{
#if defined(SET)
	typedef ft::set<int, std::greater<int> >	FT2;
	typedef std::set<int, std::greater<int> >	STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return;
#elif defined(MULTISET)
	typedef ft::multiset<int, std::greater<int> > FT2;
	typedef std::multiset<int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return;
#elif defined(MAP)
	typedef ft::map<int, int, std::greater<int> > FT2;
	typedef std::map<int, int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return;
#elif defined(MULTIMAP)
	typedef ft::multimap<int, int, std::greater<int> > FT2;
	typedef std::multimap<int, int, std::greater<int> > STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return;
#elif defined(UNORDERED_SET)
	typedef ft::unordered_set<int, std::greater<int> >	FT2;
	typedef std::unordered_set<int, std::greater<int> >	STD2;
	FT2		FT_new[T_COUNT];
	STD2	STD_new[T_COUNT];
	if (!fill_array_conteiner_from_file<FT2, STD2>(FT_new, STD_new, T_COUNT))
		return;
#endif

	if (!leaks)
	{
		start_std = timer();
		for (int i = 0; i < T_COUNT; ++i)
		{
			STD_new[i].key_comp()(1, 2);
		}
		end_std = timer();
	}

	if (!leaks)
		start_ft = timer();
	for (int i = 0; i < T_COUNT; ++i)
	{
		FT_new[i].key_comp()(1, 2);
	}
	if (!leaks)
		end_ft = timer();
}
