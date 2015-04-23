////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-19 12:14:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1084KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,m,f[100],i;
    f[0]=1;
    scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&m);
        	for(i = 1; i <= m; ++i){
				f[i] = f[i - 1];
				if(i > 1) f[i] += f[i - 2];
			}
			printf("%d\n",f[m - 1]);
		}
    return 0;
}
