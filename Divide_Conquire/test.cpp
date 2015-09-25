#include <iostream>
#include <map>
using namespace std;

class A {
		int x;
		public: 
			A(int s): x(s) {}
			operator int() const {
				return x;
			}
};


int main() {

		A a(3); 
		map<int, string> m;
		m[a] = "suneet";
		cout << m[a] << endl;
		return 0;
}
