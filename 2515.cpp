////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-07-08 21:48:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2515
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){

	int tmp,n,sum,s[5000],hash[10005],num[55],cnt = 0;
	memset(hash,0,sizeof(hash));
	scanf("%d",&n);
	sum = n * (n - 1) / 2;
	for(int i = 0; i < sum; ++i){
		scanf("%d",&s[i]);
		hash[s[i]]++;
	}
	sort(s,s + sum);
	for(int i = 2; i < sum; ++i){
		tmp = s[0] + s[1] - s[i];
		if((int)(1.0 * tmp) / 2 == tmp / 2){
			int a = tmp / 2;
			while(cnt < n){
				for(int j = 0; j < cnt; ++j)
					hash[a + num[j]]--;
                num[cnt++] = a;
				for(int j = 0; j < sum; ++j)
					if(hash[s[j]]){
                        a = s[j] - num[0];
						break;
					}
			}
			break;
		}
	}
	for(int i = 0; i < cnt; ++i)
		printf("%d\n",num[i]);
	return 0;
}
