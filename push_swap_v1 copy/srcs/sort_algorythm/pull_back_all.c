/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_back_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:34:47 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 20:34:39 by lakdogan         ###   ########.fr       */
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

void sort_optimal(t_data *data)
{
    int i;
    int lis, lds;
    int use_lis;
    int total;
    int len_a, len_b;
    int *asc_flags;
    int guard;

	init_top_b(data);

    // Initialer Status
    len_a = ft_count_current_numcount(data->a, data->numcount);
    len_b = ft_count_current_numcount(data->b, data->numcount);
    fprintf(stderr, "[DEBUG] Enter sort_optimal_debug: top_a=%d, top_b=%d, lenA=%d, lenB=%d\n",
            data->top_a, data->top_b, len_a, len_b);

    // 1) ASC-Flags
    check_ascending_order(data);
    lis = data->len_out;
    fprintf(stderr, "[DEBUG] LIS length = %d\n", lis);

    // Speicher ASC-Flags
    asc_flags = malloc(len_a * sizeof(int));
    for (i = 0; i < len_a; ++i) {
        asc_flags[i] = data->a[data->top_a + i][IN_ORDER_ASC];
        fprintf(stderr, "[DEBUG] asc_flags[%d]=%d (rank=%d)\n", i,
                asc_flags[i], data->a[data->top_a + i][RANK]);
    }

    // 1b) LDS-Flags
    check_descending_order(data);
    lds = data->len_out;
    fprintf(stderr, "[DEBUG] LDS length = %d\n", lds);

    // 2) Wahl
    use_lis = (lis >= lds ? data->true : data->false);
    fprintf(stderr, "[DEBUG] use_lis = %d\n", use_lis);

    // 2b) Finale Flags setzen
    for (i = 0; i < len_a; ++i) {
        if (use_lis == data->true)
            data->a[data->top_a + i][IN_ORDER_ASC] = asc_flags[i];
        else
            data->a[data->top_a + i][IN_ORDER_ASC] =
                data->a[data->top_a + i][IN_ORDER_DES];
        fprintf(stderr, "[DEBUG] final flag[%d]=%d\n", i,
                data->a[data->top_a + i][IN_ORDER_ASC]);
    }
    free(asc_flags);

	init_top_b(data);
    // 3) Push non-(L)IS nach B mit Guard
    total = ft_count_current_numcount(data->a, data->numcount);
    fprintf(stderr, "[DEBUG] push phase: total=%d\n", total);
    guard = total + 5;
    i = 0;
    while (i < total && guard-- > 0) {
        int flag = data->a[data->top_a][IN_ORDER_ASC];
        int val  = data->a[data->top_a][VALUE];
        fprintf(stderr, "[DEBUG] iter %d: top_a=%d flag=%d val=%d guard=%d\n",
                i, data->top_a, flag, val, guard);
        if (flag == data->true) {
            fprintf(stderr, "[DEBUG] -> rotate_a\n");
            rotate_a(data);
        } else {
            fprintf(stderr, "[DEBUG] -> push_b (rank=%d)\n", data->b[data->top_b+1][RANK]);
            push_b(data);
        }
        i++;
    }
    if (guard <= 0)
        fprintf(stderr, "[DEBUG] push phase guard exhausted\n");

    // 4) Pull-Phase debug
    len_b = ft_count_current_numcount(data->b, data->numcount);
    fprintf(stderr, "[DEBUG] pull phase start: lenB=%d\n", len_b);
    guard = len_b * 2 + 5;
    while (ft_count_current_numcount(data->b, data->numcount) > 0 && guard-- > 0) {
        int cnt = ft_count_current_numcount(data->b, data->numcount);
        int target = data->numcount;
        int idx = 0;
        // Suche nächstes
        while (idx < cnt && data->b[data->top_b+1+idx][RANK] != target)
            ++idx;
        fprintf(stderr, "[DEBUG] pull loop: cnt=%d idx=%d guard=%d\n",
                cnt, idx, guard);
        if (idx >= cnt) {
            fprintf(stderr, "[DEBUG] pull: target not at top, decrement target\n");
            target--;
            continue;
        }
        if (idx <= cnt/2) {
            fprintf(stderr, "[DEBUG] rotate_b %d times\n", idx);
            while (idx-- > 0) rotate_b(data);
        } else {
            int steps = cnt - idx;
            fprintf(stderr, "[DEBUG] reverse_rotate_b %d times\n", steps);
            while (steps-- > 0) reverse_rotate_b(data);
        }
        fprintf(stderr, "[DEBUG] push_a (target)\n");
        push_a(data);
    }
    if (guard <= 0)
        fprintf(stderr, "[DEBUG] pull phase guard exhausted\n");

    fprintf(stderr, "[DEBUG] exit sort_optimal_debug: top_a=%d top_b=%d\n",
            data->top_a, data->top_b);
}


