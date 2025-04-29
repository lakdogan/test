/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:07:00 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 18:03:04 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_data *d)
{
	if (d->a[d->top_a][0] > d->a[d->top_a + 1][0])
		rotate_a(d);
}

void	sort_three(t_data *d)
{
	int	b;
	int	x;
	int	y;
	int	z;

	b = d->top_a;
	x = d->a[b][RANK];
	y = d->a[b + 1][RANK];
	z = d->a[b + 2][RANK];
	if (x > y && y < z && x < z)
		swap_a(d);
	else if (x > y && y > z)
	{
		swap_a(d);
		reverse_rotate_a(d);
	}
	else if (x > y && y < z && x > z)
		rotate_a(d);
	else if (x < y && y > z && x < z)
	{
		swap_a(d);
		rotate_a(d);
	}
	else if (x < y && y > z && x > z)
		reverse_rotate_a(d);
}
