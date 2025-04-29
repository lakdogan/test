/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:29:10 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 21:45:20 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"



int first_idx_a(t_data *d)          /* Index des obersten Elements in A */
{
    return d->top_a;                /* top_a zeigt schon auf erstes     */
}
