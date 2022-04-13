/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/13 12:05:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* while pile A is sorted, push fourth number to top of pile A,
then until not sorted, rotate until sorted. Use an algo
to check what direction use the less moves */

void	sort_param_top_b(t_data *data, int *pile_a) // yet to test
{
	while (42)
	{
		if (check_if_already_sorted(pile_a, data->size_a) == 0)
		{
			if (distance_from_sorted_pos(data->pile_a[0], data,
				data->pile_a, ALPHA) == CLOCK)
				rab(data, data->pile_a, ALPHA);
			else
				rrab(data, data->pile_a, ALPHA);
		}
		else
			break ;
	}
}
