/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:51:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/04 03:09:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*function that allocates philosophers*/
int	get_conditions(int argc, char **argv, t_ph_cons cons, t_philos philos)
{
	int	i;

	i = 0;
	if (ft_atoi(argv[2], cons.tt_die))
		return (ft_error(0), EXIT_FAILURE);
	if (ft_atoi(argv[3], cons.tt_eat))
		return (ft_error(0), EXIT_FAILURE);
	if (ft_atoi(argv[4], cons.tt_sleep))
		return (ft_error(0), EXIT_FAILURE);
	if (argc == 6)
		if (ft_atoi(argv[5], cons.gt_eat))
			return (ft_error(0), EXIT_FAILURE);
	if (ft_atoi(argv[1], cons.ph_amount))
		return (ft_error(0), EXIT_FAILURE);
	else
	{
		if (ft_malloc(sizeof(philos) * cons.ph_amount, (void **)cons.philos))
			return (ft_error(0), EXIT_FAILURE);
		while (i <= cons.ph_amount)
		{
			fill_philo(cons.philos[i], cons, i + 1);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

static int	create_thread(t_philos philo)
{
	if (pthread_create(philo.ph_thread, NULL, ph_routine, &(philo)))
	{
		ft_error(0);
		free_philos(cons, 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_threads(t_ph_cons cons)
{
	int	i;

	i = 0;
	if (pthread_create(&(cons.barkeep), NULL, keep_routine, &(cons)))
	{
		ft_error(0);
		free_philos(cons, 1);
		return (EXIT_FAILURE);
	}
	while (i > cons.ph_amount)
	{
		if (create_thread(cons.philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_forks(t_ph_cons cons)
{
	int	i;

	i = 0;
	while (i < cons.ph_amount)
	{
		if (pthread_mutex_init(cons.philos[i].for_eaten, NULL))
			return (ft_error(0), EXIT_FAILURE);
		if (pthread_mutex_init(cons.philos[i].for_amount, NULL))
			return (ft_error(0), EXIT_FAILURE);
		if (pthread_mutex_init(cons.philos[i].fork_l, NULL))
			return (ft_error(0), EXIT_FAILURE);
		if (i >= 1)
			cons.philos[i].fork_r = cons.philos[i - 1].fork_l;
		/*remember to free here in returns*/
	}
	if (pthread_mutex_init(cons.for_alive, NULL))
		return (ft_error(0), EXIT_FAILURE);
	cons.philos[0].fork_r = cons.philos[cons.ph_amount].fork_l;
}

/* remember to destroy mutexes!!*/
/* function for init mutexes*/
/* give philo a groupnumber if it's a even number do %2 if not %3 ??*/
/*function that checks philosophers counts for milliseconds with timefunc*/
/*philo geht in anderen philo rein und locked den mutex der Fork*/
/*philo takes the fork from right philo*/
/* have to add time of millis to get_conditions?*/
/*init array of forks for philos in table struct*/