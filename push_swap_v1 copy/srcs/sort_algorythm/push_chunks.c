/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:08:07 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:46:02 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

int	dist_top_range(t_data *d, int low, int high)
{
	int	count;
	int	r;
	int	i;

	count = ft_count_current_numcount(d->a, d->numcount);
	i = 0;
	while (i < count)
	{
		r = d->a[d->top_a + i][RANK];
		if (r >= low && r <= high)
			return (i);
		++i;
	}
	return (-1);
}

int	dist_bot_range(t_data *d, int low, int high)
{
	int	count;
	int	r;
	int	i;

	count = ft_count_current_numcount(d->a, d->numcount);
	i = count - 1;
	while (i >= 0)
	{
		r = d->a[d->top_a + i][RANK];
		if (r >= low && r <= high)
			return (count - i);
		--i;
	}
	return (-1);
}

int	calculate_fwd(t_data *d)
{
	return (d->fwd = dist_top_range(d, d->low, d->high));
}

void	push_chunks(t_data *d)
{
	calibrate_chunks(d);
	d->i.m = 0;
	while (d->i.m < d->chunk_count)
	{
		d->low = d->i.m * d->chunk_size + 1;
		d->high = (d->i.m + 1) * d->chunk_size;
		if (d->high > d->numcount)
			d->high = d->numcount;
		d->mid = (d->low + d->high) / 2;
		while (calculate_fwd(d) >= 0)
		{
			d->bwd = dist_bot_range(d, d->low, d->high);
			if (d->bwd >= 0 && d->fwd > d->bwd)
				while (d->bwd-- > 0)
					reverse_rotate_a(d);
			else
				while (d->fwd-- > 0)
					rotate_a(d);
			push_b(d);
			if (d->b[d->top_b + 1][RANK] <= d->mid
				&& ft_count_current_numcount(d->b, d->numcount) > 4)
				rotate_b(d);
		}
		d->i.m++;
	}
}
