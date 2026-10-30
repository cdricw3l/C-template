/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_bfs_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:24:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 17:01:22 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int *get_int(void)
{
    static int i = 0;
    int *value;

    value = malloc(sizeof(int));
    assert(value);
    *value = i;
    i++;
    return (value);

}

static void check_bfs_arr(t_heap_node **arr)
{
    int i;
    int j;
    int value_1;
    int value_2;
    
    i = 0;
    assert(arr);
    while (arr[i])
    {
        j = i + 1;
        value_1 = *((int *)((arr[i])->content));
        while (arr[j])
        {
            value_2 = *((int *)((arr[j])->content));
            assert(value_1 < value_2);
            j++;
        }
        i++;
    }
}

void unit_heap_bfs_arr(void)
{
    START_TEST;

    t_heap *heap;
    t_heap_node *node;
    t_heap_node **arr;
    int     *value;

    heap = heap_init();
    assert(heap);
    while (heap->size_queue < 100)
    {
        value = get_int();
        assert(value);
        node = heap_new_node(value);
        assert(node);
        assert(heappush(heap, node, NULL) == TRUE);
    }
    assert(heap && heap->queue && heap->size_queue == 100);
    arr = heap_bfs_binary_tree_as_arr(heap);
    assert(arr && arr[0]);
    check_bfs_arr(arr);
    free(arr);
    heap_clear(heap, free);
    assert(heap->size_queue == 0);
    arr = heap_bfs_binary_tree_as_arr(heap);
    assert(!arr);
    arr = heap_bfs_binary_tree_as_arr(NULL);
    assert(!arr);
    node = heap_new_node(strdup("hello"));
    heappush(heap, node, NULL);
    arr = heap_bfs_binary_tree_as_arr(heap);
    assert(arr);
    int len;
    len = 0;
    while (arr[len])
    {
        len++;
    }
    assert(len == 2);
    assert(!strcmp("hello", (*arr)->content));
    free(arr);
    heap_clear(heap, free);
    heap_destroy(&heap);
    END_TEST;
}