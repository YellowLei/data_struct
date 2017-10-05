void quicksort(int left, int right)//快排
{
	int i, j;
	struct node t;
	if (left > right)
		return;

	i = left;
	j = right;

	while (i != j)
	{
		while (goods[j].q <= goods[i].q&&i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = goods[i];
			goods[i] = goods[j];
			goods[j] = t;
		}
	}

	t = goods[left];
	goods[left] = goods[i];
	goods[i] = t;

	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
