#include "../include/test.h"


typedef struct s_request
{
    int request_id;
    int amout;

} t_request;

int main(void)
{
    t_heap_node *node;

    t_request r_arr[2];
    
    t_request r1;
    // t_request r2;

    // r1.coder_id = 1;
    // r1.request_id = 1;
    // r2.coder_id = 2;
    // r2.request_id = 2;

    // r_arr[0] = r1;
    // r_arr[1] = r2;

    printf("taille de la stucure vide r1 %ld\n", sizeof(r1));
    printf("sizeof r_arr %ld\n", sizeof(r_arr));

    printf("Taille d'un noeud de l'arbre binaire: %ld\n", sizeof(t_heap_node));
    printf("size of ptr content: %ld\n", sizeof(node->content));
    printf("size of ptr parent: %ld\n", sizeof(node->parent));
    printf("size of ptr left: %ld\n", sizeof(node->left));
    printf("size of ptr right: %ld\n", sizeof(node->right));


    printf("Taille de la strcuture heap: %ld\n", sizeof(t_heap));

    return (0);
}