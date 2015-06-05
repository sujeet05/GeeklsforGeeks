#include<iostream>
#include <math.h>

//#define size 10
 int size =7;
using namespace std;

int find_maxOf_three(int x,int y,int z)
{
		return (x>y)?(x>z?x:z ):(y>z ?y:z);
}
int find_min_of_three(int x,int y,int z)
{
	 return (x<y)?(x<z?x:z):(y<z ? y:z);
}
int parent(int i) {return floor((i-1/2));}
int left(int i){return ((2*i)+1);}
int right(int i){return( (2*i)+2);}

void printArray(int arr[],int n)
{
	for(int i =1;i<=n;i++)
			cout << arr[i-1] << "..";
	cout<<endl;
}
void swap(int *x,int *y)
{
    int temp = *x;
	*x= *y;
	*y=temp;
}

void Min_HeapIFY(int arr[],int i)
{
	int smallest =i;
	if(i <size && left(i) < size && arr[left(i)] < arr[i])
	  smallest= left(i);
	if(i <size && right(i) < size && arr[right(i)] < arr[smallest])
	  smallest= right(i);
	if(smallest != i)
		{
			swap(&arr[smallest],&arr[i]);
			Min_HeapIFY(arr,smallest);
		}

}
void Build_Min_Heap(int arr[])
{
	for(int i=floor((size-1)/2);i >=0;--i)
		Min_HeapIFY(arr,i);
}

void ksmallestelement(int arr[],int k)
{
		Build_Min_Heap(arr);
		for(int i=0;i<k;i++)
		{
			cout << arr[0];
			arr[0]=arr[size-1];
			size=size-1;
			Build_Min_Heap(arr);
		}
}
int main()
{
	int k;
	cout << "give the value of k to print k largest number " << endl;
	cin >> k;
	int arr[7] ={1, 23, 12, 9, 30, 2, 50};
	cout << "Given array is .." << endl;
	printArray(arr,7);
	ksmallestelement(arr,k);
}

