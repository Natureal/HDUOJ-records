////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-25 23:55:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1001.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 25 Oct 2014 07:00:52 PM CST
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
	char s1[100],s2[100];
	char s3[100];
	while(scanf("%s%s",s1,s2) != EOF){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int pos1,pos2;
	for(int i = 0; i < len1; ++i) if(s1[i] == '_'){
		pos1 = i;
		break;
	}
	for(int i = 0; i < len2; ++i) if(s2[i] == '_'){
		pos2 = i;
		break;
	}
	int pos3 = 0;
	for(int i = pos1 + 1; i < len1; ++i){
		s3[pos3++] = s1[i];
	}
	s3[pos3++] = '_';
	char tmp[100] = "small";
	for(int i = 0; i < 5; ++i)
		s3[pos3++] = tmp[i];
	s3[pos3++] = '_';
	for(int i = pos2 + 1; i < len2; ++i){
		s3[pos3++] = s2[i];
	}
	s3[pos3] = '\0';
	printf("%s\n",s3);
	}
	return 0;
}
