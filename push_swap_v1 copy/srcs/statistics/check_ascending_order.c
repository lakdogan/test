/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ascending_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:53:54 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:55:05 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	initialize_lis_arrays(t_data *data)
{
	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		data->length[data->i.i] = 1;
		data->sum[data->i.i] = data->a[data->i.i][RANK];
		data->previous[data->i.i] = -1;
		data->i.i++;
	}
	data->max_len = 1;
	data->max_sum = data->sum[0];
	data->max_len_idx = 0;
}

void	compare_rank_and_length_asc(t_data *data)
{
	if (data->a[data->i.j][RANK] < data->a[data->i.i][RANK]
		&& data->length[data->i.j] + 1 > data->length[data->i.i])
	{
		data->length[data->i.i] = data->length[data->i.j] + 1;
		data->sum[data->i.i] = data->sum[data->i.j] + data->a[data->i.i][RANK];
		data->previous[data->i.i] = data->i.j;
	}
	else if (data->a[data->i.j][RANK] < data->a[data->i.i][RANK]
		&& data->length[data->i.j] + 1 == data->length[data->i.i]
		&& data->sum[data->i.j]
		+ data->a[data->i.i][RANK] > data->sum[data->i.i])
	{
		data->sum[data->i.i] = data->sum[data->i.j] + data->a[data->i.i][RANK];
		data->previous[data->i.i] = data->i.j;
	}
}

void	compare_and_update_statistics_asc(t_data *data)
{
	if (data->length[data->i.i] > data->max_len
		|| (data->length[data->i.i] == data->max_len
			&& data->sum[data->i.i] > data->max_sum))
	{
		data->max_len = data->length[data->i.i];
		data->max_sum = data->sum[data->i.i];
		data->max_len_idx = data->i.i;
	}
}

void	set_asc_flag(t_data *data)
{
	data->i.i = 0;
	while (data->i.i < data->numcount)
	{
		data->a[data->i.i][IN_ORDER_ASC] = FALSE;
		data->i.i++;
	}
	data->i.i = data->max_len_idx;
	while (data->i.i != -1)
	{
		data->a[data->i.i][IN_ORDER_ASC] = TRUE;
		data->i.i = data->previous[data->i.i];
	}
}

void	check_ascending_order(t_data *data)
{
	allocate_int(data);
	initialize_lis_arrays(data);
	data->i.i = 1;
	while (data->i.i < data->numcount)
	{
		data->i.j = 0;
		while (data->i.j < data->i.i)
		{
			compare_rank_and_length_asc(data);
			data->i.j++;
		}
		compare_and_update_statistics_asc(data);
		data->i.i++;
	}
	set_asc_flag(data);
	free_int(data);
	data->len_out = data->max_len;
	data->sum_out = data->max_sum;
	ft_printf("Optimized LIS: %d Numbers (data->sum %d)\n", data->max_len,
		data->max_sum);
}
