/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/19 17:17:01 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philos
{
	pthread_t		ph_thread;
	pthread_mutex_t	fork;
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_alive;
	int				a_eaten;
	unsigned int	l_eaten;
}					t_philos;

typedef struct s_ph_cons
{
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_amount;
	int				a_eaten;
	int				gt_eat;
	unsigned int	l_eaten;
	struct t_philos	*philos;
}					t_ph_cons;

#endif