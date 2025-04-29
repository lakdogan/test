# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 00:23:28 by lakdogan          #+#    #+#              #
#    Updated: 2025/04/29 21:30:56 by lakdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 					:= 	cc 
CFLAGS				:=	-Wall -Wextra -Werror
	
LIBFT_DIR			:=	libft
	
INCLUDES			:=	-I./inc -I./$(LIBFT_DIR)
	
NAME				:=	push_swap
	
LIBFT				:=	$(LIBFT_DIR)/libft_ftpf_gnl.a
	
OBJECTS_DIR			:=	./objs/
SRCS_DIR			:=	./srcs/
BONUS_DIR			:=	$(SRCS_DIR)bonus/
CALCULATIONS_DIR	:=  $(SRCS_DIR)calculations/
INIT_DIR			:=	$(SRCS_DIR)init/
MEM_DIR				:=	$(SRCS_DIR)mem/
ALLOCATE_DIR		:=	$(MEM_DIR)allocate/
ERROR_DIR			:=	$(MEM_DIR)error/
FREE_DIR			:=	$(MEM_DIR)free/
OPERATIONS_DIR		:=	$(SRCS_DIR)operations/
PUSH_DIR			:=	$(OPERATIONS_DIR)push/
REVERSE_DIR			:=	$(OPERATIONS_DIR)reverse/
ROTATE_DIR			:=	$(OPERATIONS_DIR)rotate/
SWAP_DIR			:=	$(OPERATIONS_DIR)swap/
PARSE_DIR			:=	$(SRCS_DIR)parse/
STATISTICS_DIR		:=	$(SRCS_DIR)statistics/
UTILS_DIR			:=	$(SRCS_DIR)utils/
VALIDATE_DIR		:=	$(SRCS_DIR)validate/
SORT_ALGORYTHM_DIR	:=	$(SRCS_DIR)sort_algorythm/
CHECKER_DIR			:=	$(SRCS_DIR)checker/

PUSH_SWAP_MANDATORY_FILES := \
				$(SRCS_DIR)main.c \
				$(INIT_DIR)init_data_structs.c \
				$(ALLOCATE_DIR)allocate_arr.c \
				$(ALLOCATE_DIR)allocate_int.c \
				$(ALLOCATE_DIR)ft_alloc_int_array.c \
				$(ALLOCATE_DIR)ft_set_int_value.c \
				$(ERROR_DIR)error.c \
				$(FREE_DIR)free_arrays.c \
				$(FREE_DIR)free_int.c \
				$(FREE_DIR)ft_del_int_value.c \
				$(FREE_DIR)ft_free_int_array.c \
				$(FREE_DIR)ft_free_string.c \
				$(PARSE_DIR)split_numbers.c \
				$(VALIDATE_DIR)validate_input.c \
				$(VALIDATE_DIR)validate_unique_nums.c \
				$(UTILS_DIR)ft_isspace.c \
				$(UTILS_DIR)ft_strtoll.c \
				$(UTILS_DIR)error_handler.c \
				$(UTILS_DIR)ft_ceil.c \
				$(UTILS_DIR)ft_count_current_numcount.c \
				$(UTILS_DIR)check_flag_print_op.c \
				$(UTILS_DIR)ft_sqrt.c \
				$(UTILS_DIR)chunk_utils.c \
				$(UTILS_DIR)utils.c \
				$(UTILS_DIR)stack_utils.c \
				$(SWAP_DIR)swap_a.c \
				$(SWAP_DIR)swap_b.c \
				$(SWAP_DIR)swap_both.c \
				$(PUSH_DIR)push_b.c \
				$(PUSH_DIR)push_a.c \
				$(ROTATE_DIR)rotate_a.c \
				$(ROTATE_DIR)rotate_b.c \
				$(ROTATE_DIR)rotate_both.c \
				$(REVERSE_DIR)reverse_rotate_a.c \
				$(REVERSE_DIR)reverse_rotate_b.c \
				$(REVERSE_DIR)reverse_rotate_both.c \
				$(CHECKER_DIR)check_for_sorted.c \
				$(CHECKER_DIR)check_for_reverse_sorted.c \
				$(SORT_ALGORYTHM_DIR)sort_descending_sorted_nums.c \
				$(SORT_ALGORYTHM_DIR)sort_two_three.c \
				$(SORT_ALGORYTHM_DIR)push_chunks.c \
				$(SORT_ALGORYTHM_DIR)pull_back_all.c \
				$(SORT_ALGORYTHM_DIR)mini_sort.c \
				$(SORT_ALGORYTHM_DIR)smart_rotations.c \
				$(STATISTICS_DIR)check_ascending_order.c \
				$(STATISTICS_DIR)check_descending_order.c \
				$(STATISTICS_DIR)statistics.c \
				$(STATISTICS_DIR)rank_transformation.c \
				

PUSH_SWAP_OBJS	:= $(patsubst $(SRCS_DIR)%.c,$(OBJECTS_DIR)%.o,$(PUSH_SWAP_MANDATORY_FILES))

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DIR)
		@$(MAKE) -C $(LIBFT_DIR)
		@touch $(LIBFT)
		
$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
		$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
