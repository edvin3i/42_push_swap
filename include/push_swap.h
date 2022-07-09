/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:43:00 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 11:43:12 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 * Structures
 */
typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}				t_node;

/*
 * Push_Swap
 */
void	push_swap(t_node **stack_a, t_node **stack_b);
/*
 * Error and exit
 */
void	error(void);
/*
 * Validators
 */
int		is_allnums(int argc, char **argv);
int		is_nodup(int argc, char **argv);
int		is_sorted_arr(int argc, char **argv);
int		is_sorted_stack(t_node **stack);
void	validation(int argc, char **argv);
/*
 * Sort & Algorithms
 */
void	sorting(t_node *stack_a, t_node *stack_b);
void	sort_three(t_node **stack);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_radix(t_node **stack_a, t_node **stack_b);
void	small_sel(t_node **stack_a, t_node **stack_b);
/*
 * Init
 */
void	ps_set_index(t_node **stack);
void	ps_init_stack(t_node **stack, int argc, char **argv);
/*
 * Utils
 */
void	ps_free_str(char **str);
void	ps_free_stack(t_node **stack);
int		min_index(t_node **stack, int num);
int		ps_index_bmax(t_node **stack);
/*
 * List functions
 */
t_node	**ps_lstcreate(void);
t_node	*ps_lstnew(int num);
t_node	*ps_lstlast(t_node *node);
t_node	*ps_next_min(t_node **stack);
void	ps_lstadd_back(t_node **stack, t_node *node);
int		ps_lstsize(t_node *node);
int		ps_movescount(t_node **stack, int index);
/*
 * Moves
 */
int		move_p(t_node **stack_a, t_node **stack_b);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_a, t_node **stack_b);

int		move_s(t_node **stack);
int		sa(t_node **stack);
int		sb(t_node **stack);
int		ss(t_node **stack_a, t_node **stack_b);

int		move_r(t_node **stack);
int		ra(t_node **stack);
int		rb(t_node **stack);
int		rr(t_node **stack_a, t_node **stack_b);

int		move_rev(t_node **stack);
int		rra(t_node **stack);
int		rrb(t_node **stack);
int		rrr(t_node **stack_a, t_node **stack_b);
void	ps_movetotop(t_node **stack, int count);

#endif
