////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-22 14:45:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
int i,n,m,count;
double s,d;
char str[25][15];
scanf("%d%lf",&n,&d);
while(scanf("%d",&m)!=EOF)
{
s=0;
count=0;
for(i=1;i<=n;i++)
{
scanf("%s",str[i]);
if(str[i][0]=='-')
count=1;
}
printf("%3d: ",m);
if(count)
{
printf("-\n");
continue;
}
for(i=1;i<=n;i++)
{
s+=(str[i][0]-'0')*3600;
s+=((str[i][2]-'0')*10+(str[i][3]-'0'))*60;
s+=(str[i][5]-'0')*10+str[i][6]-'0';
}
int t=(double)s/d;
if((double)s/d-t>=0.5) t++;
printf("%d:%02d min/km\n",t/60,t%60);
}
return 0;
}