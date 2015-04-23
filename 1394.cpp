////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-15 22:23:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <functional>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
int arr[5005];
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int count=0;
        for(int i=0;i<t;i++)
        {
            scanf("%d",&arr[i]);
            for(int j=0;j<i;j++)
            {
                if(arr[j]>arr[i])
                {
                    count++;
                }
            }
        }
        int tcount=count;
        for(int i=0;i<t;i++)
        {
            tcount=tcount-2*arr[i]+t-1;
            if(tcount<count)
            {
                count=tcount;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
