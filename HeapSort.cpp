// MAX-HEAPIFY(A,i)
// l <- LEFT(i)
// r <- RIGHT(i)
// if l<=heap-size[A] and A[l]>A[i]
//   then largest <- l
//   eles largest <- i
// if r<=heap-size[A] andl A[r]>A[largest]
//   then largest <- r
// if largest != i
// then exchange A[i] <-> A[largest]
//      Max-heapify(A, largest)
//BUILD-MAX-HEAP(A)
// Heap-size[A]<-length[A]
// for i<-[length[A]/2]downto 1
//   do MAX-HEAPIFY(A,i)
// HEAPSORT(A)
// BUILD-MAX-HEAP(A)
// for i <- length[A] downto 2
//   do exchange A[1] <-> A[i]
//      heap-size[A] <->heap-size[A]-1
//   MAX-HEAPIFY(A,1)
#define PARENT(i) i/2
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1

void MaxHeapify(int* A, int i, int heapsize)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = i;
	if (l <= heapsize && A[l-1] > A[i-1])
	{
		largest = l;
	}

	if (r <= heapsize && A[r-1] > A[largest-1])
	{
		largest = r;
	}

	if (largest != i)
	{
		int temp = A[i-1];
		A[i-1] = A[largest -1];
		A[largest -1] = temp;
		MaxHeapify(A, largest, heapsize);
	}
}

void BuildMaxHeap(int *A, int length)
{
	int heapsize = length;
	for (int i = length / 2; i > 0; i--)
	{
		MaxHeapify(A, i, heapsize);
	}
}

void HeapSort(int *A, int length)
{
	BuildMaxHeap(A, length);
	int heapsize = length;
	for (int i = length; i > 0; i--)
	{
		int temp = A[0];
		A[0] = A[i-1];
		A[i-1] = temp;
		heapsize--;
		MaxHeapify(A, 1, heapsize);
	}
}
