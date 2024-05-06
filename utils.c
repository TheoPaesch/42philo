/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/04 14:33:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_malloc(size_t size, void **ptr)
{
	*ptr = malloc(size);
	return (*ptr == NULL);
}

void	fill_philo(t_philos philos, t_ph_cons cons, int num)
{
	philos.ph_num = num;
	philos.tt_sleep = cons.tt_sleep;
	philos.tt_eat = cons.tt_eat;
	philos.tt_die = cons.tt_die;
	philos.a_eaten = 0;
	philos.l_eaten = ft_get_millis();
	philos.cons = &cons;
}

void	ft_die(t_ph_cons *cons)
{
	pthread_mutex_lock(cons->for_alive);
	cons->one_dead = true;
	pthread_mutex_unlock(cons->for_alive);
}
