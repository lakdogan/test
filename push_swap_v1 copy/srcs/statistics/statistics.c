/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:37:12 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/19 21:50:32 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	find_min_value_and_prepare(t_data *data)
{
	init_itterators(data);
	data->min_num = INT_MAX;
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i][RANKED] == FALSE)
		{
			if (data->a[data->i.i][VALUE] <= data->min_num)
			{
				data->min_num = data->a[data->i.i][VALUE];
				data->a[data->min_num_index][data->ranked] = FALSE;
				data->min_num_index = data->i.i;
				data->a[data->i.i][data->ranked] = TRUE;
			}
		}
		data->i.i++;
	}
	data->a[data->min_num_index][RANKED] = TRUE;
}
