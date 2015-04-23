////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-24 16:03:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4773
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1212KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const double eps = 1e-10;
const double PI = acos(-1.0);

double add(double a,double b){
	if(abs(a + b) < eps * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct Point{
	double x,y;
	Point(double tx = 0,double ty = 0) : x(tx),y(ty) {}
	Point operator + (Point p){
		return Point(add(x,p.x),add(y,p.y));
	}
	Point operator - (Point p){
		return Point(add(x,-p.x),add(y,-p.y));
	}
	Point operator * (double d){
		return Point(x * d,y * d);
	}
	Point operator / (double d){
		return Point(x / d,y / d);
	}
	Point Move(double a,double d){
		return Point(x + d * cos(a),y + d * sin(a));
	}
	void Read(){
		scanf("%lf%lf",&x,&y);
	}
};

struct Circle{
	Point o;
	double r;
	Circle(double tx = 0,double ty = 0,double tr = 0) : o(tx,ty),r(tr) {}
	void Read(){
		o.Read();
		scanf("%lf",&r);
	}
	void Out(){
		printf("%.8f %.8f %.8f\n",o.x,o.y,r);
	}
};

int Sign(double x){
	return (x > eps) - (x < -eps);
}

double Cross(Point a,Point b,Point c){
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double Dis(Point a,Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Circle c[5];
Point P;
int T,tot;
double R;

Circle Inver(Circle c1){
	Circle res;
	double oc1 = Dis(P,c1.o);
	double k1 = 1.0 / (oc1 - c1.r);
	double k2 = 1.0 / (oc1 + c1.r);
	res.r = 0.5 * (k1 - k2) * R * R;
	double oc2 = 0.5 * (k1 + k2) * R * R;
	res.o = P + (c1.o - P) * oc2 / oc1;
	return res;
}

void Mark(Point a,Point b){
	++tot;
	double t = fabs(Cross(a,P,b) / Dis(a,b));
	c[tot].r = R * R / (2.0 * t);
	double d = Dis(a,c[1].o);
	c[tot].o = P + (a - c[1].o) * (c[tot].r / d);
}

void Solve(){
	REP(i,2) c[i] = Inver(c[i]);
	if(c[1].r < c[2].r) swap(c[1],c[2]);
	Point tmp = c[2].o - c[1].o;
	double a1 = atan2(tmp.y,tmp.x);
	double a2 = acos((c[1].r - c[2].r) / Dis(c[1].o,c[2].o));
	Point P1 = c[1].o.Move(a1 + a2,c[1].r);
	Point P2 = c[2].o.Move(a1 + a2,c[2].r);
	if(Sign(Cross(P1,c[1].o,P2)) == Sign(Cross(P1,P,P2))) Mark(P1,P2);
	P1 = c[1].o.Move(a1 - a2,c[1].r);
	P2 = c[2].o.Move(a1 - a2,c[2].r);
	if(Sign(Cross(P1,c[1].o,P2)) == Sign(Cross(P1,P,P2))) Mark(P1,P2);
}

int main(){
	R = 10.0;
	scanf("%d",&T);
	REP(tt,T){
		tot = 2;
		REP(i,2) c[i].Read();
		P.Read();
		Solve();
		printf("%d\n",tot - 2);
		FOR(i,3,tot) c[i].Out();
	}
	return 0;
}
