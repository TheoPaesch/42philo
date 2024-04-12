/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:48:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/07 16:20:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int i)
{
	if (i == 0)
		printf("error\n");
	if (i == 1)
	{
		printf("----------------------------------------------\n");
		printf("usage of arguments must be as followed:\n");
		printf("1 : number of philosophers\n");
		printf("2 : time to die\n");
		printf("3 : time to eat\n");
		printf("4 : time to sleep\n");
		printf("5 : (optional) number of times philos must eat\n");
		printf("----------------------------------------------\n");
	}
}

/*function that frees all philos and all mem allocated inside them*/