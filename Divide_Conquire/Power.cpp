#include<iostream>

using namespace std;
int power(int x,int y)
{
	if(y==0) return 1;
	else if (y %2 ==0)
		return power(x,y/2)*power(x,y/2);
	else
		return x*power(x,(y-1)/2)*power(x,(y-1)/2);
}
int main()
{
	cout << power(2,5) << endl;
	cout << power(2,6) << endl;
	cout << power(2,0) << endl;
	return 0;
}
