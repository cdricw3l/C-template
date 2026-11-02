/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_bfs_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:12:26 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 18:21:55 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

static void	push(t_heap_node **queue, t_heap_node *node)
{
	int	i;

	i = 0;
	while (queue[i])
		i++;
	queue[i] = node;
}

static void	pop(t_heap_node **queue, int queue_size)
{
	int	i;

	i = 0;
	while (i < queue_size - 1)
	{
		queue[i] = queue[i + 1];
		i++; 
	}
	queue[i] = NULL;
}

static int	queue_is_empty(t_heap_node **queue)
{
	if (!queue)
		return (TRUE);
	if (!(*queue))
		return (TRUE);
	return (FALSE);
}

static t_heap_node	**get_heap_as_arr(t_heap *heap, t_heap_node **queue)
{
	t_heap_node	**arr;
	t_heap_node	*tmp;
	int			queue_size;

	arr = malloc(sizeof(t_heap_node *) * (heap->size_queue + 1));
	if (!arr)
		return (NULL);
	memset(arr, 0, sizeof(t_heap_node *) * (heap->size_queue + 1));
	push(queue, heap->queue[0]);
	queue_size = 1;
	while (!queue_is_empty(queue))
	{
		tmp = queue[0];
		push(arr, tmp);
		pop(queue, queue_size);
		queue_size--;
		push(queue, tmp->left);
		queue_size++;
		push(queue, tmp->right);
		queue_size++;

	}
	return (arr);
}

/**
 * @brief Converts a binary tree into a t_heap_node array using a Breadth-First Search (BFS) algorithm.
 *
 * This function traverses the binary heap level by level (level-order traversal)
 * and flattens its structure into a contiguous array representation.
 *
 * @param heap The pointer to the binary heap structure to process.
 * @return A pointer to the newly allocated t_heap_node array, or NULL on failure.
 */
t_heap_node	**heap_bfs_binary_tree_as_arr(t_heap *heap)
{
	t_heap_node	**queue;
	t_heap_node	**arr;

	if (!heap || !heap->queue || !*heap->queue)
		return (NULL);
	queue = malloc(sizeof(t_heap_node *) * (heap->size_queue + 1));
	if (!queue)
		return (NULL);
	memset(queue, 0, sizeof(t_heap_node *) * (heap->size_queue + 1));
	arr = get_heap_as_arr(heap, queue);
	assert(arr[0]);
	free(queue);
	return (arr);
}
