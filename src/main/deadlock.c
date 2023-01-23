/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:58:27 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 11:05:16 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define THREAD_NUMB 8

void	*routine(void *args) {
}

int	deadlock()
{
	pthread_t th[THREAD_NUMB];

	int i;
	for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to create a thread");
		}
	}

		for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_join(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to join a thread");
		}
	}

	return (0);
}
