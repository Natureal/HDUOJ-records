////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 15:29:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2824
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:23760KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN 3000000
long long eula[MAXN+1];
//void buildform()
//{
//    memset(arr,0,sizeof(arr));//0´ú±íËØÊý
//    arr[1]=1;
//    for(int i=4;i<=MAXN;i+=2)
//    {
//        arr[i]=1;
//    }
//    int k=sqrt(1.0*MAXN);
//    for(int i=3;i<=k;i+=2)
//    {
//        for(int j=i*i;j<=MAXN;j+=i)
//        {
//            arr[j]=1;
//        }
//    }
//    return;
//}
void buildeula()
{
    for(int i=1;i<=MAXN;i++)
    {
        eula[i]=i;
    }
    for(int i=2;i<=MAXN;i++)
    {
        if(i==eula[i])
        {
            for(int j=i;j<=MAXN;j+=i)
            {
                eula[j]=eula[j]/i*(i-1);
            }
        }
    }
    return;
}
//void buildsumeula()
//{
//    for(int i=2;i<=MAXN;i++)
//    {
//        eula[i]+=eula[i-1];
//    }
//    return;
//}
int main()
{
    //buildform();
    buildeula();
    //buildsumeula();
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        long long sum=0;
        for(int i=a;i<=b;i++)
        {
            sum+=eula[i];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
