////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-17 19:03:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2553
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int n,c[11],tot;
void nqueen(int count)
{
    int i,j;
    if(count==n) tot++;
    else
    {
        for(i=0;i<n;i++)
        {
            int ok=1;
            c[count]=i;
            for(j=0;j<count;j++)
            {
                if(c[count]==c[j]||abs(c[j]-c[count])==abs(j-count))
                {
                    ok=0;
                    break;
                }
            }
            if(ok) nqueen(count+1);
        }
    }
}
int main()
{
	int re[11],k;
	for(int i=1;i<11;i++)
	{
		n=i;
        tot=0;
        nqueen(0);
		re[i]=tot;
	}
    while(scanf("%d",&k)!=EOF && k)
    {
        printf("%d\n",re[k]);
    }
    return 0;
}