#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void PrintArray(vector<int>& _v)
{
	for(int i=0;i<_v.size();++i)
			cout<< _v[i] << ".....";
	cout << endl;
}
int merge(vector<int>& _v,int p,int q,int r)
{
		int n1= q-p+1;
		int n2= r-q;
		vector<int> v1(n1+1);
		vector<int> v2(n2+1);
		int k=p;
		for(int i=0;i<n1;++i,++p) v1[i]=_v[p];
		for(int j=0;j<n2;++j,++q) v2[j]=_v[q+1];
		v1[n1]=99999;
		v2[n2]=99999;
		int i=0;
		int j=0;
		int count =0;
		for(int m=k;m<r;++m)
		{
			if(v1[i] < v2[j])
			{
				_v[k]=v1[i];
				i++;
			}
			else
			{
				++count;
				_v[k]=v2[j];
				j++;
			}
		}
		return count;
}
int InversionCount(vector<int>& _v,int p,int q)
{
	int count =0;
		if(p<q)
		{
			int mid = floor((q+p)/2);
			count= count+InversionCount(_v,p,mid)+InversionCount(_v,mid+1,q)+merge(_v,p,mid,q);
		}
		return count;
}
#if 0
int InversionCount(vector<int> v,int p,int r)
{
   int count =0;
   if(p < r)
   {
   		int q = floor((p+r)/2);
   		count = count+InversionCount(v,p,q);
		count = count+InversionCount(v,q+1,r);
		count = count+merge(v,p,q,r);
   }
   return count;
}
#endif
int main()
{
   //vector<int> v ={5,2,4,6,1,3};
   vector<int> v ={1,1,1,2,2};
   vector<int> v2 ={2,1,3,1,2};
   vector<int> v3 ={1,20,6,4,5};
   std::cout << InversionCount(v,0,4) << std::endl;
   std::cout << InversionCount(v2,0,4) << std::endl;
   std::cout << InversionCount(v3,0,5) << std::endl;
   return 0;
}
