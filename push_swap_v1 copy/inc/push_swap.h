/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:52:27 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 20:55:02 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"

#define FALSE 0
#define TRUE 1

#define VALUE 0
#define RANK 1
#define RANKED 2
#define CHUNK 3
#define IN_ORDER_ASC 4
#define IN_ORDER_DES 5

#define ASCENDING 5
#define DESCENDING 6
#define CHUNK_B 2
#define CHUNK_A 1
#define NEXT 1
#define FIRSTNUM 0

#define CHUNK_A 1
#define CHUNK_B 2
#define CHUNK_C 3
#define CHUNK_D 4
#define CHUNK_E 5
#define CHUNK_F 6
#define CHUNK_G 7
#define CHUNK_H 8
#define CHUNK_I 9
#define CHUNK_J 10
#define CHUNK_K 11
#define CHUNK_L 12
#define CHUNK_M 13
#define CHUNK_N 14
#define CHUNK_O 15
#define CHUNK_P 16
#define CHUNK_Q 17
#define CHUNK_R 18
#define CHUNK_S 19
#define CHUNK_T 20

#define NORMAL 0
#define REVERSE 1

typedef struct s_v
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
}			t_v;

typedef struct s_data
{
	int		**a;
	int		**b;
	int		argc;
	int		numcount;
	char	**nums;
	int		top_a;
	int		top_b;
	int		bot_a;
	int		bot_b;
	int		sa_sb_flag;
	int		ra_rb_flag;
	int		rra_rrb_flag;
	int		operation_count;
	int		moves;
	int		compare;
	int		min_num;
	int		max_num;
	int		sorted_flag;
	int		min_num_index;
	int		max_num_index;
	int		rank;
	int		next_min_num;
	int		next_max_num;
	int		ranked;
	int		value;
	int		true;
	int		false;
	int		current_min_rank;
	int		current_max_rank;
	int		ranked_count;
	int		values_are_not_ranked;
	int		temp_value;
	int		temp_rank;
	int		data_current_numcount;
	int		chunk_b;
	int		chunk_a;
	int		percent_chunk;
	int		out_of_order_count;

	int		*length;
	int		*sum;
	int		*previous;
	int		max_len;
	int		max_sum;
	int		max_len_idx;

	int		len_out;
	int		sum_out;

	int		chunk_count;
	int		chunk_size;


	int		cost_a;
	int		cost_b;
	int		matches;
	int		rotate_direction;

	int	low;
	int	high;
	int	mid;
	int fwd;
	int	bwd;

	int	n;
	int	to_push;
	int	min_pos;
	int	half;
	int	steps;

	int target;

	int	pbacnt;
	int	pbaidx;
	int	pbasteps;

	t_v		i;
}			t_data;

int			main(int argc, char **argv);
void		validate_input(int argc, char **argv, t_data *data);
void		error_memory_allocation(t_data *data);

void		init_itterators(t_data *data);
void		initialization_structs(t_data *data, int argc);
void		ft_free_string(char **string);
void		split_numbers_by_one_argv(t_data *data, char **argv, int argc);

int			ft_isspace(unsigned char c);
long long	ft_strtoll(const char *str, char **endptr, int base);
void		validate_unique_numbers(t_data *data);
void		error(char *msg);
int			**ft_allocate_int_array(int size);
void		ft_del_int_value(int **array, int index);
int			ft_set_int_value(int **array, int index, int value, int rank);
void		allocate_a_and_b(t_data *data);

void		free_all(t_data *data);
void		ft_free_int_array(int **array, int size);
void		init_top_b(t_data *data);

// Operations
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		swap_both(t_data *data);

void		push_b(t_data *data);
void		push_a(t_data *data);

void		rotate_a(t_data *data);
void		rotate_b(t_data *data);
void		rotate_both(t_data *data);

void		reverse_rotate_a(t_data *data);
void		reverse_rotate_b(t_data *data);
void		reverse_rotate_both(t_data *data);

int			ft_count_current_numcount(int **array, int initial_numcount);
void		sort_descending_sorted_nums(t_data *data);
int			check_for_sorted(t_data *data);
int			check_for_reverse_sorted(t_data *data);

// Sort
void		sort_two(t_data *data);
void		sort_three(t_data *data);
void		systeminf(void);

// Statistics

void		find_min_value_and_prepare(t_data *data);

// Rank Transformation
void		rank_transformation(t_data *data);
void		set_all_ranked_to_false(t_data *data);

// utils
void		check_flag_print_op(t_data *data, char *op);
int			ft_ceil(int a, int b);

void		chunk_asign(t_data *data);
void		check_ascending_order(t_data *data);
void		check_descending_order(t_data *data);
void		free_int(t_data *data);
void		allocate_int(t_data *data);

double		ft_sqrt(double x, double epsilon);


void	chunk_assign(t_data *data);
void	find_chunk_size(t_data *data);
void	push_chunks(t_data *data);
void pull_back_all(t_data *d);
void sort_under_seven(t_data *d);

int stack_len(int **array, int base, int max);
void smart_reverse_rotate(t_data *d, int rra_needed, int rrb_needed);
void smart_rotate(t_data *d, int ra_needed, int rb_needed);
void calibrate_chunks(t_data *d);

void sort_optimal(t_data *data);
void    assign_chunk_id(t_data *d);
void    find_chunk_size(t_data *d);
