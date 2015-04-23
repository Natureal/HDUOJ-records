////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-15 21:31:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5105
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 15 Nov 2014 07:15:10 PM CST
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

double a,b,c,d,L,R;
double ans[10];
int cnt;

double F(double x){
	return fabs(a * x * x * x + b * x * x + c * x + d);
}

int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R) != EOF){
		cnt = 0;
		if(a != 0){
			double tri = b * b - 3.0 * a * c;
			if(tri > eps){
				double x1 = (-b + sqrt(tri * 1.0)) / (3.0 * a);
				double x2 = (-b - sqrt(tri * 1.0)) / (3.0 * a);
				if(x1 - L > eps && R - x1 > eps){
					ans[cnt++] = F(x1);
				}
				if(x2 - L > eps && R - x2 > eps){
					ans[cnt++] = F(x2);
				}
			}
		}
		else{
			if(b != 0){
				double x = -c / (2.0 * b);
				if(x - L > eps && R - x > eps){
					ans[cnt++] = F(x);
				}
			}
		}
		ans[cnt++] = F(L);
		ans[cnt++] = F(R);
		sort(ans,ans + cnt);
		printf("%.2f\n",ans[cnt - 1]);
	}
	return 0;
}