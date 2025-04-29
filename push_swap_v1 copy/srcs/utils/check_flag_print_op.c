/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_print_op.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:31:50 by lakdogan          #+#    #+#             */
/*   Updated: 2025/03/15 22:05:45 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	check_flag_print_op(t_data *data, char *op)
{
	if (data->rra_rrb_flag == 0 && data->ra_rb_flag == 0
		&& data->sa_sb_flag == 0)
	{
		data->operation_count++;
		ft_putendl_fd(op, 1);
	}
}
