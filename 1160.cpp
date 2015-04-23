////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-16 15:07:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1160
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

typedef struct node
{
    int w;   //体重
    int s;   //速度
    int n;   //位置
}node;
node mice[1002];

int dp[1002];
int index[1002];
int a[1002];

int cmp(const void *a,const void *b)
{
    return (*(node *)a).w-(*(node *)b).w;
}
 
 

int main()
{
    int lv=1;
    int i,j,k,max;
    memset(index,-1,sizeof(index));

    while(scanf("%d%d",&mice[lv].w,&mice[lv].s)!=EOF)
    {
        mice[lv].n=lv;
        lv++;
    }
   
    qsort(mice,lv,sizeof(mice[0]),cmp);

    for(i=0;i<=lv;i++)
        dp[i]=1;
    for(i=2;i<lv;i++)
    {
        for(j=1;j<i;j++)
        {
            if(mice[i].s<mice[j].s)
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    index[mice[i].n]=mice[j].n;
                }
            }
        }
    }
   
    for(max=-1,i=1;i<=lv;i++)
        if(dp[i]>max)
        {
            max=dp[i];
            k=mice[i].n;
        }

    printf("%d\n",max);
    for(i=max;i>=1;i--)
    {
        a[i]=k;
        k=index[k];
    }
    for(i=1;i<=max;i++)
        printf("%d\n",a[i]);
    return 0;
}