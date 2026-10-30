#include "../include/test.h"

int main(void)
{
    printf(BBLU"TEST UNITAIRE"CRESET"\n");
    unit_heap_init();
    unit_heap_new_node();
    unit_heap_swap_node();
    unit_heap_display_node();
    unit_heappush();
    unit_heap_clear_and_destroy();
    unit_heap_iter();
    unit_heap_bfs_arr();
    return (0);
}