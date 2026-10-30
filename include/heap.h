/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:56:11 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 16:33:43 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define HEAP_BIT_MAX 32

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <assert.h>
#include "color-codes.h"

typedef struct s_heap_node
{
	void				*content;
	struct s_heap_node	*parent;
	struct s_heap_node	*left;
	struct s_heap_node	*right;

}	t_heap_node;

typedef struct s_heap
{
	int		size_queue;
	t_heap_node	**queue;

}	t_heap;

t_heap		*heap_init(void);
t_heap_node	*heap_new_node(void *content);
int			heap_add_node( t_heap *heap, t_heap_node *node);
t_heap_node	*heap_get_node(t_heap *heap, int target_node_idx);
void		heap_iter(t_heap_node *root, void (*f)(t_heap_node *node));
void		heap_clear(t_heap *heap, void (*f)(void *));
void		heap_destroy(t_heap **heap);
int			get_path(int target_node_idx, char buffer[HEAP_BIT_MAX + 1]);
int			heappush(t_heap *heap, t_heap_node *node,  int (*cmp)(void *p1, void *p2));
int 		heappop(t_heap *heap, int (*cmp)(void *p1, void *p2), void (*del_content)(void *));
void		heap_swap_node(t_heap_node *src, t_heap_node *dst);
void		heap_display_node(t_heap_node *node, void (*display_content)(void *));
t_heap_node	**heap_bfs_binary_tree_as_arr(t_heap *heap);

#endif
