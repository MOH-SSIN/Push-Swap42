#include "../push_swap.h"

void    rrotate(t_noeud **a, bool sig, bool a_b)
{
	t_noeud *last;
    t_noeud *before_last;

    if (!(*a) || !(*a)->suivant)
        return ;

    last = *a;
    while (last->suivant)
        last = last->suivant;

    before_last = last->precedent;

    before_last->suivant = NULL;
    last->precedent = NULL;


    last->suivant = *a;
    (*a)->precedent = last;
    *a = last;
    set_index(*a);
    if (sig && a_b)
        write (1, "rra\n", 4);
    else if (sig && !a_b)
        write (1, "rrb\n", 4);
}

void    double_rrotate(t_noeud **a, t_noeud **b)
{
    rrotate(a, false, true);
    rrotate(b, false, false);
    write (1, "rrr\n", 4);
}
