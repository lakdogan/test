/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:10:31 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 21:44:29 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ---------- kleine Hilfsfunktionen --------------------------------------- */
int	ft_max(int a, int b);
int	ft_min(int a, int b);

/* ---------- Vorwärtsdeklaration für t_data, damit kein Voll-Include nötig ist */
typedef struct s_data	t_data;   /* nur bekannt geben, noch nicht definieren */
int	first_idx_b(t_data *d);

#endif /* UTILS_H */
