/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_current_numcount.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 01:59:01 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:52:15 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

int	ft_count_current_numcount(int **array, int initial_numcount)
{
	int	current_numcount;
	int	index;

	current_numcount = 0;
	index = 0;
	while (index < initial_numcount)
	{
		if (array[index] != NULL)
			current_numcount++;
		index++;
	}
	return (current_numcount);
}

int	stack_len(int **array, int base, int max)
{
	int	n;

	n = 0;
	while (base + n < max && array[base + n] != NULL)
		++n;
	return (n);
}
