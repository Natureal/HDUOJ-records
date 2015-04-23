////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-06-02 11:02:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 126;
int main(){
	char str[6];
	int i,j,v,n;
	int f[maxn];
	while(scanf("%s %d",str,&n) != EOF){
		memset(f,0,sizeof(f));
		int flag = -1;//整数
		v = 0;
		for(i = 0; i < 6; i++){
			if(str[i] == '.') flag = i;
			else{
				v *= 10;
				v += (str[i] - '0');
			}
		}
		if(flag != -1){
			flag = 5 - flag;
			flag *= n;//小数点后数的个数
		}
		//normal
		if(flag != -1){
			for(i = 5; i >= 0; i--){
				if(str[i] == '.'|| str[i] != '0')break;
				else if(str[i] == '0'){
					flag -= n;
					v /= 10;
				}
			}
		}
		//printf("%d\n",v);
		f[0] = 1;
		int c;
		for(i = 0; i < n; i++){
			c = 0;
			for(j = 0; j < maxn; j++){
				int s = f[j] * v + c;
				f[j] = s % 10;
				c = s / 10;
			}
		}
		for(i = maxn - 1; i >= 0; i--){
			if(f[i]) break;
		}//找最大非零点
		if(flag == -1 || flag == 0){
			for(;i >= 0; i--){
				printf("%d",f[i]);
			}
			puts("");
		}
		else if(flag >= i + 1){
			printf(".");
			for(j = 0; j < flag - i - 1; j++){
				printf("0");
			}
			for(;i >= 0; i--){
				printf("%d",f[i]);
			}
			puts("");
		}
		else{
			for(;i >= flag; i--){
				printf("%d",f[i]);
			}
			printf(".");
			for(;i >= 0; i--){
				printf("%d",f[i]);
			}
			puts("");
		}
	}
	return 0;
}





