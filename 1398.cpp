////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-24 23:14:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
//#include <iostream>
//using namespace std;
//const int lmax=10000;    
//int c1[lmax+1],c2[lmax+1];
//int main()
//{	
//	int n,i,j,k;	
//	while (cin>>n)	
//	{
//		for (i=0;i<=n;i++)
//	    {
//			 c1[i]=1;	
//			 c2[i]=0;	
//		}
//		 for (i=2;i<=n;i++)		
//		 {	
//			 for (j=0;j<=n;j++)				
//				 for (k=0;k+j<=n;k+=i*i)				
//				 {  
//					 c2[j+k]+=c1[j];  
//				 }			
//				 for (j=0;j<=n;j++)			
//				 {  
//					 c1[j]=c2[j];	
//					 c2[j]=0;  
//				 }		
//		 }		
//		 cout<<c1[n]<<endl;	
//	}	
//	return 0;
//}
#include <stdio.h>
int c1[1000],c2[1000];

int main()
{
	int n,i,j,k;
	for(i=0;i<=305;i++)
	{
		c1[i]=1;
		c2[i]=0;
	}
	for(i=2;i<=305;i++)
	{
		for(j=0;j<=305;j++)
		{
			for(k=0;k+j<=305;k+=i*i)
			{
				c2[j+k]+=c1[j];
			}
		}
		for(j=0;j<=305;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",c1[n]);
	}
	return 0;
}