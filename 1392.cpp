////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-27 20:34:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1392
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-8
struct point
{
	double x,y;

}p[106];
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool cmpx(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	else return a.x<b.x;
}
bool cmp(point a,point b)
{
	double k=xmult(a,b,p[0]);
	if(fabs(k)<eps)
		return a.x<b.x;
	return k>0;

}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	int n,i,k,t;
	double len;
	//freopen(\"input.in\",\"r\",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		k=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			if(k==-1||cmpx(p[i],p[k]))
				k=i;
		}
		if(n==1) {
			printf("0.00\n");
			continue;
		}
		else if(n==2)
		{
			printf("%.2lf\n",dis(p[0],p[1]));
			continue;
		}
		swap(p[0],p[k]);
		sort(p+1,p+n,cmp);
		t=2;
		for(i=2;i<n;i++)
		{
			while(t>1&&xmult(p[t-2],p[t-1],p[i])<eps)
				t--;
			p[t++]=p[i];
		}
		len=0;
		p[t]=p[0];
		for(i=0;i<t;i++)
			len+=dis(p[i],p[i+1]);
		printf("%.2lf\n",len);

	}


	return 0;
}
