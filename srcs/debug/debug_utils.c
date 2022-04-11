/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:41:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 18:57:47 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* debugging function : NOT TO PUSH FOR CORRECTION */

void	*broken_malloc(void)
{
	return (NULL);
}

void	leaks_tracking(void)
{
	system("leaks push_swap");
}

/* just print a msg if input accepted by the push_swap program */

void	msg_accept_input(void)
{
	ft_putstr_fd("input has been accepted by the program\n", STDIN_FILENO);
	exit(EXIT_SUCCESS);
}

static void	mistake_report(t_data *data, int pile_id)
{
	int			*nums_dup;
	int			*pile;
	int			i;

	if (pile_id == ALPHA)
		pile = data->pile_a;
	else
		pile = data->pile_b;
	nums_dup = int_arr_dup(pile, data->stack_size);
	if (!nums_dup)
		ft_putstr_fd("malloc error !!!!\n", STDERR_FILENO);
	quicksort(nums_dup, 0, data->stack_size - 1);
	i = 0;
	while (i < data->stack_size)
	{
		if (nums_dup[i] != pile[i])
			printf("diff at index %i : is %i and should be %i\n", i, pile[i], nums_dup[i]);
		i++;
	}
}

/* check if stack sorted (the other pile MUST BE EMPTY) */

void	is_stack_sorted(t_data *data, int pile_id)
{
	int			*pile;
	int			*nums;
	int			*nums_dup;
	int			stack_size;
	
	if (pile_id == ALPHA)
		pile = data->pile_a;
	else
		pile = data->pile_b;
	stack_size = data->stack_size;
	nums_dup = int_arr_dup(nums, stack_size);
	if (!nums_dup)
		ft_putstr_fd("malloc error !!!!\n", STDERR_FILENO);
	quicksort(nums_dup, 0, stack_size - 1);
	if (are_arr_equals(nums, nums_dup, stack_size) == 1)
		ft_putstr_fd("stack is sorted !!!!\n", STDOUT_FILENO);
	else
	{
		ft_putstr_fd("stack is not sorted !!!!\n", STDOUT_FILENO);
		mistake_report(data, pile_id);
	}
	free(nums);
	free(nums_dup);
}

void	display_pile(t_data *data)
{
	int		i;
	
	if (data->pile_a)
	{
		ft_printf("PILE A\n");
		i = 0;
		while (i < data->size_a)
		{
			printf("%i\n", data->pile_a[i]);
			i++;
		}
	}
	if (data->pile_b)
	{
		ft_printf("PILE A\n");
		i = 0;
		while (i < data->size_b)
		{
			printf("%i\n", data->pile_b[i]);
			i++;
		}
	}
	ft_printf("\n----------------------------------\n");
}

/* handle the verifs after the algo action */

void	final_verifs(t_data *data)
{
	ft_printf("\n----------------------------------\n");
	ft_printf("Check if pile B is empty, it should be !!!!\n");
	display_pile(data);
	is_stack_sorted(data, ALPHA);
	ft_printf("\n----------------------------------\n");
	ft_printf("Program terminated ! Keep going, initiate !!!\n");
}
