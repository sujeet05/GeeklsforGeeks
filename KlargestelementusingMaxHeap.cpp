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

void Max_HeapIFY(int arr[],int i)
{
	int largest =i;
	if(i <size && left(i) < size && arr[left(i)] > arr[i])
	  largest= left(i);
	if(i <size && right(i) < size && arr[right(i)] > arr[largest])
	  largest= right(i);
	if(largest != i)
		{
			swap(&arr[largest],&arr[i]);
			Max_HeapIFY(arr,largest);
		}

}
void Max_HeapIFY_iterative(int arr[],int i)
{
	int largest =i;
	while(i< size)
	{
	   if(left(i)< size && arr[left(i)] > arr[i])
			   largest = left(i);
	    if(right(i) < size && arr[right(i)] > arr[largest])
			   largest = right(i);
	   if(largest !=i)
	   {
			  swap(&arr[largest],&arr[i]);
			  i= largest;
	   }
	   else 
			break;
	}
}
void Build_Max_Heap(int arr[])
{
	for(int i=floor((size-1)/2);i >=0;--i)
		Max_HeapIFY_iterative(arr,i);
}

void Build_Max_Heap2(int arr[])
{
	for(int i=floor((size-1)/2);i >=0;--i)
		Max_HeapIFY(arr,i);
}
void klargestelement(int arr[],int k)
{
		Build_Max_Heap(arr);
		for(int i=0;i<k;i++)
		{
			cout << arr[0];
			arr[0]=arr[size-1];
			size=size-1;
			Build_Max_Heap(arr);
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
	klargestelement(arr,k);
}

