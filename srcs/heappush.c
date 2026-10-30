/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:39:24 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 09:20:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

int	heap_add_node( t_heap *heap, t_heap_node *node)
{
	t_heap_node	*target_node;

	if (!heap || !node)
		return (FALSE);
	if (!(*heap->queue))
	{
		*heap->queue = node;
		heap->size_queue++;
		return (TRUE);
	}
	target_node = heap_get_node(heap, (heap->size_queue + 1) / 2);
	if (!target_node)
		return (FALSE);
	if ((heap->size_queue + 1) % 2 == 0 && !target_node->left)
		target_node->left = node;
	else if ((heap->size_queue + 1) % 2 != 0 && !target_node->right)
		target_node->right = node;
	else
		return (FALSE);
	node->parent = target_node;
	heap->size_queue++;
	return (TRUE);
}

int	heappush(t_heap *heap, t_heap_node *node,  int (*cmp)(void *p1, void *p2))
{
	t_heap_node	*current;

	if (heap_add_node(heap, node) == FALSE)
		return (FALSE);
	if (!cmp)
		return (TRUE);
	current = node;
	if (!current)
		return (FALSE);
	while (current)
	{
		if (current->parent
			&& cmp(current->content, current->parent->content))
		{
			heap_swap_node(current, current->parent);
			current = current->parent;
		}
		else
			return (TRUE);
	}
	return (TRUE);
}
