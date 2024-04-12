/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:17:25 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/10 16:04:13 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*function that checks the philo stats and sets flag to dead*/
void	check_philo(t_philos phiolos, t_ph_cons cons)
{
	if (philos.tt_sleep > cons.tt_sleep || philos.tt_eat > cons.tt_eat
		|| philos.tt_die >= cons.tt_die)
	{
		philos.ph_alive = 0;
	}
}

/*function that checks philo flag and if dead free all*/
