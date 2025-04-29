/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:01:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:55:54 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	set_all_ranked_to_false(t_data *data)
{
	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		data->a[data->i.i][data->ranked] = FALSE;
		data->i.i++;
	}
}

void	rank_transformation(t_data *data)
{
	int	i;

	set_all_ranked_to_false(data);
	data->current_min_rank = 1;
	data->ranked_count = 0;
	i = 0;
	while (i < data->numcount)
	{
		find_min_value_and_prepare(data);
		data->a[data->min_num_index][RANK] = data->current_min_rank;
		data->a[data->min_num_index][RANKED] = TRUE;
		data->current_min_rank++;
		data->ranked_count++;
		data->min_num = data->a[data->min_num_index][VALUE] + 1;
		++i;
	}
}
