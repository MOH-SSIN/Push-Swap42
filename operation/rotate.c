#include "../push_swap.h"

void    rotate(t_noeud **a, bool sig, bool a_b)
{
    t_noeud *first;
    t_noeud *last;

    if (!(*a) || !(*a)->suivant)
        return ;

    first = *a;
    last = *a;

    while (last->suivant)
        last = last->suivant;

    *a = first->suivant;
    (*a)->precedent = NULL;

    last->suivant = first;
    first->precedent = last;
    first->suivant = NULL;
    set_index(*a);
    if (sig && a_b)
        write (1, "ra\n", 3);
    else if (sig && !a_b)
        write (1, "rb\n", 3);
}

void    double_rotate(t_noeud **a, t_noeud **b)
{
    rotate(a, false, true);
    rotate(b, false, false);
    write (1, "rr\n", 3);
}
