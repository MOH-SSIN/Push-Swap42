#include "push_swap.h"


static t_noeud *grand_element(t_noeud *a)
{
    t_noeud *temp;
    t_noeud *grand_node;

    temp =  a;
    grand_node = a;

    if (!a)
        return NULL;
    while (temp)
    {
        if(temp->valeur > grand_node->valeur)
            grand_node = temp;
        temp = temp->suivant;
    }
    return grand_node;
}

static void trier_trois(t_noeud **a)
{
    t_noeud * grand_node;
    
    grand_node = grand_element(*a);
    if (!(*a) || !(*a)->suivant->suivant)
        return ;
    if (*a == grand_node)// 30 50 20
        rotate(a, true, true);
    if ((*a)->suivant == grand_node)// 20 30 50
        rrotate(a, true, true);
    if((*a)->valeur > (*a)->suivant->valeur)// 20 30 50
        swap(a, true, true);
}


void case_ptit_piles(t_noeud **a)
{
    if (pile_taile(*a) == 2)
        swap(a, true, true);
    else if(pile_taile(*a) == 3)
        trier_trois(a);
}