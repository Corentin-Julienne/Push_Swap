/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:41:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/10 14:39:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

# define BROKEN 	0
# define CORRECT	1

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
	int			*nums;
	int			i;
	t_stack		*pile;

	if (pile_id == ALPHA)
		pile = data->pile_a;
	else
		pile = data->pile_b;
	nums = pile_to_int_arr(pile);
	if (!nums)
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
	quicksort(nums, 0, data->stack_size - 1);
	i = 0;
	while (i < data->stack_size)
	{
		if (nums[i] != pile->num)
			printf("diff at index %i : is %i and should be %i\n", i, pile->num, nums[i]);
		i++;
		pile = pile->next;
	}
}

/* check if stack sorted (the other pile MUST BE EMPTY) */

void	is_stack_sorted(t_data *data, int pile_id)
{
	t_stack		*pile;
	int			*nums;
	int			*nums_dup;
	int			stack_size;
	
	if (pile_id == ALPHA)
		pile = data->pile_a;
	else
		pile = data->pile_b;
	nums = pile_to_int_arr(pile);
	if (! nums)
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
	stack_size = data->stack_size;
	nums_dup = int_arr_dup(nums, stack_size);
	if (!nums_dup)
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
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
	t_stack		*iter;

	if (data->pile_a)
	{
		ft_printf("PILE A\n");
		iter = data->pile_a;
		while (iter->next)
		{
			ft_printf("%i\n", iter->num);
			iter = iter->next;
		}
		ft_printf("%d\n", iter->num);
	}
	if (data->pile_b)
	{
		printf("PILE B\n");
		iter = data->pile_b;
		while (iter->next)
		{
			ft_printf("%d\n", iter->num);
			iter = iter->next;
		}
		ft_printf("%d\n", iter->num);
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
