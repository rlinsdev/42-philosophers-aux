/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 10:07:03 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @param envp Environment variables
 * @return int
 */
int	main(int argc, char **argv, char **envp)
{
	int result = race_cond_1();
	return (result);
}
