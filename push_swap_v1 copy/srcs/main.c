/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:52:05 by lakdogan          #+#    #+#             */
/*   Updated: 2025/04/29 22:42:47 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	systeminf(void)
{
	system("leaks push_swap");
}

// void	print_a(t_data *data)
// {
// 	data->i.i = 0;
// 	// printf("dasdasfasfewewrewrew\n");
// 	printf("TOP INDEX OF STACK A: %i\n", data->top_a);
// 	while (data->i.i < data->numcount)
// 	{
// 		if (data->a[data->i.i] != NULL)
// 			printf("STACK A >> Index: %i , Number %i | ", data->i.i,
// 				data->a[data->i.i][0]);
// 		data->i.i++;
// 	}
// 	data->i.i = 0;
// 	printf("\nTOP INDEX OF STACK B: %i\n", data->top_b);
// 	while (data->i.i < data->numcount)
// 	{
// 		if (data->b[data->i.i] != NULL)
// 			printf("STACK B >> Index: %i , Number %i | ", data->i.i,
// 				data->b[data->i.i][0]);
// 		data->i.i++;
// 	}
// 	printf("\n");
// }

void	print_less(t_data *data)
{
	data->i.i = 0;
	printf("NUMBERS IN STACK A:\n");
	while (data->i.i < data->numcount)
	{
		if (data->a[data->i.i] != NULL)
			printf("%i | ", data->a[data->i.i][VALUE]);
		data->i.i++;
	}
	data->i.i = 0;
	printf("\nNUMBERS IN STACK B:\n");
	while (data->i.i < data->numcount)
	{
		if (data->b[data->i.i] != NULL)
			printf("%i | ", data->b[data->i.i][VALUE]);
		data->i.i++;
	}
	printf("\n");
}

void	print_rank(t_data *data)
{
	init_itterators(data);
	printf("RANKINGS\n");
	while (data->i.i < data->numcount)
	{
		printf("%i | \n", data->a[data->i.i][RANK]);
		data->i.i++;
	}
}

void	print_chunk(t_data *data)
{
	init_itterators(data);
	printf("Chunking: 1 == stackA | 2 == stackB");
	while (data->i.i < data->numcount)
	{
		printf("%i | \n", data->a[data->i.i][CHUNK]);
		data->i.i++;
	}
}

void	print_asc_order(t_data *data)
{
	init_itterators(data);
	printf("ASCENDING ORDER\n");
	while (data->i.i < data->numcount)
	{
		printf("%i | \n", data->a[data->i.i][IN_ORDER_ASC]);
		data->i.i++;
	}
}

void	print_des_order(t_data *data)
{
	init_itterators(data);
	printf("DESCENDING ORDER\n");
	while (data->i.i < data->numcount)
	{
		printf("%i | \n", data->a[data->i.i][IN_ORDER_DES]);
		data->i.i++;
	}
}

void	print_chunk_assigns(t_data *data)
{
	init_itterators(data);
	while (data->i.i < data->numcount)
	{
		printf("RANK: %i - in CHUNK: %i \n", data->a[data->i.i][RANK],
			data->a[data->i.i][CHUNK]);
		data->i.i++;
	}
}

void	print_stacks(t_data *data)
{
	int	len;
	int	i;

	/* Stack A */
	printf("NUMBERS IN STACK A:\n");
	len = ft_count_current_numcount(data->a, data->numcount);
	i = data->top_a;
	while (i < data->top_a + len)
	{
		printf("%i | ", data->a[i][VALUE]);
		i++;
	}
	printf("\n");
	/* Stack B */
	printf("NUMBERS IN STACK B:\n");
	len = ft_count_current_numcount(data->b, data->numcount);
	i = data->top_b + 1;
	while (i < data->top_b + 1 + len)
	{
		printf("%i | ", data->b[i][VALUE]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialization_structs(&data, argc);
	validate_input(argc, argv, &data);
	split_numbers_by_one_argv(&data, argv, argc);
	init_top_b(&data);
	validate_unique_numbers(&data);
	rank_transformation(&data);
	printf("\n**********************************************\n\n");
	print_rank(&data);
	printf("\n**********************************************\n\n");
	print_chunk(&data);
	printf("\n**********************************************\n\n");
	check_ascending_order(&data);
	print_asc_order(&data);
	printf("\n**********************************************\n\n");
	check_descending_order(&data);
	print_des_order(&data);
	printf("\n**********************************************\n\n");
	// assign_chunk_id(&data);
	// printf("Chunk count: %i\n", data.chunk_count);
	// printf("Chunk size: %i\n", data.chunk_size);
	// print_chunk_assigns(&data);
	data.sorted_flag = 0;
	data.compare = 0;
	data.moves = 0;
	data.min_num = INT_MAX;
	data.max_num = INT_MIN;
	if (check_for_reverse_sorted(&data))
		sort_descending_sorted_nums(&data);
	else
	{
		data.sorted_flag = 0;
		data.compare = 0;
		data.moves = 0;
		data.min_num = INT_MAX;
		data.max_num = INT_MIN;
		if (check_for_sorted(&data))
		{
			print_less(&data);
			return (0);
		}
		else
		{
			if (data.numcount <= 6)
			{
				sort_under_seven(&data);
			}
			else
			{
				data.top_a = 0;
				init_top_b(&data);
				assign_chunk_id(&data); /* 1) Chunk-Infos für sort_optimal  */
				sort_optimal(&data);    /* 2) LIS/LDS-Phase                 */
				/* =========== 3) PUSH-CHUNKS  (optional)  =========== */
				/* push_chunks(&data); */
				/* =========== 4) GREEDY-MERGE  ======================= */
				greedy_merge(&data); /* statt pull_back_all()          */
				/* =========== 5) Min nach oben  ====================== */
				rotate_min_to_top(&data);
	
			}
		}
	}
	// if (ft_is_sorted_int(data.a, data.numcount))
	// 	return (0);
	// if (data.numcount == 2)
	// {
	// 	sort_two(&data);
	// 	// print_rank(&data);
	// 	return (0);
	// }
	// if (data.numcount == 3)
	// {
	// 	sort_three(&data);
	// 	// print_rank(&data);
	// 	return (0);
	// }
	// if (check_for_sorted(&data))
	// 	print_less(&data);
	// else
	// 	printf("not sorted\n");
	// data.compare = 0;
	// data.sorted_flag = 0;
	// data.moves = 0;
	// if (check_for_reverse_sorted(&data))
	// 	sort_descending_sorted_nums(&data);
	// else
	// 	ft_putendl_fd("Array is not sorted in descending order", 1);
	// // printf("\n**********************************************\n\n");
	// print_less(&data);
	print_stacks(&data);
	// // printf("\n**********************************************\n\n");
	// // print_a(&data);
	// print_rank(&data);
	printf("Operation count: %i\n", data.operation_count);
	free_all(&data);
	printf("\nnumcount: %i\n", data.numcount);
	printf("Chunkcount: %i\n", data.chunk_count);
	// systeminf();
	return (0);
}
