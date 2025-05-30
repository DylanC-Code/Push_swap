/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 09:40:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_info
{
	int				size_a;
	int				size_b;
}					t_info;

typedef struct s_stack
{
	int				number;
	int				lis;
	int				lis_len;
	int				prev;
	int				dis;
	int				pair;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_status			check_valid_move(char *move);
void				calculate_best_elem(t_stack *b_elem, t_info *info);
int					calcul_moves(t_stack *b_elem, t_info *info);
void				marking_best_elem(t_stack **stack_a, t_stack **stack_b,
						t_info *info);
t_stack				*min_move(t_stack **stack_b, t_info *info);
void				b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info);
t_stack				*max_of_stack(t_stack *stack);
int					check_duplicate(t_stack *stack, int value);
t_status			ft_error(void);
int					is_integer(char *num);
void				ft_sort_under_five(t_stack **s_a, t_stack **s_b,
						t_info *info);
void				sort_five(t_stack **s_a, t_stack **s_b, t_info *info);
void				ft_sort_three(t_stack **stack, t_info *info);
void				sort_three_a(t_stack **stack, t_info *info);
void				sort_three_b(t_stack **stack, t_info *info);
t_stack				*max_of_length(t_stack **stack);
t_stack				*find_elem_by_index(t_stack **stack, int index);
void				get_lis(t_stack **stack);
void				find_lis(t_stack **stack);
int					check_space(char *string);
char				*check_arguments(int ac, char **av);
t_status			check_valid_numbers(int ac, char **av);
t_status			stack_init(t_stack **stack_a, t_stack **stack_b,
						t_info **info);
void				sort_stack(t_stack **stack_a, t_stack **stack_b,
						t_info *info);
void				ft_swap(t_stack **stack, char *move, t_info *info);
void				ft_ss(t_stack **stack_a, t_stack **stack_b, char *move,
						t_info *info);
void				ft_push(t_stack **stack_a, t_stack **stack_b, char *move);
t_stack				*ft_last_elem(t_stack *stack);
void				ft_rotate(t_stack **stack, char *move, t_info *info);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, char *move,
						t_info *info);
void				ft_reverse_rotate(t_stack **stack, char *move,
						t_info *info);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b, char *move,
						t_info *info);
void				ft_print_move(char *move);
int					ft_max(int a, int b);
void				a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info);
void				elem_pos(t_stack **stack_a, t_stack *elem);
void				mv_to_top(t_stack **s_a, t_stack **s_b, t_stack *b_elem,
						t_info *info);
void				norm_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem,
						t_info *info);
void				rr_or_rrr(t_stack **s_a, t_stack **s_b, t_stack *b_elem,
						t_info *info);
void				rrr_move(t_stack **s_a, t_stack **s_b, t_stack *b_elem,
						t_info *info);
int					check_number(char *num);
int					stack_is_sorted(t_stack *stack);
void				min_in_top(t_stack **stack, t_info *info);
t_stack				*min_elem(t_stack *stack);
void				index_stack(t_stack **stack);
int					is_empty(t_stack *s);
void				push(t_stack **s, int value);
int					pop(t_stack **s, int *value);
int					fill_stack(t_stack **s, char *arg);
int					three_len_move(char *move);
int					four_len_move(char *move);
void				perform_move(t_stack **s_a, t_stack **s_b, int move,
						t_info *info);
void				perform_move_two(t_stack **s_a, t_stack **s_b, int move,
						t_info *info);
t_status			check_moves(t_stack **stack_a, t_stack **stack_b,
						t_info *info, int fd);
char				*join_arg(char *s1, char *s2, int a);
int					ft_count_elem(t_stack *stack);
void				free_savage(t_stack *a_stack, t_stack *b_stack,
						t_info *info, char **argv);
void				print_savage(t_stack *stack_a, t_stack *stack_b);
t_status			get_stack(t_stack **stack_a, char **av, t_info *info,
						int ac);

#endif
