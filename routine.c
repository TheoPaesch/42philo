/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/08 02:59:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if philo died or meals finished*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */
void	is_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	ft_printfunc(philo->cons, philo->ph_num, "has taken fork one");
	pthread_mutex_lock(philo->fork_r);
	ft_printfunc(philo->cons, philo->ph_num, "has taken fork two");
	ft_printfunc(philo->cons, philo->ph_num, "is eating");
	ft_wait_and_die(philo->cons->tt_eat + ft_get_millis(), philo);
	pthread_mutex_lock(&philo->for_amount);
	philo->a_eaten++;
	pthread_mutex_unlock(&philo->for_amount);
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_lock(&philo->for_eaten);
	philo->l_eaten = ft_get_millis();
	pthread_mutex_unlock(&philo->for_eaten);
	return ;
}

void	single_routine(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	ft_printfunc(philo->cons, philo->ph_num, "has taken a fork");
	ft_wait_and_die(philo->cons->tt_eat + ft_get_millis(), philo);
	pthread_mutex_unlock(&philo->fork_l);
	return ;
}

bool	simulation_is_running(t_ph_cons *cons)
{
	bool	check;

	check = true;
	ft_printfunc(cons, check, "shit");
	pthread_mutex_lock(&cons->for_alive);
	if (cons->one_dead == true)
		check = false;
	pthread_mutex_unlock(&cons->for_alive);
	pthread_mutex_lock(&cons->for_done);
	if (cons->ph_done == cons->ph_amount)
		check = false;
	pthread_mutex_unlock(&cons->for_done);
	ft_printfunc(cons, check, "shit");
	return (check);
}

void	sleep_check(t_philos *philo)
{
	if (philo->ph_num % 2 == 0)
	{
		ft_printfunc(philo->cons, philo->ph_num, "is thinking");
		ft_wait_until(philo->cons->tt_eat / 2 + ft_get_millis());
	}
	return ;
}

void	*ph_routine(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	if (philo->cons->ph_amount == 1)
		single_routine(philo);
	else
	{
		sleep_check(philo);
		while (simulation_is_running(philo->cons))
		{
			is_eating(philo);
			ft_printfunc(philo->cons, philo->ph_num, "is sleeping");
			ft_wait_until(philo->cons->tt_sleep + ft_get_millis());
			ft_printfunc(philo->cons, philo->ph_num, "is thinking");
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
		ft_printfunc(cons, i + 1, "iteration check");
		if (cons->philos[i].a_eaten == cons->gt_eat)
		{
			ft_printfunc(cons, i + 1, "died");
			free_philos(cons, 2);
			return (NULL);
		}
		if (cons->one_dead == true)
		{
			ft_printfunc(cons, i + 1, "died through console");
			free_philos(cons, 2);
			return (NULL);
		}
		i++;
		if (i == cons->ph_amount - 1)
			i = 0;
	}
	return (NULL);
}
