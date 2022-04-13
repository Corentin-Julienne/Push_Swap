/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:25 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/13 12:04:04 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* rotate pile A until data->pile_b inf to data->pile_a,
then push push data->pile_b to data->pile_a,
then use sort_param_top_b to */

void	handle_within_interval(t_data *data)
{
	while (data->pile_b[0] > data->pile_a[0])
		rab(data, data->pile_a, ALPHA);
	pa(data, data->pile_a, data->pile_b);
	sort_param_top_b(data, data->pile_a);
}

/* when outside interval, push num at the top of pile B to top of pile A,
then check if sorted. if not, just rotate the num at the bottom of pile A */

void	handle_outside_interval(t_data *data, int *interval) // yet to test
{
	pa(data, data->pile_a, data->pile_b);
	if (data->pile_a[0] > interval[0])
		rab(data, data->pile_a, ALPHA);
}

/* find_interval function returns an array of two ints. 
index 0 refers to smallest num in the stack 
while index 1 refers to the  biggest  */

static void	find_biggest(int *pile, int *int_arr)
{
	int		biggest;
	int		i;

	biggest = INT_MIN;
	i = 0;
	while (pile && pile[i])
	{
		if (biggest < pile[i])
			biggest = pile[i];
		i++;
	}
	int_arr[1] = biggest;
}

static void	find_smallest(int *pile, int *int_arr)
{
	int		smallest;
	int		i;

	smallest = INT_MAX;
	i = 0;
	while (pile && pile[i])
	{
		if (smallest > pile[i])
			smallest = pile[i];
		i++;
	}
	int_arr[0] = smallest;
}

int	*find_interval(t_data *data, int a_or_b)
{
	int			*int_arr;
	int			*pile;

	if (a_or_b == ALPHA)
		pile = data->pile_a;
	else
		pile = data->pile_b;
	int_arr = (int *)malloc(sizeof(int) * 2);
	if (!int_arr)
		return (NULL);
	find_smallest(pile, int_arr);
	find_biggest(pile, int_arr);
	return (int_arr);
}
