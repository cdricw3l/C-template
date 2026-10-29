/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 09:01:04 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:47:47 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

t_heap	*heap_init(void);


void unit_heap_init(void)
{
	START_TEST;
	t_heap *heap;

	heap = heap_init();
	assert(heap);
	assert(heap->queue);
	assert(!*heap->queue);
	assert(heap->size_queue == 0);

	free(heap->queue);
	free(heap);
	
	END_TEST;
}