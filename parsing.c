/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:24:23 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/07 00:52:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][0] == '+' && argv[j][1] != '\0')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

int	check_input(int argc, char **argv)
{
	unsigned int	check;

	check = 0;
	if (ft_isnum(argc, argv))
		return (ft_error(0), 1);
	check = ft_atoi(argv[1]);
	if (check < 1 || check > 200)
		return (ft_error(1), 1);
	return (0);
}
