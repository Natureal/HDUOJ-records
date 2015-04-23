////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 13:49:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1431
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:10056KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
#define MAXN 9989900
bool arr[MAXN+100];
void buildform()
{
    memset(arr,false,sizeof(arr));
    arr[1]=1;
    int k=sqrt(1.0*MAXN+99);
    for(int i=4;i<=MAXN;i+=2)
    {
        arr[i]=true;
    }
    for(int i=3;i<=k;i+=2)
    {
        for(int j=i*i;j<=MAXN+99;j+=i)
        {
            arr[j]=true;
        }
    }
    return;
}
bool judge(int x)//判断是否回文只要比较其本身和它的逆序数是否相等！！
{
    int temp=x;
    int b=0;
    while(temp!=0)
    {
        b=b*10;
        b+=temp%10;
        temp/=10;
    }
    return x==b;
}
int main()
{
    int a,b;
    buildform();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(b>MAXN)
        {
            b=MAXN;
        }
        for(int i=a;i<=b;i++)
        {
            if(!arr[i]&&judge(i))
            {
                printf("%d\n",i);
            }
        }
        puts("");
    }
    return 0;
}
