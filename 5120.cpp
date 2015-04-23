////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-29 18:43:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5120
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:312KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: i.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 29 Nov 2014 03:55:06 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;
const double eps = 1e-8;
const double PI = acos(-1.0);

int T;
double r,R;
double x[2],y[2];

double Cal(double ax,double ay,double ar,double bx,double by,double br){
    double d = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    if(d >= ar + br)
        return 0.0;
    double minr = min(ar,br);
    if(d <= fabs(ar - br))
        return PI * minr * minr;
    double a1 = acos((ar * ar + d * d - br * br) / (2.0 * ar * d));
    double a2 = acos((br * br + d * d - ar * ar) / (2.0 * br * d));
    double ans = -d * ar * sin(a1);
    ans += a1 * ar * ar + a2 * br * br;
    return ans;
}

int main(){
    scanf("%d",&T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1]);
        printf("Case #%d: %.6f\n",tt,Cal(x[0],y[0],R,x[1],y[1],R) -
            2.0 * Cal(x[0],y[0],r,x[1],y[1],R) + Cal(x[0],y[0],r,x[1],y[1],r));
    }
    return 0;
}