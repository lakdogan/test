/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:40:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/27 21:53:55 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

/**
 * @brief Frees the memory allocated for the numbers array.
 *
 * This function checks if the numbers array stored in 
 * @p data->nums exists,
 * and if so, frees it using ft_free_string.
 *
 * @param data Pointer to the t_data structure containing 
 * the numbers string array.
 */
void	free_nums(t_data *data)
{
	if (!data->nums)
		ft_free_string(data->nums);
}

/**
 * @brief Frees the memory allocated for both stacks.
 *
 * This function releases the memory allocated 
 * for the integer arrays @p data->a and
 * @p data->b, which represent the stacks, 
 * by calling ft_free_int_array on each with the
 * total number of elements given by @p data->numcount.
 *
 * @param data Pointer to the t_data structure 
 * containing the stacks.
 */
void	free_stacks(t_data *data)
{
	ft_free_int_array(data->a, data->numcount);
	ft_free_int_array(data->b, data->numcount);
}

/**
 * @brief Frees all allocated resources.
 *
 * This function consolidates the freeing process by 
 * calling both @p free_nums and
 * @p free_stacks to ensure that all dynamically 
 * allocated memory associated with the
 * numbers array and the stacks is properly released.
 *
 * @param data Pointer to the t_data structure containing 
 * all allocated resources.
 */
void	free_all(t_data *data)
{
	free_nums(data);
	free_stacks(data);
}
