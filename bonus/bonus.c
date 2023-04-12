





int	main(int argc, char **argv)
{
	t_lst *a;
	t_lst *new_elem;
	int i;
	
	new_elem = NULL;
	a = lstnew(ft_atoi(argv[1]));
	if (!a)
    	return (printf("Error\n"), 1);
	i = 2;
	while (i < argc)
	{
		new_elem = lstnew(ft_atoi(argv[i]));
		if (!new_elem)
			return (printf("Error\n"), free_list(&a), 1);
		pile_addback(&a, new_elem);
		i++;
	}
	free_list(&a);
	return (0);
}