/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:19:32 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 22:09:25 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	swap_a(t_data *data)
{
	if (data->a[data->top_a] == NULL || data->a[data->top_a + 1] == NULL)
		return ;
	data->temp_value = data->a[data->top_a][VALUE];
	data->a[data->top_a][VALUE] = data->a[data->top_a + 1][VALUE];
	data->a[data->top_a + 1][VALUE] = data->temp_value;
	data->temp_rank = data->a[data->top_a][RANK];
	data->a[data->top_a][RANK] = data->a[data->top_a + 1][RANK];
	data->a[data->top_a + 1][RANK] = data->temp_rank;
	check_flag_print_op(data, "sa");
}
