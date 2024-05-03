/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/03 21:24:58 by tpaesch          ###   ########.fr       */
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
	philos.ph_alive = 1;
	philos.a_eaten = 0;
	philos.l_eaten = 0;
}

void	ft_die(t_philo *philo)
{
	ft_log_died(philo);
	ft_stop(philo->info);
}
