////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 16:58:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int map[155][155];
int flag[155],mark[155],k;
int Dijkstra(int V)
{
int i,j,min,dir;
for(i=0;i<k;i++)
{
flag[i]=0;
mark[i]=map[V][i];
}
flag[V]=1;
mark[V]=0;
for(i=0;i<k;i++)
{
min=100000000;
for(j=0;j<k;j++)
if(flag[j]==0&&min>mark[j])
{
min=mark[j];
dir=j;
}
if(min==100000000)break;
flag[dir]=1;
for(j=0;j<k;j++)
if(flag[j]==0&&mark[j]>mark[dir]+map[dir][j])
mark[j]=mark[dir]+map[dir][j];
}
return mark[1];
}
int main()
{
char name[155][35],str1[35],str2[35];
int i,j,a,num1,num2,N;
while(scanf("%d",&N),N!=-1)
{
for(i=0;i<155;i++)
for(j=0;j<155;j++)
map[i][j]=100000000;
scanf("%s %s",name[0],name[1]);
k=2;
for(i=0;i<N;i++)
{
scanf("%s %s %d",str1,str2,&a);
for(j=0;j<k;j++)
if(strcmp(str1,name[j])==0)
{
num1=j;
break;
}
if(j==k){
strcpy(name[k++],str1);
num1=k-1;
}
for(j=0;j<k;j++)
if(strcmp(str2,name[j])==0)
{
num2=j;
break;
}
if(j==k){
strcpy(name[k++],str2);
num2=k-1;
}
if(map[num1][num2]>a)
map[num1][num2]=a;
if(map[num2][num1]>a)
map[num2][num1]=a;
}
if(strcmp(name[0],name[1])==0)
printf("0\n");
else{
i=Dijkstra(0);
if(i>=100000000)
printf("-1\n");
else
printf("%d\n",i);
}
}
return 0;
}