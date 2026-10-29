/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_swap_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:22:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:48:25 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void        heap_swap_node(t_heap_node *src, t_heap_node *dst);
t_heap_node *heap_new_node(void *content);

void unit_heap_swap_node(void)
{
	START_TEST;
	
    int         a;
    int         b;
    t_heap_node *node_1;
    t_heap_node *node_2;

    a = 0;
    b = 42;
    node_1 = heap_new_node(&a);
    node_2 = heap_new_node(&b);
    heap_swap_node(node_1, node_2);
    assert(*(int *)node_1->content == 42);
    assert(*(int *)node_2->content == 0);
    heap_swap_node(node_1, NULL);
    assert(*(int *)node_1->content == 42);
    assert(*(int *)node_2->content == 0);
    heap_swap_node(NULL, node_2);
    assert(*(int *)node_1->content == 42);
    assert(*(int *)node_2->content == 0);
    heap_swap_node(NULL, NULL);
    assert(*(int *)node_1->content == 42);
    assert(*(int *)node_2->content == 0);
    free(node_1);
    free(node_2);
	END_TEST;
}
