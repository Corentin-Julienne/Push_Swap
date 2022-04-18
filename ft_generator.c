/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:43:57 by user42            #+#    #+#             */
/*   Updated: 2022/03/31 13:10:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NOT MY CODE : COURTESY OF GROUBAUD | FOR TESTING PURPOSES ONLY */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	rand_a_number(int min, int max)
{
	static int	rand_is_seeded = 0;

	if (!rand_is_seeded)
	{
		srand(time(NULL));
		rand_is_seeded = 1;
	}
	return (rand() % (max - min + 1) + min);
}

void	ft_generator(int size, int min, int max)
{
	int	*tab;
	int	i;
	int	j;
	int	r;

	if (max - min < size)
	{
		printf("too few possibilities in this size");
		return ;
	}
	tab = (int *)malloc(sizeof(*tab) * size);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		r = rand_a_number(min, max);
		while (j < i)
		{
			if (tab[j] == r)
				break ;
			j++;
		}
		if (tab[j] != r)
		{
			tab[j] = r;
			i++;
		}
	}
	i = 0;
	while (i < size)
		printf("%i ", tab[i++]);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		printf("./a.out <nb of numero> <min> <max>");
	else
		ft_generator(atoi(av[1]), atoi(av[2]), atoi(av[3]));
	return (0);
}
