/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/04/03 14:31:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_ph_cond
{
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_amount;
	int				a_eaten;
	int				gt_eat;
	unsigned int	l_eaten;
}

typedef struct s_philos
{
	int				tt_sleep;
	int				tt_eat;
	int				tt_die;
	int				ph_amount;
	int				a_eaten;
	int				gt_eat;
	unsigned int	l_eaten;
} t_ph_cons

#endif