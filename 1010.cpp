////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-05 22:18:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>    
using namespace std;    
int sx,sy,ex,ey;  //起点和终点坐标  
int n,m;  //迷宫的行数列数  
char map[10][10];// 迷宫  
int flag;//判断成功  
int d[4][2]={0,1,1,0,0,-1,-1,0};  // 下、右、上、左  
void dfs(int x,int y,int t)    
{     
    /** 1、排除并剪枝 */  
    if(flag==1) return ;// 成功则返回  
    // 剩余时间不足以走到终点 或者 当前点与终点横纵坐标差的和 与 剩余时间之差奇偶性不同。则直接否决返回  
    if(t<abs(ex-x)+abs(ey-y)||(t-abs(ex-x)+abs(ey-y))%2) return ;   
    // 时间用完，则判断是否到终点并返回  
    if(t==0)   
    {  
        if(x==ex&&y==ey)  {flag=1; return ;}  
        else { return ;  }  
    }  
    /** 2、递归四个方向 */  
    for(int i=0;i<4;i++)                   
    {  
        int nx=x+d[i][0],ny=y+d[i][1];//下一位置  
        // 排除：1越界，2不是'.'或不是终点  
        if (nx>0&&nx<=n&&ny>0&&ny<=m&&(map[nx][ny]=='.'||map[nx][ny]=='D'))  
        {  
            map[nx][ny]='X';//标记当前点走过           
            dfs( nx,ny,t-1) ;// 时间-1，递归下一点  
            map[nx][ny]='.';//还原状态           
        }  
  
    }    
    return ;    
}    
int main()    
{    
    char str[10];      
    int t;    
    while (scanf("%d%d%d",&n,&m,&t)!=EOF)    
    {       
        if(n==0&&m==0&&t==0) return 0;    
        for (int i=1;i<=n;i++)    
        {    
            scanf("%s",str);    
            for (int j=1;j<=m;j++)    
            {    
                map[i][j]=str[j-1];       
                if(map[i][j]=='S')  sx=i,sy=j;    
                else if(map[i][j]=='D') ex=i,ey=j;    
            }    
        }             
        flag=0;    
        dfs(sx,sy,t);    
        if(flag==0) printf("NO\n");    
        else printf("YES\n");     
    }    
    return 0;    
}  