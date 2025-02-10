#include "../push_swap.h"

void    push(t_noeud **a, t_noeud **b, bool sign)
{
    t_noeud *first;

    if (!(*b))
        return ;

    first = *b;
    *b = first->suivant;

    if (*b) 
        (*b)->precedent = NULL;

    first->suivant = *a;

    if (*a) 
        (*a)->precedent = first;

    first->precedent = NULL;
    *a = first;
    set_index(*a);
    set_index(*b);
    if (sign)
        write(1, "pa\n", 3);
    else
        write(1, "pb\n", 3);
}
