/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:59:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/19 22:36:53 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	free_int(t_data *data)
{
	free(data->length);
	free(data->previous);
	free(data->sum);
}
