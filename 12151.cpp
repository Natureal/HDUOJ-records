////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 16:27:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define MAXN 500005
int arr[MAXN+5];
void facsum()
{
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=MAXN;i++)
    {
        for(int j=i+i;j<=MAXN;j+=i)
        {
            arr[j]+=i;
        }
    }
    return;
}
int main()
{
    facsum();
    int t,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("%d\n",arr[a]);
    }
    return 0;
}
