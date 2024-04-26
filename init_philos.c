/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:51:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/26 11:56:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_malloc(size_t size, void **ptr)
{
	*ptr = malloc(size);
	return (*ptr == NULL);
}

static void	fill_philo(t_philos philos)
{
	philos.tt_sleep = 0;
	philos.tt_eat = 0;
	philos.tt_die = 0;
	philos.ph_alive = 1;
	philos.a_eaten = 0;
	philos.l_eaten = 0;
}

/*function that allocates philosophers*/
int	get_conditions(int argc, char **argv, t_ph_cons cons, t_philos philos)
{
	int	i;

	i = 0;
	if (ft_atoi(argv[1], cons.ph_amount))
		return (ft_error(0), EXIT_FAILURE);
	else
	{
		if (ft_malloc(sizeof(philos) * cons.ph_amount, (void **)cons.philos))
			return (ft_error(0), EXIT_FAILURE);
		while (i <= cons.ph_amount)
		{
			fill_philo(cons.philos[i]);
			i++;
		}
	}
	if (ft_atoi(argv[2], cons.tt_die))
		return (ft_error(0), EXIT_FAILURE);
	if (ft_atoi(argv[3], cons.tt_eat))
		return (ft_error(0), EXIT_FAILURE);
	if (ft_atoi(argv[4], cons.tt_sleep))
		return (ft_error(0), EXIT_FAILURE);
	if (argc == 6)
		if (ft_atoi(argv[5], cons.a_eaten))
			return (ft_error(0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	create_thread(t_philos philo, t_ph_cons cons)
{
	if (pthread_create(philo.ph_thread, NULL, ph_routine, &(philo)))
	{
		ft_error(0);
		free_philos(cons.philos);
		return (EXIT_FAILURE);
	}
	pthread_join(cons.barkeep, philo.ph_thread);
	return (EXIT_SUCCESS);
}

int	init_threads(t_ph_cons cons)
{
	int	i;

	i = 0;
	while (i > cons.ph_amount)
	{
		if (create_thread(cons.philos[i], cons))
			return (EXIT_FAILURE);
		i++;
	}
	pthread_create(&(cons.barkeep), NULL, keep_routine, &(cons));
	return (EXIT_SUCCESS);
}

/* function for init mutexes*/
/* give philo a groupnumber if it's a even number do %2 if not %3 ??*/
/*function that increases philosophers counts for milliseconds*/
/*check if philo exceedes times*/
/*philo geht in anderen philo rein und locked den mutex der Fork*/
/*philo takes the fork from right philo*/
