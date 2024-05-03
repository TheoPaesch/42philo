/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/28 20:48:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if times are overdue*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */

void	single_routine(t_ph_cons cons)
{
	pthread_mutex_lock(&cons->fork_l);
	/*print for eating here*/
	ft_wait_until(cons->tt_eat + ft_get_millis());
	/*philo has to die*/
	pthread_mutex_unlock(&cons->fork_l);
	/*end program here*/
}

void	lock_forks(t_ph_cons *cons)
{
}

void	*ph_routine(void *ph)
{
	t_ph_cons	*cons;

	cons = (t_ph_cons *)ph;
	if (cons->ph_amount == 1)
		single_routine(&cons);
}

void	*keep_routine(void *barkeep)
{
}