/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:57:12 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/19 22:37:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	allocate_int(t_data *data)
{
	data->length = malloc(sizeof(int) * data->numcount);
	data->sum = malloc(sizeof(int) * data->numcount);
	data->previous = malloc(sizeof(int) * data->numcount);
	if (!data->length || !data->previous || !data->sum)
		exit(EXIT_FAILURE);
}
