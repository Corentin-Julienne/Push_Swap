/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 18:38:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check if number at top of pile B is within or without the pile A interval,
the apply different func to handle both cases. Repeat for second number*/

static void	handle_pile_bravo(t_data *data)
{
	int		*nums;
	int		i;

	i = 0;
	while (i < 2)
	{
		nums = pile_to_int_arr(data->pile_a);
		if (!nums)
			free_stacks_and_exit(data);
		if (is_within_interval(data->pile_b, nums, i + 3) == 0)
			handle_outside_interval(data, nums);
		else
			handle_within_interval(data, nums, i + 4);
		i++;
	}
}

/* this algo push the first two nums on pile B,
then apply algo for three nums on pile A
(if not sorted already), then handle pile B */

void	algo_case_five_nums(t_data *data)
{
	int			*nums;

	pb(data, data->pile_a, data->pile_b);
	pb(data, data->pile_a, data->pile_b);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	algo_case_three_nums(data, nums);
	free(nums);
	handle_pile_bravo(data);
}
