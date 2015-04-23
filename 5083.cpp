////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-25 23:55:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5083
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 25 Oct 2014 07:12:03 PM CST
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

int flag,a,b,c;
char tmp1,tmp2;
char s1[100],s2[100],s3[100];
char a1[100],a2[100],a3[100];

int main(){
	while(scanf("%d",&flag) != EOF){
		if(flag == 1){
			a = b = 0;
			scanf("%s%c",s1,&tmp1);
			scanf("%c%d",&tmp1,&a);
			if(strcmp(s1,"SET") == 0){
				printf("000110");
			}
			else{
				scanf(",%c%d",&tmp2,&b);
				if(strcmp(s1,"ADD") == 0)
					printf("000001");
				else if(strcmp(s1,"SUB") == 0)
					printf("000010");
				else if(strcmp(s1,"DIV") == 0)
					printf("000011");
				else if(strcmp(s1,"MUL") == 0)
					printf("000100");
				else if(strcmp(s1,"MOVE") == 0)
					printf("000101");
			}
			for(int i = 0; i < 5; ++i){
				if((1 << (4 - i)) & a)
					a2[i] = '1';
				else
					a2[i] = '0';
				if((1 << (4 - i)) & b)
					a3[i] = '1';
				else
					a3[i] = '0';
			}
			a2[5] = '\0';
			a3[5] = '\0';
			printf("%s%s\n",a2,a3);
		}
		else{
			c = 0;
			scanf("%s",s1);
			for(int i = 0; i < 6; ++i){
				if(s1[i] == '1'){
					c += (1 << (5 - i));
				}
			}
			a = b = 0;
			for(int i = 6; i < 11; ++i){
				if(s1[i] == '1'){
					a += (1 << (10 - i));
				}
			}
			for(int i = 11; i < 16; ++i){
				if(s1[i] == '1'){
					b += (1 << (15 - i));
				}
			}
			if(c < 1 || c > 6){
				printf("Error!\n");
				continue;
			}
			if(c == 6){
				if(a < 1 || a > 31 || b != 0){
					printf("Error!\n");
					continue;
				}
				printf("SET");
				printf(" R%d\n",a);
			}
			else{
				if(a < 1 || a > 31 || b < 1 || b > 31){
					printf("Error!\n");
					continue;
				}
				if(c == 1) printf("ADD");
				else if(c == 2) printf("SUB");
				else if(c == 3) printf("DIV");
				else if(c == 4) printf("MUL");
				else if(c == 5) printf("MOVE");
				printf(" R%d,R%d\n",a,b);
			}
		}
	}
	return 0;
}



