#include "../push_swap.h"

void    swap(t_noeud **a, bool sig, bool a_b)
{
	// t_noeud	*head;
	// t_noeud	*led;

	// if (!(*a))
	// 	return ;
	// head = (*a)->suivant;
	// if (!head)
	// 	return ;
	// (*a)->suivant = NULL;
	// led = head->suivant;
	// head->suivant = NULL;
	// head->suivant = *a;
	// (*a)->suivant = led;
	// *a = head;
	t_noeud *first;
    t_noeud *last;

    if (!(*a) || !(*a)->suivant)
        return ;
    first = *a;
    last = first->suivant;

    first->suivant = last->suivant;
    first->precedent = last;
    last->precedent = NULL; 
    last->suivant = first;

    if(first->suivant)// ca ila kan troisieme element
        first->suivant->precedent = first;
    *a = last;
    set_index(*a);
    if (sig && a_b)
        write (1, "sa\n", 3);
    else if (sig && !a_b)
        write (1, "sb\n", 3);
}

void double_swap(t_noeud **a, t_noeud **b)
{
    swap(a, false, true);
    swap(b, false, false);
    write(1, "ss\n", 3);
}