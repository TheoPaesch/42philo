/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:09 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/08 23:42:23 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_get_millis(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_wait_until(unsigned int time)
{
	unsigned int	diff_time;
	unsigned int	current_time;

	while (true)
	{
		current_time = ft_get_millis();
		if (current_time >= time)
			break ;
		diff_time = (time - current_time) * 1000;
		if (diff_time < 5000)
			usleep(100);
		else
			usleep(diff_time * 0.9);
	}
}

bool	ft_wait_and_die(unsigned int time, t_philos *philo)
{
	unsigned int	die_time;

	die_time = philo->l_eaten + philo->cons->tt_die;
	if (die_time < time)
	{
		ft_wait_until(die_time);
		pthread_mutex_lock(&philo->cons->for_print);
		if (philo->cons->one_dead == false)
		{
			ft_die(philo->cons);
			printf("%u %d died\n", ft_get_millis() - philo->cons->tt_start,
				philo->ph_num);
		}
		pthread_mutex_unlock(&philo->cons->for_print);
		return (true);
	}
	ft_wait_until(time);
	return (false);
}
