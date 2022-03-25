/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:43:00 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 11:43:12 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 * Structures
 */
typedef struct s_input
{
	int		argc;
	char	**argv;
}				t_input;

typedef struct s_stack
{
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_params
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		index_min;
	int		mid;
	int		len_a;
	int		len_b;
}				t_params;
/*
 * Parser's functions
 */
char	**ft_parser(struct s_input input);
char	**ft_getstring(struct s_input input);
void	err_handler(void);
int		validation(char **str);
int		is_allnums(char **str);
int		is_nodup(char **str);


#endif
