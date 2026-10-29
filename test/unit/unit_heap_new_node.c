/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_new_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:25:19 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:31:23 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

t_heap_node *heap_new_node(void *content);

void unit_heap_new_node(void)
{
	START_TEST;
	
    t_heap_node *node;
    int i;

    node = heap_new_node(NULL);
    assert(node);
    assert(node->content == NULL);
    assert(node->left == NULL);
    assert(node->right == NULL);
    assert(node->parent == NULL);
    free(node);

    i = 42;
    node = heap_new_node(&i);
    assert(node);
    assert(*((int *)node->content) == 42);
    node->content = strdup("hello world");
    assert(!strcmp("hello world", node->content));
    assert(node->left == NULL);
    assert(node->right == NULL);
    assert(node->parent == NULL);
    free(node->content);
    free(node);
	END_TEST;
}