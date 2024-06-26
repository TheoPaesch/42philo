/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:51:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/09 01:15:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*function that allocates philosophers*/
int	get_conditions(int argc, char **argv, t_ph_cons *cons)
{
	unsigned int	i;

	i = 0;
	cons->tt_die = ft_atoi(argv[2]);
	cons->tt_eat = ft_atoi(argv[3]);
	cons->tt_sleep = ft_atoi(argv[4]);
	cons->ph_amount = ft_atoi(argv[1]);
	cons->ph_done = 0;
	cons->one_dead = false;
	cons->tt_start = ft_get_millis();
	if (argc == 6)
		cons->gt_eat = ft_atoi(argv[5]);
	else
		cons->gt_eat = UINT_MAX;
	cons->philos = malloc(sizeof(t_philos) * cons->ph_amount);
	if (cons->philos == NULL)
		return (ft_error(0), EXIT_FAILURE);
	while (i < cons->ph_amount)
	{
		fill_philo(&cons->philos[i], cons, i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	create_thread(t_philos *philo)
{
	if (pthread_create(&philo->ph_thread, NULL, ph_routine, philo))
	{
		ft_error(0);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_threads(t_ph_cons *cons)
{
	unsigned int	i;

	i = 0;
	cons->ph_done = 0;
	while (i < cons->ph_amount)
	{
		if (create_thread(&cons->philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_create(&cons->barkeep, NULL, keep_routine, cons))
	{
		ft_error(0);
		free_philos(cons, 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	init_forks(t_ph_cons *cons)
{
	unsigned int	i;

	i = 0;
	while (i < cons->ph_amount)
	{
		if (pthread_mutex_init(&cons->philos[i].for_eaten, NULL) != 0)
			return (ft_error(0), EXIT_FAILURE);
		if (pthread_mutex_init(&cons->philos[i].for_amount, NULL) != 0)
			return (ft_error(0), EXIT_FAILURE);
		if (pthread_mutex_init(&cons->philos[i].fork_l, NULL) != 0)
			return (ft_error(0), EXIT_FAILURE);
		if (i >= 1)
			cons->philos[i].fork_r = &cons->philos[i - 1].fork_l;
		i++;
	}
	cons->philos[0].fork_r = &cons->philos[cons->ph_amount - 1].fork_l;
	if (pthread_mutex_init(&cons->for_alive, NULL) != 0)
		return (ft_error(0), EXIT_FAILURE);
	if (pthread_mutex_init(&cons->for_print, NULL) != 0)
		return (ft_error(0), EXIT_FAILURE);
	if (pthread_mutex_init(&cons->for_done, NULL) != 0)
		return (ft_error(0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
