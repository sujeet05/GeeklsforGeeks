#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class point {
		
		int x;
		int y;
		public:
			point(int _x, int _y):x(_x),y(_y){}
		int getX() const{ return x;}
		int getY() const{ return y;}
};

bool compare_y(const point& lhs, const point& rhs){
		return lhs.getY() <= rhs.getY();
}
bool compare_x(const point& lhs, const point& rhs){
		return lhs.getX() <= rhs.getX();
}

int dist(const point& lhs, const point& rhs){
		return (lhs.getX() - rhs.getX()) * (lhs.getX() - rhs.getX())  + (lhs.getY() - rhs.getY()) * (lhs.getY() - rhs.getY());
}
ostream& operator << (ostream& os,const point& p) {
		os << "(" << p.getX() << ","<< p.getY() << ")";
		return os;
}
int min(int x, int y, int z)
{
		return x < y ? ( x < z ? x : z): (y < z ? y : z);
}
int strip_closest_pair(vector<point>& Y, int d)
{
		int m = d;
		for(int i=0; i < Y.size(); ++i)
				for(int j = i+1; j< Y.size() && Y[j].getY()-Y[i].getY() < d; j++)
						m = min(m, dist(Y[i],Y[j]));
		return m;
}
int closest_pair(vector<point>& P,int s, int e) 
{
		int size = e-s+1;
		if(size == 1) return 0;
		if(size == 2) return dist(P[s], P[s+1]);
		if(size == 3) return min(dist(P[s], P[s+1]), dist(P[s+1], P[s+2]), dist(P[s], P[s+2]));
		if(size > 3)
		{
			int dl = closest_pair(P, s, (e+s)/2-1);
			int dr = closest_pair(P, (e+s)/2+1, e);
			int d  = min(dl,dr);
			Vector<point> Y;
			for(int i = s; i < size; ++i)
					if(abs(P[i].getX() - P[(s+e)/2].getX()) < d) Y.push_back(p);
			return min(d,strip_closest_pair(Y,d));
		}
}

int main() {


		point p(2,3), q(5,5), r(1,7);;

		vector<point> points;  
		points.push_back(p); 
		points.push_back(q);
		points.push_back(r);

		sort(points.begin(), points.end(), compare_y);
		for(point p: points) cout << p << " ";

		return 0;
}
