/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:25 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 17:27:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* find_interval function returns an array of two ints. 
index 0 refers to smallest num in the stack 
while index 1 refers to the  biggest  */

static void	find_biggest(int *pile, int *int_arr)
{
	int		biggest;
	int		i;

	biggest = INT_MIN;
	while (pile)
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
	while (pile)
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
