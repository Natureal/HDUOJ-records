////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-06 16:27:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5199
////Problem Title: 
////Run result: Accept
////Run time:1965MS
////Run memory:2648KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 1000000000 + 5;
map<int,int> cnt;


void scan( int& x )
{
    char c;
    while( c = getchar(), c < '0' || c > '9' );
    x = c - '0';
    while( c = getchar(), c >= '0' && c <= '9' ) x = x * 10 + c - '0';
}

int main(){
	int n , m , h , q;

	while(scanf("%d%d",&n , &m) == 2){
		cnt.clear();
		for(int i = 0;i < n;++i){
			scan(h);
			++cnt[h];
		}

		for(int i = 0;i < m;++i){
			scan(q);
			printf("%d\n",cnt[q]);
			cnt[q] = 0;
		}
	}
    return 0;
}