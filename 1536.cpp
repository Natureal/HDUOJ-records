////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-25 02:21:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1536
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int k,num[105],m,l,sg[10005];

//hash: sg value exist ( mex(sg))
int SG_dfs(int x)
{
    if(sg[x] != -1)
        return sg[x];
    bool hash[105];
    memset(hash,0,sizeof(hash));
    for(int i = 1; i <= k; i++)
    {
        if( x >= num[i])
        {
            SG_dfs(x - num[i]);
            hash[sg[x- num[i]]] = 1;
        }
    }
    int e;
    for(int i = 0; i <= x ; i++)
    {
        if(hash[i] == 0)
        {
            e = i;
            break;
        }
    }
    return sg[x] = e;
}
int main()
{
    while(scanf("%d",&k)!=EOF && k)
    {
        memset(sg,-1,sizeof(sg));
        for(int i = 1; i <= k; i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+k);
        scanf("%d",&m);
        while(m --)
        {
            int ans = 0,temp;
            scanf("%d",&l);
            while(l --)
            {
                scanf("%d",&temp);
                ans ^= SG_dfs(temp);
            }
            if(ans)
                printf("W");
            else
                printf("L");
        }
        puts("");
    }
    return 0;
}
