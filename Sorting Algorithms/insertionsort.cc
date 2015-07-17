//Shannon Rhodes
//ECE 2060-001
//.cc file for the insertion sort functions for Lab 5

void insertionsort(long signed int* data, long signed int n)
{
	for (int i = 1; i < n; i++)
	{
		for(int k = i; (k > 0) && (data[k] < data[k-1]);k--)
		{
			//swap elements of the array
			int temp = data[k];
			data[k] = data[k-1];
			data[k-1] = temp;
		}
	}
}