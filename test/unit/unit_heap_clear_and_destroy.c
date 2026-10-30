/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heap_clear_and_destroy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:13:48 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 16:23:40 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

/*

    Run this test with valgrind: 
        valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=memory.log

*/

typedef struct s_heap_test
{
    char *s1;
    char *s2;

} t_heap_test;

static t_heap_test *get_heap_test_node(char *s1, char *s2)
{
    t_heap_test *test_node;

    test_node = malloc(sizeof(t_heap_test));
    test_node->s1 = strdup(s1);
    test_node->s2 = strdup(s2);
    return (test_node);
}

static void clear_test_node(void *ptr)
{
    t_heap_test *node;

    node = (t_heap_test *)ptr;
    free(node->s1);
    free(node->s2);
    free(node);
}

void unit_heap_clear_and_destroy(void)
{
    START_TEST;
    t_heap *heap;
    t_heap_node *node;
    t_heap_test *test;

    heap = heap_init();
    assert(heap);

    heap_clear(NULL, NULL);
    while (heap->size_queue < 100)
    {
        test = get_heap_test_node("hello", "world");
        node = heap_new_node(test);
        assert(test);
        assert(heappush(heap,node,NULL) == TRUE);
    }
    assert(heap->size_queue == 100);
    heap_clear(heap, clear_test_node);
    assert(heap);
    assert(heap->queue);
    assert(!*heap->queue);
    assert(heap->size_queue == 0);
    heap_destroy(&heap);
    assert(!heap);
    END_TEST;
}