/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:49:57 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 18:36:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define TIMES_TO_COUNT 21000

#define NC		"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"

static void *thread_routine(void *data);

int	comb1()
{
	pthread_t tid1;
	pthread_t tid2;

	unsigned int count = 0;

	printf("Main: Expected count is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);

	pthread_create(&tid1, NULL, thread_routine, &count);
	printf("Created first thread[%ld]\n", tid1);

	pthread_create(&tid2, NULL, thread_routine, &count);
	printf("Created first thread[%ld]\n", tid2);

	pthread_join(tid1, NULL);
	printf("Join first thread[%ld]\n", tid1);

	pthread_join(tid2, NULL);
	printf("Join first thread[%ld]\n", tid2);

	if (count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERROR ! Total count is %u%s\n", RED, count, NC);
	else
		printf("%sMain: OK. Total count is %u%s\n", GREEN, count, NC);

	return (0);
}


static void *thread_routine(void *data)
{
	pthread_t tid;
	unsigned int *count;
	unsigned int i = 0;

	tid = pthread_self();
	count = (unsigned int *)data;
	
	// Print the count before this thread starts iterating:
	printf("%sThread [%ld]: Count at thread start = %u.%s\n",
		YELLOW, tid, *count, NC);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		(*count)++;
		i++;
	}
	printf("%sThread [%ld]: Final count = %u.%s\n",
		BYELLOW, tid, *count, NC);
	return (NULL); // Thread ends here.
}
