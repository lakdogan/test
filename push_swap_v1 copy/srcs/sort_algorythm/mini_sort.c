/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:40:08 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:23:49 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	find_min_index(t_data *d)
{
	int	cnt;
	int	min_i;
	int	min_v;
	int	cur_v;
	int	i;

	cnt = stack_len(d->a, d->top_a, d->numcount);
	min_i = 0;
	min_v = d->a[d->top_a][VALUE];
	i = 1;
	while (i < cnt)
	{
		cur_v = d->a[d->top_a + i][VALUE];
		if (cur_v < min_v)
		{
			min_v = cur_v;
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

void static	perpare_to_push(t_data *d)
{
	if (d->min_pos <= d->half)
		while (d->min_pos-- > 0)
			rotate_a(d);
	else
	{
		d->steps = d->n - d->min_pos;
		while (d->steps-- > 0)
			reverse_rotate_a(d);
	}
}

void	sort_under_seven(t_data *d)
{
	d->n = stack_len(d->a, d->top_a, d->numcount);
	if (d->n < 3)
		return ;
	if (d->n == 3)
	{
		sort_three(d);
		return ;
	}
	d->to_push = d->n - 3;
	while (d->to_push--)
	{
		d->min_pos = find_min_index(d);
		d->half = d->n / 2;
		perpare_to_push(d);
		push_b(d);
		d->n--;
	}
	sort_three(d);
	while (stack_len(d->b, d->top_b + 1, d->numcount))
		push_a(d);
}
