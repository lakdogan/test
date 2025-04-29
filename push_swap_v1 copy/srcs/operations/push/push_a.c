/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 21:35:03 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	push_a(t_data *data)
{
	if (data->top_a == 0 || data->top_b == data->numcount - 1)
		return ;
	ft_set_int_value(data->a, data->top_a - 1, data->b[data->top_b + 1][VALUE],
		data->b[data->top_b + 1][RANK]);
	ft_del_int_value(data->b, data->top_b + 1);
	data->top_a--;
	data->top_b++;
	data->operation_count++;
	ft_putendl_fd("pa", 1);
}
