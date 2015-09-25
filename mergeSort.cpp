#include <iostream>
#include <limits.h>
using namespace std;


void merge(int A[], int p, int q, int r)
{
		int T[ r - p + 1];

		int i = p, j = q + 1, k = 0;

		while(k < r-p+1)
		{
				int t1 = i > q ? INT_MAX : A[i];
				int t2 = j > r ? INT_MAX : A[j];
				if( t1 <= t2 )
					   	T[k++] = A[i++];
				else 
						T[k++] = A[j++];
		}
		while(--k>=0) A[r--] = T[k];
}
void mergeSort(int A[], int p, int r)
{
		if( p < r)
		{
				mergeSort(A, p, (p+r)/2);
				mergeSort(A, (p+r)/2 + 1, r);
				merge(A, p, (p+r)/2 , r);
		}
}

int main()
{
		int A[9] = {- 2, 1, 9 , 5, 0, 8, -3, 23, 456};

		mergeSort(A,0,8);
		for(int i=0; i < sizeof(A)/sizeof(int); ++i) cout<< A[i] << " ";
		cout << endl;
		return 0;
}

