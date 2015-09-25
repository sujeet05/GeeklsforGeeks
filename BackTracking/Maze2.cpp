#include<iostream>
#include<vector>
#include<map>

using namespace std;
void ReadInput(vector<vector<int>>& _v)
{
		_v[0][0]=1;
		_v[0][1]=0;
		_v[0][2]=0;
		_v[0][3]=0;
		_v[1][0]=1;
		_v[1][1]=1;
		_v[1][2]=0;
		_v[1][3]=1;
		_v[2][0]=0;
		_v[2][1]=1;
		_v[2][2]=1;
		_v[2][3]=0;
		_v[3][0]=1;
		_v[3][1]=1;
		_v[3][2]=1;
		_v[3][3]=1;
}
void PrintInput(vector<vector<int>>& _v)
{
	for(auto i:_v){
		cout << endl;
	for(auto j:i)
	cout << j << "  ";}
}
void mazeTravel(vector<vector<int>>& _v,int i,int j)
{
	if (i ==3 && j==3) {_v[i][j]=2; return;}
	else if(i <4 && j <4 && _v[i][j] == 1)
	{
				_v[i][j]=2;
				mazeTravel(_v,i,j+1);
				mazeTravel(_v,i+1,j);
	}
}
int main()
{
	int _rows;
	int _cols;
	vector<vector<int>> v;
	cout << "NO of Rows..." ;
	cin >> _rows;
	cout << "No of cols...";
	cin >> _cols;
	for(int i=0;i<_rows;++i){
		vector<int> p(_cols);
		v.push_back(p);}
	ReadInput(v);
	PrintInput(v);
	cout << endl;
	mazeTravel(v,0,0);
	PrintInput(v);

	cout << endl;
	return 0;
}
