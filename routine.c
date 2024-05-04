/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/04 03:27:37 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if times are overdue*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */

void	single_routine(t_philos philo)
{
	pthread_mutex_lock(philo.fork_l);
	/*print for eating here*/
	ft_wait_until(philo.tt_eat + ft_get_millis());
	/*philo has to die*/
	pthread_mutex_unlock(philo.fork_l);
	/*end program here*/
}

/*void	lock_forks(t_ph_cons *cons)
{
}
*/

void	*ph_routine(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	if (&philo->cons->ph_amount == 1)
		single_routine(*philo);
	while (simulation_is_running(philo->cons))
	{
		/*print for thinking here*/
		pthread_mutex_lock(&philo->fork_l);
		pthread_mutex_lock(&philo->fork_r);
		/*print for eating here*/
		ft_wait_and_die(philo->tt_eat + ft_get_millis(), philo);
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(&philo->fork_r);
		/*print for sleeping here*/
		ft_wait_until(&philo->tt_sleep + ft_get_millis());
	}
}

void	*keep_routine(void *barkeep)
{
	t_ph_cons	*cons;
	int			i;

	cons = (t_ph_cons *)barkeep;
	i = 0;
	while (i < cons->ph_amount)
	{
		if (cons->philos[i].a_eaten < cons->gt_eat)
			return (true);
		i++;
	}
	return (false);
}

bool	simulation_is_running(t_ph_cons *cons)
{
	if (cons->one_dead)
		return (false);
	if (cons->a_eaten == true)
		return (false);
	return (true);
}