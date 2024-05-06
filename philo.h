/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/06 02:38:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_ph_cons	t_ph_cons;

typedef struct s_philos
{
	int						ph_num;
	pthread_t				ph_thread;
	pthread_mutex_t			*for_eaten;
	pthread_mutex_t			*for_amount;
	pthread_mutex_t			*fork_l;
	pthread_mutex_t			*fork_r;
	unsigned int			tt_sleep;
	unsigned int			tt_eat;
	unsigned int			tt_die;
	int						a_eaten;
	unsigned int			l_eaten;
	t_ph_cons				*cons;
}							t_philos;

typedef struct s_ph_cons
{
	pthread_mutex_t			*for_alive;
	pthread_t				barkeep;
	unsigned int			tt_sleep;
	unsigned int			tt_eat;
	unsigned int			tt_die;
	bool					one_dead;
	int						ph_done;
	unsigned int			ph_amount;
	int						a_eaten;
	unsigned int			gt_eat;
	t_philos				*philos;
}							t_ph_cons;

void						ft_error(int i);
int							get_conditions(int argc, char **argv,
								t_ph_cons cons, t_philos philos);
int							init_threads(t_ph_cons cons);
void						*ph_routine(void *philo);
void						*keep_routine(void *barkeep);
unsigned int				ft_get_millis(void);
void						ft_wait_until(unsigned int time);
void						fill_philo(t_philos philos, t_ph_cons cons,
								int num);
int							ft_malloc(size_t size, void **ptr);
void						free_philos(t_ph_cons *cons, int id);
bool						ft_atoi(const char *str, unsigned int *num);
int							ft_isnum(int argc, char **argv);
#endif