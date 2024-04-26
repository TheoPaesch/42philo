/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:36:56 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/24 23:09:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_error(1), 1);
	else
	{
		if (!ft_isnum())
			return (ft_error(0), 1);
	}
}
/* check for valid arguments
create threads and give them checks for time
pthread_mutex_init
pthread_mutex_lock
pthread_mutex_unlock
*/