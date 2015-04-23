////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-25 22:35:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1848
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAXN 1000

int num,fibo[105],sg[MAXN + 5] = {0};
void init()
{
    int i;
    fibo[1] = 1;
    fibo[2] = 2;
    for(i = 3;; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        if(fibo[i] > MAXN)
            break;
    }
    num = i - 1;
    return;
}
void init_sg()
{
    for(int i = 1; i <= MAXN; i++)
    {
        bool hash[MAXN + 5] = {0};
        for(int j = 1; j <= num; j++)
        {
            if(i - fibo[j] >= 0)
                hash[sg[i - fibo[j]]] = 1;
        }
        for(int j = 0; j <= i; j++)
        {
            if(hash[j] == 0)
            {
                sg[i] = j;
                break;
            }
        }
    }
    return;
}
int main()
{
    init();
    init_sg();
    int m,n,p;
    while(scanf("%d %d %d",&m,&n,&p) !=EOF)
    {
        if(m == 0 && n == 0 && p == 0)
            break;
        int ans = 0;
        ans ^= sg[m];
        ans ^= sg[n];
        ans ^= sg[p];
        if(ans)
        {
            printf("Fibo\n");
        }
        else
        {
            printf("Nacci\n");
        }
    }
    return 0;
}
