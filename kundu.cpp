#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000000 + 7;
int main() {
		int N; cin >> N;
		vector<vector<int> > e(N+1, vector<int>(N+1,0));

		for(int i=1;i<N; ++i){
				int a,b; char c;
				cin >> a >> b >> c;
				if(c=='b')e[a][b] = 0;
				else e[a][b] = 1;
		}
		int res = 0;
		for(int i=1;i<N+1; ++i){
				for(int j=i+1; j<N+1; ++j){
						for(int k=j+1; k<N+1; ++k){
								bool a2b = false;
								bool b2c = false;
								for(int p=i;p<=j-1;++p){
//										cout<<"Between: "<< p << " " << p + 1<<endl;
										if(e[p][p+1]==1){a2b=true;break;}
								}
								for(int p=j;p<=k-1;++p){
//										cout<<"Between: "<< p << " " << p + 1<<endl;
										if(e[p][p+1]==1){b2c=true;break;}
								}
								if(a2b==true && b2c==true) res = (res+1)%MOD;
						}
						//if(e[i][j]==1) res = (res%MOD + (N-j)%MOD )%MOD;
				}
		}
		
		cout << res << endl;
		return 0;
}
