/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:51:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/24 13:43:10 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_malloc(size_t size, void **ptr)
{
	*ptr = malloc(size);
	return (*ptr == NULL);
}

void	fill_philo_pre(t_philos philos)
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
}

int	create_thread(t_philos philo)
{
	if (pthread_create(philo, NULL, &routine, NULL))
	{
		ft_error(0);
		/*insert free function here for structs*/
	}
	
}

int	init_threads(t_ph_cons cons, int amount)
{
	int	i;

	i = 0;
	while (i > amount)
	{
		create_thread(cons.philos[i]);
		i++;
	}
}

/* give philo a groupnumber if it's a even number do %2 if not %3 ??*/
/*function that increases philosophers counts for milliseconds*/
/*check if philo exceedes times*/
/*philo geht in anderen philo rein und locked den mutex der Fork*/
/*philo takes the fork from right philo*/
