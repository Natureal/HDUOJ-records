////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-25 23:44:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:856KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<math.h>
int c1[80001];
int c2[80001];
int main()
{
  int i,j,k,n;
  int s;
  int num[4];
  int valu[4];
  int flag;
  valu[1]=1,valu[2]=2,valu[3]=5;
  while(scanf("%d%d%d",&num[1],&num[2],&num[3])!=EOF)
  {
 	  if(!(num[1]||num[2]||num[3]))
      break;
	  flag=1;
	  memset(c1,0,sizeof(c1));
	  memset(c2,0,sizeof(c2));
	  for(i=0;i<=num[1];i++)
	  {
 	      c1[i]=1;         	
 	  }
 	  n=num[1]*1+num[2]*2+num[3]*5;
	  for(i=2;i<=3;i++)
	  {
  	        for(j=0;j<=n;j++)
			{
				 for(k=0;k+j<=n&&k<=num[i]*valu[i];k+=valu[i])
				 {
 				          c2[j+k]+=c1[j]; 	
 				 }
			}
			for(j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}  	
  	  }
	  for(j=0;j<=n+1;j++)
      {
            if(!c1[j])
        	 {
     	       printf("%d\n",j);
     	       break;
			 }
	
      }
 	           
  }  
 
 return 0; 
}