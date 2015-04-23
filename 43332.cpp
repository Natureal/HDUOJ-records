////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-17 01:09:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4333
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:2084KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn = 200010;

int T,len,ans1,ans2,ans3;
int next[maxn],P[maxn];
char s[maxn];

void Get_P(){
	P[0] = -1;
	int j = -1;
	for(int i = 1; i < len; ++i){
		while(j > -1 && s[j + 1] != s[i]) j = P[j];
		if(s[j + 1] == s[i]) j++;
		P[i] = j;
	}
}

void Ex_kmp(){
	int k = 0,j,p,L;
	next[0] = len;
	while(k < len - 1 && s[k + 1] == s[k]) k++;
	next[1] = k;
	k = 1;
	int top = len / 2;
	for(int i = 2; i < top; ++i){
		p = k + next[k] - 1,L = next[i - k];
		if(i + L > p){
			j = p - i + 1;
			if(j < 0) j = 0;
			while(i + j < len && s[i + j] == s[j]) j++;
			next[k = i] = j;
		}
		else next[i] = L;
	}
}

int main(){
	scanf("%d",&T); getchar();
	for(int tt = 1; tt <= T; ++tt){
		len = 0;
		char c = getchar();
		while(c != '\n') s[len++] = c,c = getchar();
		Get_P();
		int t = len - P[len - 1] - 1;
		len = t + len % t;
		for(int i = 0; i < len; ++i) s[i + len] = s[i];
		len *= 2;
		Ex_kmp();
		int top = len / 2;
		ans1 = ans2 = ans3 = 0;
		for(int i = 0; i < top; ++i){
			if(next[i] >= len / 2) ans2++;
			else if(s[i + next[i]] > s[next[i]]) ans3++;
			else ans1++;
		}
		printf("Case %d: %d %d %d\n",tt,ans1,ans2,ans3);
	}
	return 0;
}
