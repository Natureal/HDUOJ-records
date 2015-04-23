////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-29 02:20:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1517
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
int main()  
{  
  double n;  
  while(scanf("%lf",&n)!=EOF)  
  {  
     while(n>18) n/=18;  
     printf(n<=9?"Stan wins.\n":"Ollie wins.\n");  
  }  
  return 0;  
}  