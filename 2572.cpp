////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-24 00:11:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2572
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int max(int x,int y)
{
	return (x>y?x:y);
}
int min(int x,int y)
{
	return (x<y?x:y);
}
int main()
{
	int i,j,p,lena,lenb,lenc,t,flagb,flagc,k,mark1,mark2,s1,s2,count;
	char a[105],b[15],c[15],kc[100],kct[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a,b,c);
		lena=strlen(a);
		lenb=strlen(b);
		lenc=strlen(c);
		flagb=flagc=0;
		mark1=mark2=-1;
		count=0;
		memset(kc,'1',sizeof(kc));
		memset(kct,'1',sizeof(kct));
		for(i=0;i<lena;i++)
		{
			k=i;
			for(j=0;j<lenb;j++)
			{
				if(a[k]=='\0') break;
				if(a[k]!=b[j]) break;
				k++;
			}
			if(j>=lenb)
			{
				flagb=1;
				mark1=i;
			}

			/*if(flagb==1 && flagc==1)
			{
				s1=min(mark1,mark2);
				s2=max((mark1+strlen(b)-1),(mark2+strlen(c)-1));
				p=0;
				if((s2-s1+1)<strlen(kc))
				{
					for(j=s1;j<=s2;j++)
					{
						kc[p++]=a[j];
					}
					kc[p]='\0';
				}
				if(count==0)
				{
					strcpy(kct,kc);
				}
				else
				{
					if(strcmp(kct,kc)>0)
					{
						strcpy(kct,kc);
					}
				}
				count=1;
			}
*/
			k=i;
			for(j=0;j<lenc;j++)
			{
				if(a[k]=='\0') break;
				if(a[k]!=c[j]) break;
				k++;
			}
			if(j>=lenc)
			{
				flagc=1;
				mark2=i;
			}
			if((mark1==i || mark2==i) && mark1!=-1 && mark2!=-1)
			{
 				s1=min(mark1,mark2);
				s2=max((mark1+strlen(b)-1),(mark2+strlen(c)-1));
				p=0;
				if((s2-s1+1)<=strlen(kc))
				{
					for(j=s1;j<=s2;j++)
					{
						kc[p++]=a[j];
					}
					kc[p]='\0';
				}
				if(count==0)
				{
					strcpy(kct,kc);
				}
				else
				{
					if(strcmp(kct,kc)>0)
					{
						strcpy(kct,kc);
					}
				}
				count=1;
			}
		}
		if(count) printf("%s\n",kct);
		else printf("No\n");
	}
	return 0;
}