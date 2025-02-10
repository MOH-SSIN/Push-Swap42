#include "push_swap.h"

t_noeud *lstnew(char *args, int indice)
{
    t_noeud *new_1;

    new_1 = NULL;
    new_1 = (t_noeud *)malloc(sizeof(t_noeud));
    if (!new_1)
        return (NULL);
    new_1->indice = indice;
    new_1->valeur = ft_atoi(args);
    new_1->length = 1;
    new_1->sub =-1;
    new_1->sub_ptr =NULL;
    new_1->appartient = false;
    new_1->noeud_cible = NULL;
    new_1->suivant = NULL;
    new_1->precedent = NULL;
    return (new_1);
}

t_noeud *lslast(t_noeud *last)
{   
    if (!last)
        return (NULL);
    while (last->suivant)
        last = last->suivant;
    return (last); 
}

void lsadd_back(t_noeud **pile, t_noeud *new_1)
{
    t_noeud *last;

    if (!new_1)
        return ;
    if (!*pile)
        *pile = new_1;
    else
    {
        last = *pile;
        last = lslast(*pile);
        last->suivant = new_1;
        new_1->precedent = last;
    }
}

void	lstadd_front(t_noeud **lst, t_noeud *new_1)
{
	if (!lst || !new_1)
		return ;
	new_1->suivant = *lst;
	*lst = new_1;
}

t_noeud *ajouter_noeud(char **args)
{
    t_noeud *pile;
    int     i;

    i = 0;
    pile = NULL;
    while (args[i])
    {
        lsadd_back(&pile ,lstnew(args[i], i));
        i++;
    }
    if (pile_trie(pile))
    {
        liberer_erreurs(args);
        free_pile(pile);
        exit(0);
    }
    // printf("hhh\n");
    // printf("***************************\n");
    // afficher_pile(pile);
    // printf("***************************\n");
    ft_lis(&pile);
    // printf("apres_ft_lis\n");
    liberer_erreurs(args);
    return (pile);
}







