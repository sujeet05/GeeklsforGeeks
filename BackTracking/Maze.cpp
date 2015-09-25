#include<iostream>
#include<vector>
#include<map>

struct path
{
	public:
	int x;
	int y;
};

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
void printPath(vector<vector<path>>& _p)
{
	for(auto i:_p){
		cout << endl;
	for(auto j:i)
	cout << j.x << "," << j.y << "....";}
}
void addpath(vector<vector<path>>& _p,vector<path>&_v)
//vector<vector<int>> addpath(vector<path>&_v)
{
	_p.push_back(_v);
}
void mazeTravel(vector<vector<int>>& _v,int i,int j,vector<vector<path>>& _p,vector<path>& _temp)
//void mazeTravel(vector<vector<int>>& _v,int i,int j,vector<path>& _temp)
{
	if (i ==3 && j==3) {
			path t;
			t.x=i;
			t.y=j;
			_temp.push_back(t);
				_v[i][j]=1;
			addpath(_p,_temp);
				_temp.pop_back();
			return;}
	else if(i <4 && j <4 && _v[i][j] == 1)
	{
		         path _path;
			    _path.x =i;
				_path.y =j;
				_temp.push_back(_path);
				_v[i][j]=2;
				mazeTravel(_v,i,j+1,_p,_temp);
				mazeTravel(_v,i+1,j,_p,_temp);
				_v[i][j]=1;
				_temp.pop_back();
	}
}
int main()
{
	int _rows;
	int _cols;
	vector<vector<path>> _p;
	vector<path> _temp;
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
	mazeTravel(v,0,0,_p,_temp);
	PrintInput(v);

	cout << endl;
	printPath(_p);
	cout << endl;
	return 0;
}
