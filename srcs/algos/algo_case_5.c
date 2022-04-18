/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 17:53:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* this algo push the first two nums on pile B,
then apply algo for three nums on pile A
(if not sorted already), then handle pile B */

void	algo_case_five_nums(t_data *data)
{
	int			i;
	int			*interval;
	
	pb(data, data->pile_a, data->pile_b);
	pb(data, data->pile_a, data->pile_b);
	algo_case_three_nums(data, data->pile_a);
	i = 0;
	while (i < 2)
	{
		interval = find_interval(data, ALPHA);
		if (!interval)
			free_stacks_and_exit(data);
		if (data->pile_b[0] < interval[0] || data->pile_b[0] > interval[1])
		{
			handle_outside_interval(data, interval);
		}
		else
			handle_within_interval(data);
		i++;
		free(interval);
	}
}
