/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/26 11:54:54 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philos
{
	pthread_t		ph_thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	for_eaten;
	pthread_mutex_t	for_amount;
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_alive;
	int				a_eaten;
	unsigned int	l_eaten;
}					t_philos;

typedef struct s_ph_cons
{
	pthread_t		barkeep;
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_amount;
	int				a_eaten;
	int				gt_eat;
	t_philos		*philos;
}					t_ph_cons;

int					get_conditions(int argc, char **argv, t_ph_cons cons,
						t_philos philos);
int					init_threads(t_ph_cons cons);
void				*ph_routine(void *philo);
void				*keep_routine(void *barkeep);

#endif