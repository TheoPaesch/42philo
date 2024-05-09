/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/09 02:03:55 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_philos *philos, t_ph_cons *cons, int num)
{
	philos->ph_num = num;
	philos->a_eaten = 0;
	philos->l_eaten = ft_get_millis();
	philos->cons = cons;
}

void	ft_die(t_ph_cons *cons, int ph_num)
{
	pthread_mutex_lock(&cons->for_alive);
	if (cons->one_dead == false)
	{
		pthread_mutex_unlock(&cons->philos[ph_num].fork_l);
		pthread_mutex_unlock(cons->philos[ph_num].fork_r);
		pthread_mutex_lock(&cons->philos[ph_num].for_eaten);
		cons->one_dead = true;
		pthread_mutex_lock(&cons->for_print);
		printf("%u %d died\n", ft_get_millis() - cons->tt_start, ph_num);
		pthread_mutex_unlock(&cons->for_print);
	}
	pthread_mutex_unlock(&cons->for_alive);
}

void	ft_printfunc(t_ph_cons *cons, int id, const char *msg)
{
	pthread_mutex_lock(&cons->for_alive);
	pthread_mutex_lock(&cons->for_print);
	if (cons->one_dead == true)
	{
		pthread_mutex_unlock(&cons->for_print);
		pthread_mutex_unlock(&cons->for_alive);
		return ;
	}
	printf("%u %d %s\n", ft_get_millis() - cons->tt_start, id, msg);
	pthread_mutex_unlock(&cons->for_alive);
	pthread_mutex_unlock(&cons->for_print);
}
