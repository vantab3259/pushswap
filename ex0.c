/*#include "ex0.h"

int estVide(t_list *liste)
{
    return (liste == NULL)? 1 : 0;
}
void afficherListe(t_list *list)
{
    t_list *tmp = list;
    while(tmp != NULL)
    {
        printf("%d", tmp->val);
        On avance d'une case 
        tmp = tmp->next;
    }
	printf("\n");
}

t_list	*ajt_en_tete(t_list *list, int valleur)
{
	t_list *new = malloc(sizeof(t_list));
	new->val = valleur;
	new->next = list;
	return (new);
}

t_list	*ajt_en_fin(t_list *list, int valleur)
{
	t_list *new = malloc(sizeof(t_list));
	new->val = valleur;
	new->next = NULL;
	if(list == NULL)
		return(new);
	else
	{
		t_list	*temp = list;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
	temp->next = new;
	return(list);
	}
}


t_list	*sup_element_tete(t_list *premiere_position)
{
	if(premiere_position != NULL)
	{
		t_list *second_position = premiere_position->next;
		free(premiere_position);
		return (second_position);
	}
	else
		return(NULL);
}

t_list	*sup_element_fin(t_list *list)
{
	if(list == NULL)
		return(NULL);
	if(list->next == NULL)
	{
		free (list);
		return(NULL);
	}

	t_list *temp = list;
	t_list *ptmp = list;
	while(temp->next != NULL)
	{
		ptmp = temp;
		temp = temp->next;
	}
	ptmp->next = NULL;
	free(temp);
	return(list);

}

t_list	*rechercherElement(t_list *list, int valeur)
{
	if(estVide(list) == 0)
	{
		t_list *tmp = list;
		while (tmp != NULL)
		{
			if( tmp->val == valeur)
				return(tmp);
			tmp = tmp->next;
		}
		return(NULL);
	}

}

int	compte_occur(t_list *list, int val)
{
	if(estVide(list) == 0)
	{
		t_list tmp = list;
		while(liste = rechercherElement(tmp, 2) != NULL)
		{
			liste = liste->next;
			i++;
		}
	retunr(i);
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	t_list *list1 = NULL;
	
	while (i <= 10)
	{
		list1 = ajt_en_tete(list1, i);
		list1 = ajt_en_fin(list1, i);
		i++;
	}
	afficherListe(list1);
	list1 = sup_element_tete(list1);
	afficherListe(list1);
	list1 = sup_element_fin(list1);
	afficherListe(list1);
}*/