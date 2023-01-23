/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_cond_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:38:38 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 10:22:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int mails = 0;

void	*routine() {
	// for (int i = 0; i < 1000000; i++) {
	for (int i = 0; i < 100; i++) {
		mails++;
	}
}

int	race_cond_1()
{
	pthread_t p1, p2;

	if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
		return (1);
	}
	if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
		return (2);
	}
	if (pthread_join(p1, NULL) != 0) {
		return (3);
	}
	if (pthread_join(p2, NULL) != 0) {
		return (4);
	}
	// printf("oi\n");
	printf("Number of mails: %d\n", mails);
	return (0);
}
