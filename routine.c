/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:41:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/26 17:13:40 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*routine for table (barkeep), that checks if times are overdue*/
/*routine for the philosophers, calculating the time from when
last eaten, to end of meal, end of sleep ... */

void	lock_forks(t_ph_cons cons)
{
	pthread_mutex_lock(cons.philo.fork);
	if (philo.ph_num == 0)
		num = cons.ph_amount;
	pthread_mutex_lock(cons.philos[num - 1].fork);
}

void	*ph_routine(void *ph)
{
	t_ph_cons	*cons;

	cons = (t_ph_cons *)ph;
	lock_forks()
}

void	*keep_routine(void *barkeep)
{
}