/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:02:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 16:23:04 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void to_upper(t_heap_node *node)
{
    char *str;

    str = (char *)node->content;
    while (*str)
    {
        if(*str >= 97 && *str < 122)
            *str = *str - 32;
        str++;
    }
}

static void check_heap(t_heap_node *root)
{
    char *str;

    if (!root)
        return ;
    check_heap(root->left);
    check_heap(root->right);
    str = (char *)root->content;
    while (*str)
    {
        if (*str != 32)
            assert(*str >= 65 && *str <= 90);
        str++;
    }
    
}

static void clean_heap(void *ptr)
{
    char *content;

    content = (char *)ptr;
    free(content);
    content = NULL;
}

void unit_heap_iter(void)
{
    START_TEST;
    t_heap *heap;
    t_heap_node *node;

    heap = heap_init();
    assert(heap);
    
    while (heap->size_queue < 100)
    {
        node = heap_new_node(strdup("hello world"));
        assert(node);
        assert(heappush(heap,node,NULL) == TRUE);
    }
    assert(heap->size_queue == 100);
    heap_iter(*heap->queue, NULL);
    heap_iter(NULL, to_upper);
    heap_iter(*heap->queue, to_upper);
    check_heap(*heap->queue);

    heap_clear(heap, clean_heap);
    heap_destroy(&heap);
    END_TEST;
    
}