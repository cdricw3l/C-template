#include "../include/test.h"

int main(void)
{
    printf(BBLU"TEST UNITAIRE"CRESET"\n");
    unit_heap_init();
    unit_heap_new_node();
    unit_heap_swap_node();
    unit_heap_display_node();
    unit_heappush();
    return (0);
}