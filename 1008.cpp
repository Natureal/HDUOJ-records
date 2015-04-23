////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-10-30 01:19:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{    
int n,sum,i,a[1000]={0};
    while(scanf("%d",&n)!=EOF && n)    
{       
 sum=0;                    
  for(i=1; i<=n; i++) 
  scanf("%d",&a[i]);  
  for(i=1;i<=n;i++)     
   {           
 if(a[i]>a[i-1])  
 sum = sum+ (a[i] - a[i-1])*6+5;  
 else sum = sum+(a[i-1] - a[i])*4+5;   
     }       
 printf("%d\n",sum);  
  }    
return 0;
}