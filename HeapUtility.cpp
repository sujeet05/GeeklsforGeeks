#include<iostream>
#include <math.h>

int  size =10;
using namespace std;

int find_maxOf_three(int x,int y,int z)
{
		return (x>y)?(x>z?x:z ):(y>z ?y:z);
}
int find_min_of_three(int x,int y,int z)
{
	 return (x<y)?(x<z?x:z):(y<z ? y:z);
}
int parent(int i) {return floor(((i-1)/2));}
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
int Heap_maximum(int arr[])
{
	Build_Max_Heap(arr);
	return arr[0];
}
int Heap_Minimum(int arr[])
{
	Build_Min_Heap(arr);
	return arr[0];
}
int Heap_Extract_Maximum(int arr[])
{
	Build_Max_Heap(arr);
	int _ret=0;
	if(size <0)
		_ret=-1;
	else
	{
		_ret= arr[0];
		arr[0] =arr[size-1];
		size=size-1;
		Max_HeapIFY(arr,0);
	}
		return _ret;
}
int Heap_Extract_Miinimum(int arr[])
{
	Build_Min_Heap(arr);
	int _ret=0;
	if(size <0)
			_ret =-1;
	else
	{
		_ret= arr[0];
		arr[0]=arr[size-1];
		size=size-1;
		Min_HeapIFY(arr,0);
	}
	return _ret;
}
void Heap_increase_key(int arr[],int key,int i)
{
	if(key < arr[i])
	{
		cout << "key is lesser than already it has.."<< endl;
		return;
	}
	arr[i]=key;
	while( i >0 &&  arr[parent(i)] <arr[i])
	{
		 swap(&arr[parent(i)],&arr[i]);
		 i = parent(i);
	}
}
void Max_Heap_insert(int arr[],int key)
{
	arr[size-1] =-9999; // Assuming array size is incerased by i here 
	Heap_increase_key(arr,key,9);
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
//	std::cout <<"Heap MAximum.." << Heap_maximum(arr)<< std::endl;
//	std::cout <<"Heap Extract Maximum..." << Heap_Extract_Maximum(arr)<< std::endl;
//	printArray(arr,9);
//	cout << "Build Min heap..." << endl;
//	Build_Min_Heap2(arr1);
//	printArray(arr1,10);
//	size =10;
//	std::cout <<"Heap Minimum.." << Heap_Minimum(arr1)<< std::endl;
//	std::cout <<"Heap Extract Minimum..." << Heap_Extract_Miinimum(arr1)<< std::endl;
//	printArray(arr1,9);
	Build_Max_Heap(arr);
	Max_Heap_insert(arr,90);
	printArray(arr,10);
	//Heap_increase_key(arr,26,3);
}

