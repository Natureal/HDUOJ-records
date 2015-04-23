////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 16:33:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5057
////Problem Title: 
////Run result: Accept
////Run time:2015MS
////Run memory:30008KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define MAXN 100010
#define MOD 32768
unsigned short tree[MAXN][10][10];
char cnt[MAXN][10][10];
int a[MAXN];
int n,m;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int P,int D,int num){
	while(x<=MAXN){
		int tmp=tree[x][D][P]+num;
		tree[x][D][P]=tmp%MOD;
		cnt[x][D][P]+=tmp/MOD;		
		x+=lowbit(x);
	}
}
int getsum(int x,int D,int P){
	int sum=0;
	while(x){
		sum+=(tree[x][D][P]+(MOD)*cnt[x][D][P]);
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int tmp=a[i];
			for(int j=0;j<10;j++){
				add(i,tmp%10,j,1);
				tmp/=10;
			}
		}
		while(m--){
			char ch;
			getchar();
			scanf("%c",&ch);
			if(ch=='S'){
				int x,y;
				scanf("%d%d",&x,&y);
				int tmp=a[x];
				for(int j=0;j<10;j++){
					add(x,tmp%10,j,-1);
					tmp/=10;
				}
				a[x]=y;
				tmp=a[x];
				for(int j=0;j<10;j++){
					add(x,tmp%10,j,1);
					tmp/=10;
				}
			}
			else {
				int L,R,D,P;
				scanf("%d%d%d%d",&L,&R,&D,&P);
				int ans=getsum(R,D-1,P)-getsum(L-1,D-1,P);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}