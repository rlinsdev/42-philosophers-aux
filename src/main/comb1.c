/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:49:57 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 18:21:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

# define NC		"\e[0m"
# define YELLOW	"\e[1;33m"

static void *thread_routine(void *data);

int	comb1()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, NULL, &thread_routine, NULL);
	printf("Created first thread[%ld]\n", tid1);

	pthread_create(&tid2, NULL, &thread_routine, NULL);
	printf("Created first thread[%ld]\n", tid2);

	pthread_join(tid1, NULL);
	printf("Join first thread[%ld]\n", tid1);

	pthread_join(tid2, NULL);
	printf("Join first thread[%ld]\n", tid2);

	return (0);
}


static void *thread_routine(void *data)
{
	pthread_t tid;

	tid = pthread_self();
	printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n",
		YELLOW, tid, NC);

	return (NULL);
}
