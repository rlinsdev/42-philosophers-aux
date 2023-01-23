/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 10:59:23 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // Printf
# include <stdlib.h> // Malloc
# include <pthread.h> //pthread_

/******************************************************************************/
/*Begin - Initialization*/
/******************************************************************************/
/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @param envp Environment pointer variable
 * @return int
 */
int	init(int argc, char **argv, char **envp);
int	race_cond_1();
int	deadlock();

/******************************************************************************/
/*End - Initialization*/
/******************************************************************************/

#endif
