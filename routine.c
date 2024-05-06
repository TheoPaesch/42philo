/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/06 22:09:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if philo died or meals finished*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */

void	single_routine(t_philos philo)
{
	pthread_mutex_lock(philo.fork_l);
	printf("philo %d is eating : %u\n", philo.ph_num, ft_get_millis());
	ft_wait_and_die(philo.tt_eat + ft_get_millis(), &philo);
	pthread_mutex_unlock(philo.fork_l);
	return ;
}

bool	simulation_is_running(t_ph_cons *cons)
{
	if (cons->one_dead)
		return (false);
	if (cons->a_eaten == true)
		return (false);
	return (true);
}

void	*ph_routine(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	if (philo->cons->ph_amount == 1)
		single_routine(*philo);
	else
	{
		while (simulation_is_running(philo->cons))
		{
			printf("philo %d is thinking : %u\n", philo->ph_num,
				ft_get_millis());
			pthread_mutex_lock(philo->fork_l);
			pthread_mutex_lock(philo->fork_r);
			printf("philo %d is eating : %u\n", philo->ph_num, ft_get_millis());
			ft_wait_and_die(philo->tt_eat + ft_get_millis(), philo);
			philo->a_eaten++;
			pthread_mutex_unlock(philo->fork_l);
			pthread_mutex_unlock(philo->fork_r);
			printf("philo %d is sleeping : %u\n", philo->ph_num,
				ft_get_millis());
			ft_wait_until(philo->tt_sleep + ft_get_millis());
		}
	}
	return (NULL);
}

void	*keep_routine(void *barkeep)
{
	t_ph_cons		*cons;
	unsigned int	i;

	cons = (t_ph_cons *)barkeep;
	i = 0;
	while (i < cons->ph_amount)
	{
		if (cons->philos[i].a_eaten == cons->gt_eat)
		{
			free_philos(cons, 2);
			return (NULL);
		}
		if (cons->one_dead == true)
		{
			free_philos(cons, 2);
			return (NULL);
		}
		i++;
		if (i == cons->ph_amount)
			i = 0;
	}
	return (NULL);
}
