////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-31 16:46:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1576
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: hdu1576.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 31 Aug 2014 04:20:57 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int Ex_gcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int r = Ex_gcd(b,a % b,x,y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int T,n,B;

int main(){
	int x,y,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&B);
		//Bx1 + 9973y1 = gcd(B,9973) = 1
		d = Ex_gcd(B,9973,x,y);
		x *= n;
		while(x < 0) x += 9973;
		printf("%d\n",x);
	}
	return 0;
}
