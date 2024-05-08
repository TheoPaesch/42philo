/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:48:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/08 01:31:56 by tpaesch          ###   ########.fr       */
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

void	free_philos(t_ph_cons *cons, int id)
{
	unsigned int	i;

	i = 0;
	if (id == 2)
	{
		while (i < cons->ph_amount)
		{
			pthread_mutex_destroy(&cons->philos[i].fork_l);
			pthread_mutex_destroy(&cons->philos[i].for_amount);
			pthread_mutex_destroy(&cons->philos[i].for_eaten);
			pthread_join(cons->philos[i].ph_thread, NULL);
			i++;
		}
		pthread_mutex_destroy(&cons->for_alive);
	}
	free(cons->philos);
	cons->philos = NULL;
}

/*remember to finish main thread before freeing structs*/