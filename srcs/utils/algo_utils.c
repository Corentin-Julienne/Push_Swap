/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 16:53:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check whether the num at top of pile B is within or outside
the interval defined by the smallest num of pile A and the largest */

int	is_within_interval(t_stack *pile_b, int *nums, int num_size)
{
	if (pile_b->num < nums[0] && pile_b->num < nums[num_size - 1])
		return (0);
	if (pile_b->num > nums[0] && pile_b->num > nums[num_size - 1])
		return (0);
	return (1);
}

/* rotate pile A until data->pile_b inf to data->pile_a,
then push push data->pile_b to data->pile_a,
then use sort_param_top_b to */

void	handle_within_interval(t_data *data, int *nums, int num_len)
{
	while (data->pile_b->num > data->pile_a->num)
		rab(&(data->pile_a), ALPHA, data);
	pa(&(data->pile_a), &(data->pile_b), data);
	sort_param_top_b(data, nums, num_len);
}

/* when outside interval, push num at the top of pile B to top of pile A,
then check if sorted. if not, just rotate the num at the bottom of pile A */

void	handle_outside_interval(t_data *data, int *nums)
{
	pa(&(data->pile_a), &(data->pile_b), data);
	if (data->pile_a->num > nums[0])
		rab(&(data->pile_a), ALPHA, data);
	free(nums);
}

/* while pile A is sorted, push fourth number to top of pile A,
then until not sorted, rotate until sorted. Use an algo
to check what direction use the less moves */

void	sort_param_top_b(t_data *data, int *nums, int num_len)
{
	while (42)
	{
		free(nums);
		nums = pile_to_int_arr(data->pile_a);
		if (!nums)
			free_stacks_and_exit(data);
		if (check_if_already_sorted(nums, num_len) == 0)
		{
			if (distance_from_sorted_pos(data->pile_a->num, data->pile_a)
				== CLOCK)
				rab(&(data->pile_a), ALPHA, data);
			else
				rrab(&(data->pile_a), ALPHA, data);
		}
		else
		{
			free(nums);
			break ;
		}
	}
}
