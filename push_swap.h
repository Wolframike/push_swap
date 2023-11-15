/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 04:46:50 by misargsy          #+#    #+#             */
/*   Updated: 2023/10/31 00:56:59 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}	t_stacks;

typedef struct s_queue
{
	char			*op;
	struct s_queue	*next;
}	t_queue;

//Basic Stack Operations: ps_stackops.c
t_stacks	*stacks_init(void);
bool		stack_push(t_node **stack, int value);
int			stack_get(t_node *stack, int n);
size_t		stack_depth(t_node *stack);
void		stack_clear(t_node *stack);

//Operations Specified in PDF: ps_pushswap.c, ps_rotate.c, ps_mix.c
void		sa(t_stacks *stack);
void		sb(t_stacks *stack);
void		pa(t_stacks *stack);
void		pb(t_stacks *stack);
void		ra(t_stacks *stack);
void		rb(t_stacks *stack);
void		rra(t_stacks *stack);
void		rrb(t_stacks *stack);
void		ss(t_stacks *stack);
void		rr(t_stacks *stack);
void		rrr(t_stacks *stack);

//Coordinate Compression: ps_coco.c
bool		ps_coco(int *arr, size_t size);

//Input Parsing: ps_parse_util.c
char		**ps_free2darr(char **arr);
bool		ps_isnumber(char **split);
bool		ps_isoverflow(char **split, char *max, char *min);
bool		ps_isduplicate(int *input, size_t size);
char		**ps_parse_split(int argc, char **argv);

//Small Stack Sorting: ps_sort_small.c
void		ps_three(t_stacks *stacks, t_queue **head);
void		ps_four(t_stacks *stacks, t_queue **head);
void		ps_five(t_stacks *stacks, t_queue **head);
void		ps_sort_small(t_stacks *stacks, t_queue **head, int depth);

//Main Sorting Functions: ps_sort.c
void		ps_sort(t_stacks *stacks, t_queue **head);

//Utils for sorting: ps_sort_util.c
bool		ps_issorted(t_node *head);
void		ps_fetchpa(t_stacks *stacks, t_queue **head, int n);
void		ps_fetchpb(t_stacks *stacks, t_queue **head, int n);

//Queue Operations for Optimization: ps_queueops.c
bool		ps_issorted(t_node *head);
bool		queue_enqueue(t_queue **head, char *op);
void		queue_clear(t_queue *head);

//Optimization: ps_optimization.c
void		ps_doop(t_stacks *stacks, t_queue **head,
				void (*op)(t_stacks*), char *str);
void		ps_printqueue(t_queue *head);

//Main: push_swap.c
void		*ps_exit(char **arr, bool f);
int			*ps_parse(int argc, char **argv, size_t *size);

#endif