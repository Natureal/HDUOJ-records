////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-31 21:19:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4986
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:8080KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 31 Aug 2014 06:59:17 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const double V = 0.577218;
const double E = 2.718281828;

int n;
double ans[1000005];

void Pre(){
	ans[1] = 1;
	for(int i = 2; i <= 1000000; ++i){
		ans[i] = ans[i - 1] + (double)1 / i;
	}
}

int main(){
	Pre();
	while(scanf("%d",&n) == 1){
		if(n >= 1000000) printf("%.4lf\n",log(1.0 * n + 1) / log(E) + V);
		else printf("%.4lf\n",ans[n]);
	}
	return 0;
}
