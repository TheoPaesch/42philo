/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/27 22:31:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if times are overdue*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */

void	lock_forks(t_ph_cons *cons, int num)
{
	pthread_mutex_lock(cons->fork[num]);
	if (num == 0)
		num = cons->ph_amount;
	pthread_mutex_lock(cons->fork[num - 1]);
}

void	*ph_routine(void *ph)
{
	t_ph_cons	*cons;

	cons = (t_ph_cons *)ph;
	lock_forks(cons, num)
}

void	*keep_routine(void *barkeep)
{
}