/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/12 11:25:10 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	decision_tree(t_data *data, int arr_len)
{
	data->counter = 0;
	data->pile_b = NULL;
	if (arr_len == 2)
		algo_case_two_nums(data);
	else if (arr_len == 3)
		algo_case_three_nums(data, data->pile_a);
	else if (arr_len == 4)
		algo_case_four_nums(data);
	else if (arr_len == 5)
		algo_case_five_nums(data);
	else if (arr_len >= 6)
		algo_big_nums(data);
}

void	msg_writer(int fildes, char *msg, t_data *data) // OK
{	
	if (write(fildes, msg, ft_strlen(msg)) == -1)
		free_stacks_and_exit(data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**input;

	atexit(leaks_tracking); // leak tracker, suppress after use
	if (argc == 1)
	{
		ft_printf("\n");
		exit(EXIT_SUCCESS);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit(NULL);
	input = format_input(argc, argv, data);
	data->pile_a = check_args_are_valid(input, data);
	data->pile_begin = NULL;
	if (data->is_sorted == 1)
	{
		free(data->pile_a);
		free(data);
		exit(EXIT_SUCCESS);
	}
	decision_tree(data, data->stack_size);
	final_verifs(data); // verifs
	suppress_leaks_bfr_exit(data);
	return (0);
}
