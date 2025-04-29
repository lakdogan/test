/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_back_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:34:47 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 20:22:19 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	pull_back_all(t_data *d)
{
	d->target = d->numcount;
	while (d->target >= 1)
	{
		d->pbacnt = ft_count_current_numcount(d->b, d->numcount);
		if (d->pbacnt == 0)
			break ;
		d->pbaidx = 0;
		while (d->pbaidx < d->pbacnt && d->b[d->top_b + 1
				+ d->pbaidx][RANK] != d->target)
			++d->pbaidx;
		if (d->pbaidx >= d->pbacnt)
			continue ;
		if (d->pbaidx <= d->pbacnt / 2)
			while (d->pbaidx-- > 0)
				rotate_b(d);
		else
		{
			d->pbasteps = d->pbacnt - d->pbaidx;
			while (d->pbasteps-- > 0)
				reverse_rotate_b(d);
		}
		push_a(d);
		--d->target;
	}
}
