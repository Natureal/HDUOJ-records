////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-01 00:36:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4987
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2588KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: c.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 31 Aug 2014 06:59:21 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
double dp[2000005];
double s[2000005];

int main(){
	while(scanf("%d%d",&m,&n) == 2){
		if(m >= 600000) printf("0.00000\n");
		else{
			if(n <= m) printf("%.5f\n",pow(1.0 + 1.0 / m,n - 1.0) / m);
			else{
				dp[0] = s[0] = 1;
				for(int i = 1; i <= n; ++i){
					if(i <= m) dp[i] = s[i - 1] / m;
					else dp[i] = (s[i - 1] - s[i - m - 1]) / m;
					s[i] = s[i - 1] + dp[i];
					if(i >= m && fabs(dp[i] - 2.0 / (m + 1)) <= 1e-9){
						n = i;
						break;
					}
				}
				printf("%.5f\n",dp[n]);
			}
		}
	}
	return 0;
}
