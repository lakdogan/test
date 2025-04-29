/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:32:10 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/18 15:34:19 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * ft_sqrt
 * --------
 * Computes the square root of a non‑negative double using
 * the Newton–Raphson iteration, implemented with a while‑loop.
 *
 * x       : the value to take the square root of (must be ≥ 0).
 * epsilon : desired precision (e.g. 1e‑6).
 *
 * Returns the approximated square root, or –1.0 if x < 0.
 */
double	ft_sqrt(double x, double epsilon)
{
	double	guess;
	double	next;
	double	diff;

	if (x < 0.0)
		return (-1.0);
	if (x == 0.0 || x == 1.0)
		return (x);
	if (x < 1.0)
		guess = 1.0;
	else
		guess = x / 2.0;
	next = 0.5 * (guess + x / guess);
	diff = next - guess;
	if (diff < 0.0)
		diff = -diff;
	while (diff > epsilon)
	{
		guess = next;
		next = 0.5 * (guess + x / guess);
		diff = next - guess;
		if (diff < 0.0)
			diff = -diff;
	}
	return (next);
}
