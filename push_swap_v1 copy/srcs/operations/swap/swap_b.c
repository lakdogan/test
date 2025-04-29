/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:19:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 22:10:18 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	swap_b(t_data *data)
{
	if (data->b[data->top_b + 1] == NULL || data->b[data->top_b + 2] == NULL)
		return ;
	data->temp_value = data->b[data->top_b + 1][VALUE];
	data->b[data->top_b + 1][VALUE] = data->b[data->top_b + 2][VALUE];
	data->b[data->top_b + 2][VALUE] = data->temp_value;
	data->temp_rank = data->b[data->top_b + 1][RANK];
	data->b[data->top_b + 1][RANK] = data->b[data->top_b + 2][RANK];
	data->b[data->top_b + 2][RANK] = data->temp_rank;
	check_flag_print_op(data, "sb");
}
