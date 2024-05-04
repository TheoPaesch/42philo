/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:09 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/04 02:53:09 by tpaesch          ###   ########.fr       */
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

	while (1)
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
	unsigned int die_time;

	die_time = philo->l_eaten + philo->tt_die;
	if (die_time < time)
	{
		ft_wait_until(die_time);
		ft_die(philo->cons);
		return (true);
	}
	ft_wait_until(time);
	return (false);
}