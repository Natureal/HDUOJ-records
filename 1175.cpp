////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 20:24:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1175
////Problem Title: 
////Run result: Accept
////Run time:8359MS
////Run memory:5192KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
const int MAX =1002;
bool flag = false;
bool vist[MAX][MAX];
int s,e,map[MAX][MAX];
int dir[5][3]={{1,0},{0,1},{-1,0},{0,-1}};
void DFS(int x,int y,int cnt,int d)
{
    if(cnt>2||vist[x][y]||flag)return;
    vist[x][y] = true;
    for(int i = 0;i < 4;i++)
    {
        int a,b,t;
        a = x + dir[i][0];
        b = y + dir[i][1];
        if(d!=i) t = cnt +1;
        else t = cnt;
        if(a==s&&b==e&&t<=2)
        {flag = true;return ;}      //printf("x-%d y-%d a-%d b-%d\n",x,y,a,b);
        if(!map[a][b]&&!vist[a][b])
          DFS(a,b,t,i);
    }
    vist[x][y] = false;
}
int main()
{
    //freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
    int n,m,u,v,q;
    while(scanf("%d%d",&n,&m),(n||m))
    {
        memset(map,-1,sizeof(map));
        for(int i = 1;i <= n;i++)
          for(int j = 1;j <= m;j++)
            scanf("%d",&map[i][j]);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d%d",&u,&v,&s,&e);
            flag = false;
            memset(vist,false,sizeof(vist));
            if(map[u][v]!=map[s][e]||map[u][v]==0);
            else
              DFS(u,v,-1,-1);
            if(flag)
              puts("YES");
            else
              puts("NO");
        }
    }
    return 0;
}