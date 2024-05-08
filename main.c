/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:36:56 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/08 22:45:49 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_ph_cons	*cons;

	cons = malloc(sizeof(t_ph_cons));
	if (argc < 5 || argc > 6)
		return (ft_error(1), 1);
	else
	{
		if (check_input(argc, argv))
			return (1);
		if (get_conditions(argc, argv, cons))
			return (ft_error(0), 1);
		if (init_forks(cons))
			return (ft_error(0), 1);
		if (init_threads(cons))
			return (ft_error(0), 1);
	}
	while (simulation_is_running(cons))
		usleep(500);
	return (0);
}
/* check for valid arguments
create threads and give them checks for time
pthread_mutex_init
pthread_mutex_lock
pthread_mutex_unlock
*/