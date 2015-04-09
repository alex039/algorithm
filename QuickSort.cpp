// QUICKSORT(A,p,r)
// if p<r
//    then q<- PARTITION(A,p,r)
//     QUICKSORT(A,p,q-1)
//     QUICKSORT(A,q+1,r)
//PATRITION(A,p,r)
// x<-A[r]
// i<-p-1
// for j <-p to r-1
//    do if A[j]<=x
//       the i <- i+1
//            exchange A[i]<->A[j]
// exchange A[i+1]<->A[r]
// return i+1


int Partition(int *A, int p, int r)
{
	int i = p - 1;
	int x = A[r-1];
	for (int j = p; j < r; j++)
	{
		if (A[j-1] <= x)
		{
			i++;
			if (i != j)
			{
				int temp = A[i-1];
				A[i - 1] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
	int temp = A[i];
	A[i] = A[r - 1];
	A[r - 1] = temp;
	return i+1;
}
void QuickSort(int *A, int p, int r)
{
	if (p < r)
	{
		int q = Partition(A,p,r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}