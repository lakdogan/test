/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:57:26 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:51:42 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	calibrate_chunks(t_data *data)
{
	double	root;
	int		cnt;

	root = ft_sqrt((double)data->numcount, 1e-6);
	cnt = (int)(root * 0.4 + 0.5);
	if (data->numcount >= 6 && cnt < 2)
		cnt = 2;
	if (cnt < 1)
		cnt = 1;
	data->chunk_count = cnt;
	data->chunk_size = (data->numcount + cnt - 1) / cnt;
}

void	chunk_assign(t_data *data)
{
	data->a[data->i.i][CHUNK] = (data->a[data->i.i][RANK] - 1)
		/ data->chunk_size + 1;
}

// !!!!!!!!!!!!!!!!
// void calibrate_chunks(t_data *d)
// {
//     int n = d->numcount;
//     if (n <= 100)
//         d->chunk_count = 5;
//     else if (n <= 500)
//         d->chunk_count = 9;
//     else if (n <= 1000)
//         d->chunk_count = 20;
//     else
//     {
//         double root = ft_sqrt((double)n, 1e-6);
//         d->chunk_count = (int)(root * 0.5 + 0.5);
//     }
//     if (d->chunk_count < 1)
//         d->chunk_count = 1;
//     d->chunk_size = (n + d->chunk_count - 1) / d->chunk_count;
// }

void	assign_chunk_id(t_data *data)
{
	calibrate_chunks(data);
	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		chunk_assign(data);
		data->i.i++;
	}
}
