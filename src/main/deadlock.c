/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:58:27 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 11:14:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define THREAD_NUMB 8

pthread_mutex_t mutexFuel;
int fuel = 50;

static void	*routine(void *args) {
	pthread_mutex_lock(&mutexFuel);
	fuel += 50;
	printf("Increment fuel to: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
}

int	deadlock()
{
	pthread_t th[THREAD_NUMB];

	pthread_mutex_init(&mutexFuel, NULL);
	int i;
	for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to create a thread");
		}
	}

		for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join a thread");
		}
	}
	printf("Fuel: %d\n", fuel);
	pthread_mutex_destroy(&mutexFuel);

	return (0);
}
