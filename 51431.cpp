////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-13 22:52:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5143
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1088KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.cpp
    > Author: Natureal
    > Mail: 564374850@qq.com 
    > Created Time: Sat 13 Dec 2014 07:11:10 PM CST
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
typedef unsigned long long ull;
const int INF = 1 << 30;

int n;
int a,b,c,d;

int main(){
	scanf("%d",&n);
	//freopen("bc2.in","r",stdin);
	//freopen("bc1.out","w",stdout);
	for(int t = 1; t <= n; ++t){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int flag = 0;
		for(int i = 0; !flag && i < 3; ++i){
			for(int j = 0; !flag && j < 3; ++j){
				for(int k = 0; !flag && k < 3; ++k){
					int a1 = a - i - j;
					int b1 = b - i - j - k;
					int c1 = c - i - j - k;
					int d1 = d - j - k;
					if((a1 >= 3 || a1 == 0) && (b1 >= 3 || b1 == 0) && 
							(c1 >= 3 || c1 == 0) && (d1 >= 3 || d1 == 0)){
						flag = 1;
						break;
					}
				}
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
	
