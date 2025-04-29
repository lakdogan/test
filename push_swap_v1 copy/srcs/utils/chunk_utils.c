/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:57:26 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 20:54:42 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

void	calibrate_chunks(t_data *data)
{
	double	root;
	int		cnt;

	root = ft_sqrt((double)data->numcount, 1e-6);
	cnt = (int)(root * 0.4 + 0.5);
	if (data->numcount >= 6 && cnt < 2)
		cnt = 2;
	if (cnt < 1)
		cnt = 1;
	data->chunk_count = cnt;
	data->chunk_size = (data->numcount + cnt - 1) / cnt;
}

void	chunk_assign(t_data *data)
{
	data->a[data->i.i][CHUNK] = (data->a[data->i.i][RANK] - 1)
		/ data->chunk_size + 1;
}

// !!!!!!!!!!!!!!!!
// void calibrate_chunks(t_data *d)
// {
//     int n = d->numcount;
//     if (n <= 100)
//         d->chunk_count = 5;
//     else if (n <= 500)
//         d->chunk_count = 9;
//     else if (n <= 1000)
//         d->chunk_count = 20;
//     else
//     {
//         double root = ft_sqrt((double)n, 1e-6);
//         d->chunk_count = (int)(root * 0.5 + 0.5);
//     }
//     if (d->chunk_count < 1)
//         d->chunk_count = 1;
//     d->chunk_size = (n + d->chunk_count - 1) / d->chunk_count;
// }



/* ============================================================ */
/*  helpers                                                     */
/* ============================================================ */
static int stack_len_A(t_data *d)
{
    /* nur die aktuell belegten Felder in A zählen */
    return ft_count_current_numcount(d->a, d->numcount);
}

/* ============================================================ */
/*  find_chunk_size – jetzt mit realer Rest-Länge               */
/* ============================================================ */
void    find_chunk_size(t_data *d)
{
    int cur = stack_len_A(d);        /* *** NEU *** */
    double root = ft_sqrt((double)cur, 1e-6);
    int    cnt  = (int)(root * 0.4 + 0.5);

    if (cur >= 6 && cnt < 2) cnt = 2;
    if (cnt < 1) cnt = 1;

    d->chunk_count = cnt;
    d->chunk_size  = (cur + cnt - 1) / cnt;   /* ceiling-division */
}

/* ============================================================ */
/*  assign_chunk_id – nur echte Elemente markieren              */
/* ============================================================ */
void    assign_chunk_id(t_data *d)
{
    find_chunk_size(d);              /* nutzt jetzt die neue cur-Lenge */

    int cur = stack_len_A(d);        /* Elemente, die noch in A sind   */
    int base = d->top_a;             /* Start-Index                    */

    for (int i = 0; i < cur; ++i)
    {
        int idx   = base + i;
        int rank  = d->a[idx][RANK];
        if (d->a[idx] == NULL)       /* NULL-Sicherheit                */
            continue;
        d->a[idx][CHUNK] = (rank - 1) / d->chunk_size + 1;
    }
}