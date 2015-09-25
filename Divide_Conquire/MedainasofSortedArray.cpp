#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<int> Vector;

int getmedian(Vector& v1,Vector& v2)
{
	int median_index=(v1.size()+v2.size())%2 !=0 ? floor((v1.size()+v2.size())/2)+1:(v1.size()+v2.size())/2;
	int count= median_index; 
	int vi=0;
	int vj=0;
	int median;
	while(count-- > 0)
	    median= v1[vi] < v2[vj] ? v1[vi++] : v2[vj++];
    if((v1.size()+v2.size())%2!=0) return median;
	else if (vi < v1.size())
		   	return (median+v1[vi])/2;
	else 	    
		return (median+v2[vj])/2;
}

int main()
{
	Vector v2 {1,2,3,4,5,6,7,8};
	Vector v3 {1,2,3,4,5,6,7};
	Vector v1 {11,12,13,14,15,16,17};
	Vector v4 {11,22,33,44,55,66,77};
	Vector v5 {11,20,30,40,50,60,70};
	cout << getmedian(v1,v2)<< endl;
	cout << getmedian(v1,v3)<< endl;
	cout << getmedian(v4,v5)<< endl;
	
}
