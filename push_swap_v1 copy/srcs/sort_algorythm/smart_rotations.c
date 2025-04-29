/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:19:17 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 21:19:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Führt gleichzeitig ra / rb (bzw. rra / rrb) aus,
** wann immer möglich (rr / rrr), um Befehle zu sparen.
*/

void	smart_rotate(t_data *d, int ra, int rb)
{
	if (ra < 0)
		ra = 0;
	if (rb < 0)
		rb = 0;
	while (ra && rb)
	{
		rotate_both(d);
		--ra;
		--rb;
	}
	while (ra--)
		rotate_a(d);
	while (rb--)
		rotate_b(d);
}

void	smart_reverse_rotate(t_data *d, int rra, int rrb)
{
	if (rra < 0)
		rra = 0;
	if (rrb < 0)
		rrb = 0;
	while (rra && rrb)
	{
		reverse_rotate_both(d);
		--rra;
		--rrb;
	}
	while (rra--)
		reverse_rotate_a(d);
	while (rrb--)
		reverse_rotate_b(d);
}


