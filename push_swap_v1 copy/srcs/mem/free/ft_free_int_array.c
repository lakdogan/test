/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:30:14 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:59:52 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees a dynamically allocated array of integer pointers.
 *
 * Iterates over the array, freeing each element using 
 * ft_del_int_value and then frees the array itself.
 *
 * @param array Pointer to the array of integer pointers to free.
 * @param size The number of elements in the array.
 */
void	ft_free_int_array(int **array, int size)
{
	int	index;

	index = 0;
	if (array)
	{
		while (index < size)
		{
			ft_del_int_value(array, index);
			index++;
		}
		free(array);
	}
}
