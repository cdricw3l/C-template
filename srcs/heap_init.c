/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 09:01:04 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 20:42:46 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

t_heap	*heap_init(void)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
	{
		printf("Error heap allocation %d\n", __LINE__ - 3);
		return (NULL);
	}
	heap->queue = malloc(sizeof(t_heap_node *));
	if (!heap->queue)
	{
		printf("Error queue allocation %d\n", __LINE__ - 3);
		free(heap);
		return (NULL);
	}
	*heap->queue = NULL;
	heap->size_queue = 0;
	return (heap);
}
