/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/12 15:36:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	ft_printfunc(philo->cons, philo->ph_num, "has taken fork");
	pthread_mutex_lock(philo->fork_r);
	ft_printfunc(philo->cons, philo->ph_num, "has taken fork");
	ft_printfunc(philo->cons, philo->ph_num, "is eating");
	if (ft_wait_and_die(philo->cons->tt_eat + ft_get_millis(), philo))
		return ;
	pthread_mutex_lock(&philo->for_amount);
	philo->a_eaten++;
	if (philo->a_eaten == philo->cons->gt_eat)
	{
		pthread_mutex_lock(&philo->cons->for_done);
		philo->cons->ph_done++;
		pthread_mutex_unlock(&philo->cons->for_done);
	}
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
	ft_wait_until(philo->cons->tt_die + ft_get_millis());
	pthread_mutex_unlock(&philo->fork_l);
	ft_printfunc(philo->cons, philo->ph_num, "died");
	pthread_mutex_lock(&philo->cons->for_alive);
	philo->cons->one_dead = true;
	pthread_mutex_unlock(&philo->cons->for_alive);
	return ;
}

bool	simulation_is_running(t_ph_cons *cons)
{
	bool	check;

	check = true;
	pthread_mutex_lock(&cons->for_alive);
	if (cons->one_dead == true)
		check = false;
	pthread_mutex_unlock(&cons->for_alive);
	pthread_mutex_lock(&cons->for_done);
	if (cons->ph_done == cons->ph_amount)
		check = false;
	pthread_mutex_unlock(&cons->for_done);
	return (check);
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
			if (simulation_is_running(philo->cons))
				is_eating(philo);
			if (simulation_is_running(philo->cons))
				ft_printfunc(philo->cons, philo->ph_num, "is sleeping");
			if (simulation_is_running(philo->cons) && philo->l_eaten
				+ philo->cons->tt_sleep < philo->l_eaten + philo->cons->tt_die)
				ft_wait_until(philo->cons->tt_sleep + ft_get_millis());
			else if (simulation_is_running(philo->cons) && philo->l_eaten
				+ philo->cons->tt_sleep > philo->l_eaten + philo->cons->tt_die)
				ft_die_sleeping(philo);
			if (simulation_is_running(philo->cons))
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
		if (!simulation_is_running(cons))
			return (NULL);
		pthread_mutex_lock(&cons->for_done);
		if (cons->ph_done >= cons->ph_amount)
		{
			pthread_mutex_unlock(&cons->for_done);
			return (NULL);
		}
		pthread_mutex_unlock(&cons->for_done);
		i++;
		if (i == cons->ph_amount - 1)
			i = 0;
	}
	return (NULL);
}
