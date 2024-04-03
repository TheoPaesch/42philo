/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:24:23 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/03 14:31:44 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1 while (j != argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][0] == '+' && argv[j][1] != '\0')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
}

int	ft_atoi(const char *str, int *num)
{
	int i;
	long int temp;

	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = (temp * 10) + (str[i] - '0');
		i++;
	}
	if (temp > 2147483647)
		return (1);
	*num = (int *)temp;
	return (0);
}