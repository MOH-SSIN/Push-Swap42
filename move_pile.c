#include "push_swap.h"

static t_noeud *find_cheapest(t_noeud **b)
{
   t_noeud *cheapest;

    cheapest = *b;
    while (cheapest)
    {
        if (cheapest->moins_cher == true)
            return cheapest;
        cheapest = cheapest->suivant;
    }
    return (NULL);
}

static void    rest_rotation_a(t_noeud **a, t_noeud *cheapest)
{
    while (cheapest->indice)
    {
        if (cheapest->au_dessus_median)
            rotate(a, true, true);
        else
            rrotate(a, true, true);
    }
}

static void    rest_rotation_b(t_noeud **b, t_noeud *cheapest)
{
    while (cheapest->indice)
    {
        if (cheapest->au_dessus_median)
            rotate(b, true, false);
        else
            rrotate(b, true, false);
    }
}


void move_b_vers_a(t_noeud **a, t_noeud **b)
{
	t_noeud *cheapest;

    cheapest = find_cheapest(b);
    if (!cheapest->au_dessus_median && !cheapest->noeud_cible->au_dessus_median)
            while (cheapest != *b && cheapest->noeud_cible != *a)
                double_rrotate(a, b);
    else if (cheapest->au_dessus_median && cheapest->noeud_cible->au_dessus_median)
            while (cheapest != *b && cheapest->noeud_cible != *a)
                double_rotate(a, b);
    rest_rotation_b(b, cheapest);
    rest_rotation_a(a, cheapest->noeud_cible);
    push(a, b, true);
}


