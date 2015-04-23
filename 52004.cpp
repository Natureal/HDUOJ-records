////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:55:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5200
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:2788KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int num,pos;
}a[50011];
int n,m,b[50011],map[50011],t[50011],ans[50011],c;

 bool cmp(node x,node y)
 {
 	return x.num<y.num;
 }

 void run()
 {
 	int i,x,p;
 	memset(t,0,sizeof(t));
 	c=0;
 	a[0].num=-1;
 	for(i=1;i<=n;i++){
 		scanf("%d",&a[i].num);
 		if(a[i].num==a[i-1].num){
 			n--;
 			i--;
 			continue;
 		}
 		b[i]=a[i].num;
 		a[i].pos=i;
 	}
 	sort(a+1,a+n+1,cmp);
 	
 	for(i=1;i<=n;i++){
 		if(a[i].num!=a[i-1].num){
 			c++;
 			map[c]=a[i].num;
 		}
 		b[a[i].pos]=c;
 	}
 	b[0]=b[n+1]=0;
 	for(i=1;i<=n;i++){
 		if(b[i-1]<b[i]&&b[i]>b[i+1]) t[b[i]]--;
 		if(b[i-1]>b[i]&&b[i]<b[i+1]) t[b[i]]++;
 	}
 	ans[0]=1;
 	for(i=1;i<=c;i++){
 		ans[i]=ans[i-1]+t[i];
 	}
 	for(i=1;i<=m;i++){
 		scanf("%d",&x);
 		p=upper_bound(map+1,map+c+1,x)-map-1;
 		printf("%d\n",ans[p]);
 	}
 }

int main()
{
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}