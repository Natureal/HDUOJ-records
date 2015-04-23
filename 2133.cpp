////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-08 12:10:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int calday(int year,int month,int day)
{
	int sum,leap;
	switch(month)/*先计算某月以前月份的总天数*/
	{
	case 1:sum=0;break;
	case 2:sum=31;break;
	case 3:sum=59;break;
	case 4:sum=90;break;
	case 5:sum=120;break;
	case 6:sum=151;break;
	case 7:sum=181;break;
	case 8:sum=212;break;
	case 9:sum=243;break;
	case 10:sum=273;break;
	case 11:sum=304;break;
	case 12:sum=334;break;
	default:;
	}
	sum=sum+day; /*再加上某天的天数*/
	if(year%400==0||(year%4==0&&year%100!=0))/*判断是不是闰年*/
		leap=1;
	else
		leap=0;
	if(leap==1&&month>2)/*如果是闰年且月份大于2,总天数应该加一天*/
		sum++;

	return sum;
}
int main()
{
	int year,month,day,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},flag;
	int i,a1,a2,s,re,week[7]={7,1,2,3,4,5,6},leap,days[2]={365,366};
	while(scanf("%d %d %d",&year,&month,&day)!=EOF)
	{
		flag=1;
		leap=0;
		if(year%400==0||(year%4==0&&year%100!=0))
		{
			leap=1;
		}
		if(year%400==0||(year%4==0&&year%100!=0) && month==2)
		{
			if(day>29 || day<1)
				flag=0;
		}
		else
		{
			if(month>12 || month<1)
				flag=0;
			else if(day>a[month] || day<1)
				flag=0;
		}
		if(flag==0)
		{
			printf("illegal\n");
			continue;
		}
		a1=calday(2007,11,17);
		a2=calday(year,month,day);
		s=0;
		if(year>=2007)
		{
			for(i=2008;i<year;i++)
			{
				s+=days[i%400==0||(i%4==0&&i%100!=0)];
			}
		}
		else
		{
			for(i=year+1;i<2007;i++)
			{
				s+=days[i%400==0||(i%4==0&&i%100!=0)];
			}
		}
		if(year>2007)
		{
		   re=week[(365-a1+a2+s+6)%7];
		}
		else if(year==2007)
		{
			if(a1>a2)
				re=week[6-(a1-a2)%7];
			else
				re=week[(a2-a1+6)%7];
		}
		else
		{
			re=week[6-(days[leap]-a2+a1+s)%7];
		}
		switch(re)
		{
		case 1:printf("Monday\n");break;
		case 2:printf("Tuesday\n");break;
		case 3:printf("Wednesday\n");break;
		case 4:printf("Thursday\n");break;
		case 5:printf("Friday\n");break;
		case 6:printf("Saturday\n");break;
		case 7:printf("Sunday\n");break;
		}
	}
	return 0;
}