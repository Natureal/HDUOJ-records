////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 14:20:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <iostream>
#define Max_n 110
#define Max_m 220
using namespace std;
int vec[Max_n][Max_n];
int nearby[Max_n];
int wantplace[Max_n];
int dis[Max_m];
int s[Max_m];

int N,M;
//创建图模型函数
void creatgraph()
{
	int i,a,b;
	memset(vec,0,Max_n*Max_n*sizeof(int));
	for(i=0;i<M;i++)
	{
		cin>>a>>b;
		if(a!=b)
		{
			vec[a][b]=1;
		vec[b][a ]=1;
		}
	}
}

void dijkstra(int start)
{
	int i,j,u,mindis;
	memset(s,0,Max_m*sizeof(int));
	for(i=0;i<N;i++)
	{
		dis[i]=vec[start][i];
	}
	s[start]=1;
	
	for(i=1;i<N;i++)
	{
		mindis=0x7FFFFFFF;
		for(j=0;j<N;j++)
		{
			if(0==s[j]&&dis[j]!=0&&dis[j]<mindis)
			{
				u=j;
				mindis=dis[j];
			}
		}
		s[u]=1;
		for(j=0;j<N;j++)
		{
			if(0==s[j]&&vec[u][j]!=0&&dis[u]+vec[u][j]<dis[j])
			{
				dis[j]=dis[u]+vec[u][j];
			}
			else if(0==s[j]&&vec[u][j]!=0&&0==dis[j])
				dis[j]=dis[u]+vec[u][j];
		}
	}
	
}

int main()
{
	int i,j,tag;
    while(cin>>N>>M)
    {
		tag=0;
        creatgraph();
		for(i=0;i<N;i++)
		{
			dijkstra(i);
			for(j=0;j<N;j++)
			{
				if(i!=j)
				{
					if(dis[j]==0||dis[j]>7)
					{
						tag=1;break;
					}
				}
			}
			if(1==tag)break;
			
		}
		if(1==tag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		
    }
    return 0;
}