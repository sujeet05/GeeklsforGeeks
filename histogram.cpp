#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;
typedef vector<int> arr;

arr leftminarray(const arr& hist)
{
		arr out(hist.size());
		stack<int> S;
		for(int i=0;i<hist.size(); ++i)
		{
				while( !S.empty() && hist[S.top()] >= hist[i]) S.pop();
				if(!S.empty())out[i] = S.top();
				else out[i] = -1;
				S.push(i);
		}

		return out;
}
arr rightminarray(const arr& hist)
{
		arr out(hist.size());
		stack<int> S;
		for(int i=hist.size()-1 ;i>=0; --i)
		{
				while( !S.empty() && hist[S.top()] >= hist[i]) S.pop();
				if(!S.empty())out[i] = S.top();
				else out[i] = hist.size();
				S.push(i);
		}

		return out;
}
void print(const arr& array)
{
		cout<<"[";
		for(int c: array) cout<< c << ", ";
		cout<< "]" << endl;
}
int max_area(const arr& hist)
{
		int max_area = INT_MIN;
		arr left  = leftminarray(hist);
		arr right = rightminarray(hist);
		for(int i=0; i < hist.size(); ++i)
		{
				int area = (right[i]-left[i]-1 )*hist[i];
				if( area > max_area) max_area = area;
		}
		return max_area;
}


int main()
{
//	arr input = { 1,3,5,4,5,3,1,5};
	arr input = { 1,1,4,3};
	cout<< max_area(input) << endl;
	return 0;
}
