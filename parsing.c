/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:24:23 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/03 00:58:28 by tpaesch          ###   ########.fr       */
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

void	ft_atoi(const char *str, unsigned int *num)
{
	int				i;
	unsigned int	temp;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = (temp * 10) + (str[i] - '0');
		i++;
	}
	if (temp > 2147483647)
		return (1);
	*num = (unsigned int *)temp;
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	check;

	check = 0;
	if (ft_isnum(argc, argv))
		return (ft_error(0), 1);
	ft_atoi(argv[1], (int *)check);
	if (check < 1 || check > 200)
		return (ft_error(1), 1);
}
