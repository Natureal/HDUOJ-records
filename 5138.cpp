////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-06 21:52:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5138
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1156KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1001.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 06 Dec 2014 07:00:19 PM CST
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

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int head = 1;
		if(n > 15){
			if(!head) printf(" ");
			printf("%d",n - 15);
			head = 0;
		}
		if(n > 7){
			if(!head) printf(" ");
			printf("%d",n - 7);
			head = 0;
		}
		if(n > 4){
			if(!head) printf(" ");
			printf("%d",n - 4);
			head = 0;
		}
		if(n > 2){
			if(!head) printf(" ");
			printf("%d",n - 2);
			head = 0;
		}
		if(n > 1){
			if(!head) printf(" ");
			printf("%d",n - 1);
			head = 0;
		}
		printf("\n");
	}
	return 0;
}
