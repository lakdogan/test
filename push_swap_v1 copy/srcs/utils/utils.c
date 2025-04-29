/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:27 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 21:38:09 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"


int	ft_max(int a,int b){ return (a > b ? a : b); }
int	ft_min(int a,int b){ return (a < b ? a : b); }
int	first_idx_b(t_data *d){ return (d->top_b + 1); } /* -1 wenn leer? */

