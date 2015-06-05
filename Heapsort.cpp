#include<iostream>
#include <math.h>

//#define size 10
 int size =10;
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
void Min_HeapIFY_iterative(int arr[],int i)
{
	int smallest =i;
	while(i< size)
	{
	   if(left(i)< size && arr[left(i)] < arr[i])
			   smallest = left(i);
	    if(right(i) < size && arr[right(i)] < arr[smallest])
			   smallest = right(i);
	   if(smallest !=i)
	   {
			  swap(&arr[smallest],&arr[i]);
			  i= smallest;
	   }
	   else 
			break;
	}
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

void Build_Min_Heap(int arr[])
{
	for(int i=floor((size-1)/2);i >=0;--i)
		Min_HeapIFY_iterative(arr,i);
}

void Build_Min_Heap2(int arr[])
{
	for(int i=floor((size-1)/2);i >=0;--i)
		Min_HeapIFY(arr,i);
}
void Heapsort(int arr[])
{
	Build_Max_Heap(arr);
	while(size >0)
	{
		swap(&arr[0],&arr[size-1]);
		--size;
		Max_HeapIFY(arr,0);
	}
}
int main()
{
	std::cout << find_maxOf_three(4,5,2);
	std::cout << find_maxOf_three(7,5,2);
	std::cout << find_maxOf_three(4,5,10);
	std::cout << endl;
	std::cout << parent(9);
	std::cout << left(4);
	std::cout << right(4) << endl;
	int arr[10] ={16,4,10,14,7,9,3,2,8,1};
	int arr1[10] ={16,4,10,14,7,9,3,2,8,1};
//	swap(&arr[0],&arr[1]);
	printArray(arr,10);
	std::cout << "End test utility..." << endl;
//	Min_HeapIFY(arr,0);
//	printArray(arr,10);
//	Min_HeapIFY(arr,0);
//	Build_Max_Heap(arr);
//	cout << "Build Max heap..." << endl;
//	printArray(arr,10);
//	cout << "Build Min heap..." << endl;
//	Build_Min_Heap2(arr1);
//	printArray(arr1,10);
	Heapsort(arr);
	cout << "Heap sort..." << endl;
	printArray(arr,10);
}

