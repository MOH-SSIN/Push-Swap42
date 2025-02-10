#include "push_swap.h"

static bool is_true(t_noeud *a)
{
    while (a)
    {
        if (a->appartient == false)
            return (1);
        a = a->suivant;
    }
    return (0);
}


void push_non_list(t_noeud **a, t_noeud**b)
{
    t_noeud *tmp;

    while (is_true(*a))
    {
        set_index(*a);
        tmp = *a;
        if ((tmp)->appartient)
            rotate(a, true, true);
        else
            push(b, a, false);
        tmp = (tmp)->suivant;
    }
}


t_noeud *ft_Get_PtitdNode(t_noeud *a)//5asni ndirha machi statick
{
    t_noeud *ptit_valeur;
    
    if (!a)
        return (NULL);
    ptit_valeur = a;
    while (a)
    {
        if (a->valeur < ptit_valeur->valeur)
            ptit_valeur = a;
        a =a->suivant;
    }
    return (ptit_valeur);
}

void	set_index(t_noeud *pile)
{
	int i;

    i = -1;
    while (pile)
    {
        pile->indice = ++i;
        pile = pile->suivant;
    }
}

void case_grand_pile(t_noeud **a,t_noeud **b)
{
    t_noeud *ptit;
    
    push_non_list(a,b);
    while (*b)
    {
        init_pile(a,b);
        move_b_vers_a(a,b);
    }
    ptit = ft_Get_PtitdNode(*a);
    if (ptit->au_dessus_median)
        while (*a != ptit)
            rotate(a, true, true);
    else
        while (*a != ptit)
            rrotate(a, true, true);
}























    // while (*b)
    // {
    //     init_pile(*a ,*b);
    //     move_b_vers_a(a, b);
    // }
    // set_index(*a);// kina f fichier case_grand_pile
    // ptit = ft_Get_PtitdNode(*a);
    // if (ptit->au_dessus_median)
    //     while (*a != ptit)
    //         ra(a, false);
    // else
    //     while (*a != ptit)
    //         rra(a, false);
