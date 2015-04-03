//BinarySearch
//Input sort array A, length, x
//binarySearch(int *A, int startIndex,int endIndex, int x)
//1 int mid = endIndex-startIndex/2
//2 if x < A[mid]
//3    do binarySearch(A,startIndex,mid,x)
//4 else if x > A[mid]
//5    do binarySearch(A,mid,endIndex,x)
//6 else
//7    do return mid
int binarySearch(const int *A, int startIndex,int endIndex, int x)
{
	int mid = (endIndex - startIndex) / 2;
	if (x == A[mid])
	{
		return mid;
	}
	else if (x < A[mid])
	{
		binarySearch(A, startIndex, mid, x);
	}
	else
	{
		binarySearch(A, mid, endIndex, x);
	}
}
