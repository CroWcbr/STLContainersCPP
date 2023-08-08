#pragma once

#include "../_define.hpp"
#include "../_utils.hpp"

template<class FT, class STD>
bool test_all()
{
	FT	ft_test[T_COUNT];
	STD	std_test[T_COUNT];
	if (!fill_array_conteiner_from_file<FT, STD>(ft_test, std_test, T_COUNT))
		return false;

	for (int i = 0; i < T_COUNT; ++i)
	{
		if (std_test[i].empty())
			continue;

#ifdef STACK
		typename FT::reference ft_ref = ft_test[i].top();
		typename STD::reference std_ref = std_test[i].top();

		if (ft_ref!= std_ref)
		{
			return false;
		}
#endif

		typename FT::const_reference ft_const_ref = ft_test[i].top();
		typename STD::const_reference std_const_ref = std_test[i].top();

		if (ft_const_ref!= std_const_ref)
		{
			return false;
		}

	}
	return true;
}

template<class FT, class STD>
void	test_time(bool leaks, time_t& start_ft, time_t& start_std, time_t& end_ft, time_t& end_std)
{
	FT	ft_test[T_COUNT];
	STD	std_test[T_COUNT];
	if (!fill_array_conteiner_from_file<FT, STD>(ft_test, std_test, T_COUNT))
		return;

	if (!leaks)
	{
		start_std = timer();
		for (int i = 0; i < T_COUNT; ++i)
		{
			if (std_test[i].empty())
				continue;
			std_test[i].top();
		}
		end_std = timer();
	}

	if (!leaks)
		start_ft = timer();
	for (int i = 0; i < T_COUNT; ++i)
	{
		if (ft_test[i].empty())
			continue;
		ft_test[i].top();
	}
	if (!leaks)
		end_ft = timer();
}