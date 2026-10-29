/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heappop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:10:48 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/29 18:33:55 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

int	heappop(t_heap *heap, int (*cmp)(void *p1, void *p2),
			void (*del_content)(void *))
{
	t_heap_node	*current;

	if (!heap || !heap->queue || !cmp)
		return (FALSE) ;
	current = *heap->queue;
	if (!current)
		return (FALSE) ;
	while (current->left && current->right)
	{
		if (cmp(current->left->content, current->right->content))
		{
			heap_swap_node(current, current->left);
			current = current->left;
		}
		else
		{
			heap_swap_node(current, current->right);
			current = current->right;
		}
	}
	if (current->left)
	{
		heap_swap_node(current, current->left);
		current = current->left;
	}
	else if (current->right)
	{
		heap_swap_node(current, current->right);
		current = current->right;
	}
	if (current->parent && current->parent->left == current)
		current->parent->left = NULL;
	else if (current->parent && current->parent->right == current)
		current->parent->right = NULL;
	if (del_content)
		del_content(current->content);
	free(current);
	current = NULL;
	heap->size_queue--;
	if (heap->size_queue == 0)
		*heap->queue = NULL;
	return (TRUE);
}
