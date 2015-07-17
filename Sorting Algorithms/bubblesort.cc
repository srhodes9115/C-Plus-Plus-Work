//Shannon Rhodes
//ECE 2060-001
//Bubblesort.cc file

void bubblesort(long signed int data[], long signed int n)
{
	long signed int temp = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1; j > i; --j)
		{
			if (data[j] < data [j-1])
			{
				//swaps the elements of the array
				temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
		}
	}
}