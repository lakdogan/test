/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_back_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:34:47 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 23:04:55 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/* ------------------------------------------------------------------
   In A bleibt (L)IS – der Rest wird nach B gedrückt
   ------------------------------------------------------------------ */
void	sort_optimal(t_data *d)
{
    int	i;
    int	lds_len;
    int	use_lis;
    int	lis_len;
    static int asc_store[1000]; /* 1000 > numcount */

    /* ---------- 1. Flags berechnen ---------- */
    check_ascending_order(d); /* setzt IN_ORDER_ASC   */
    lis_len = d->len_out;       /* merkt LIS-Länge      */
    /* Zwischenspeichern der Ascending-Flags */
    i = 0;
    while (i < d->numcount)
    {
        asc_store[i] = d->a[i][IN_ORDER_ASC];
        ++i;
    }
    check_descending_order(d); /* setzt IN_ORDER_DES   */
    lds_len = d->len_out;
    /* ---------- 2. Besseres Muster auswählen ---------- */
    use_lis = (lis_len >= lds_len) ? d->true : d->false;
    i = 0;
    while (i < d->numcount)
    {
        if (use_lis)
            d->a[i][IN_ORDER_ASC] = asc_store[i];
        else
            d->a[i][IN_ORDER_ASC] = d->a[i][IN_ORDER_DES];
        ++i;
    }
    /* ---------- 3. Nicht-(L)IS nach B schieben ---------- */
    while (ft_count_current_numcount(d->a, d->numcount) > lis_len)
    {
        if (d->a[d->top_a][IN_ORDER_ASC] == d->true)
            rotate_a(d);
        else
            push_b(d);
    }
    /* ---------- 4. Alles aus B geordnet zurück ---------- */
}

/* ------------------------------------------------------------------
   Hilfs-Funktion: Bestimme Position in A, wo 'rank' eingefügt wird.
   Indexierung wird als zyklisch betrachtet.
   ------------------------------------------------------------------ */
static int	place_in_a(t_data *d, int rank)
{
    int	len;
    int	base;
    int	min_r, max_r;
    int	min_i, max_i;
    int	r;
    int	cur;
    int	nxt;

    len = ft_count_current_numcount(d->a, d->numcount);
    base = d->top_a;
    min_r = d->a[base][RANK];
    max_r = min_r;
    min_i = 0;
    max_i = 0;
    for (int i = 1; i < len; ++i)
    {
        r = d->a[(base + i) % d->numcount][RANK];
        if (r < min_r)
        {
            min_r = r;
            min_i = i;
        }
        if (r > max_r)
        {
            max_r = r;
            max_i = i;
        }
    }
    /* 1) Wrap-around Fälle */
    if (rank < min_r)
        return (min_i);
    if (rank > max_r)
        return ((max_i + 1) % len);
    /* 2) Normale Lücke */
    for (int i = 0; i < len - 1; ++i)
    {
        cur = d->a[(base + i) % d->numcount][RANK];
        nxt = d->a[(base + i + 1) % d->numcount][RANK];
        if (cur < rank && rank < nxt)
            return (i + 1);
    }
    /* 3) Fallback */
    return (len);
}

/* ------------------------------------------------------------------
   Kosten für EIN Element oben in B berechnen – eval_move
   ------------------------------------------------------------------ */
typedef struct s_move
{
    int	ra, rb, rra, rrb, cost;
}			t_move;

static void	eval_move(t_data *d, int idx_in_b, t_move *m)
{
    int	len_b;
    int	len_a;
    int	rank;
    int	pos_a;
    int	v1, v2, v3, v4;

    len_b = ft_count_current_numcount(d->b, d->numcount);
    len_a = ft_count_current_numcount(d->a, d->numcount);
    rank = d->b[(first_idx_b(d) + idx_in_b) % d->numcount][RANK];
    /* Rotationen in B */
    m->rb = idx_in_b;
    m->rrb = len_b - idx_in_b;
    /* Einfüge-Position in A */
    pos_a = place_in_a(d, rank);
    m->ra = pos_a;
    m->rra = len_a - pos_a;
    /* Vergleiche verschiedene Kombinationen */
    v1 = ft_max(m->ra, m->rb);
    v2 = ft_max(m->rra, m->rrb);
    v3 = m->ra + m->rrb;
    v4 = m->rra + m->rb;
    m->cost = ft_min(ft_min(v1, v2), ft_min(v3, v4));
}

/* ------------------------------------------------------------------
   Günstigstes Element aus B in A einfügen – apply_move
   ------------------------------------------------------------------ */
static void	apply_move(t_data *d, t_move m)
{
    if (m.cost == ft_max(m.ra, m.rb))
        smart_rotate(d, m.ra, m.rb);
    else if (m.cost == ft_max(m.rra, m.rrb))
        smart_reverse_rotate(d, m.rra, m.rrb);
    else if (m.cost == m.ra + m.rrb)
    {
        smart_rotate(d, m.ra, 0);
        smart_reverse_rotate(d, 0, m.rrb);
    }
    else
    {
        smart_reverse_rotate(d, m.rra, 0);
        smart_rotate(d, 0, m.rb);
    }
    push_a(d);
}

/* ------------------------------------------------------------------
   Greedy merge: Elemente von B werden eins nach dem anderen korrekt in A eingefügt.
   Die Rotationen in B erfolgen explizit.
   ------------------------------------------------------------------ */
void	greedy_merge(t_data *d)
{
    int		len_b;
    int		best_idx;
    int		i, k;
    t_move	best_move, cur;

    while (ft_count_current_numcount(d->b, d->numcount) > 0)
    {
        len_b = ft_count_current_numcount(d->b, d->numcount);
        best_idx = 0;
        eval_move(d, 0, &best_move);
        for (i = 1; i < len_b; ++i)
        {
            eval_move(d, i, &cur);
            if (cur.cost < best_move.cost)
            {
                best_move = cur;
                best_idx = i;
            }
        }
        /* Rotationen in B: best_idx-mal im günstigsten Weg */
        if (best_idx <= len_b / 2)
        {
            for (i = 0; i < best_idx; i++)
                rotate_b(d);
        }
        else
        {
            k = len_b - best_idx;
            for (i = 0; i < k; i++)
                reverse_rotate_b(d);
        }
        apply_move(d, best_move);
    }
    if (!check_for_sorted(d))
        rotate_sorted_stack(d);
    rotate_min_to_top(d);
}

/* ------------------------------------------------------------------
   Dreht A so, dass das Minimum (kleinstes RANK) oben ist.
   ------------------------------------------------------------------ */
void	rotate_min_to_top(t_data *d)
{
    int	len;
    int	idx;
    int	k;
    int	base;

    len = ft_count_current_numcount(d->a, d->numcount);
    base = d->top_a;
    idx = 0;
    /* Suche nach dem Element mit RANK == 1 */
    while (idx < len && d->a[(base + idx) % d->numcount][RANK] != 1)
        ++idx;
    if (idx == len)
        return ;
    /* Wähle die kostengünstige Richtung zum Rotieren */
    if (idx <= len / 2)
    {
        for (int i = 0; i < idx; i++)
            rotate_a(d);
    }
    else
    {
        k = len - idx;
        for (int i = 0; i < k; i++)
            reverse_rotate_a(d);
    }
}
