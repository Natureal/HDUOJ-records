////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-06 20:42:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5060
////Problem Title: 
////Run result: Accept
////Run time:2734MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 05 Oct 2014 06:54:51 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
const double PI = acos(-1.0);

double R,HR,HZ;
double v1,v2,vi,t,d,vsum;

int main(){
	while(scanf("%lf%lf%lf",&R,&HR,&HZ) != EOF){
		v1 = 4.0 * PI * R * R * R / 3.0;
		v2 = PI * HR * HR * 2.0 * HZ;
		d = HR * HR + HZ * HZ;
		vsum = v1 + v2;
		if(HZ >= R && HR >= R){
			printf("%.6f\n",v1 / v2);
		}
		else if(d <= R * R){
			printf("%.6f\n",v2 / v1);
		}
		else if(HZ < R && HR > R){
			vi = 2.0 * PI * R * R * HZ - 2.0 * PI * HZ * HZ * HZ / 3.0;
			printf("%.6f\n",vi / (vsum - vi));
		}
		else if(HZ > R && HR < R){
			t = sqrt(R * R - HR * HR);
			vi = 4.0 * PI * (R * R * R - t * t * t) / 3.0;
			printf("%.6f\n",vi / (vsum - vi));
		}
		else{
			t = sqrt(R * R - HR * HR);
			vi = 4.0 * PI * (R * R * R - t * t * t) / 3.0;
			vi -= 2 * PI * (R - HZ) * (R - HZ) * (R - (R - HZ) / 3.0);
			printf("%.6f\n",vi / (vsum - vi));
		}
	}
	return 0;
}
