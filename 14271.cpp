////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-03 22:34:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1427
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:344KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1427.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月03日 星期一 21时17分34秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int val[4],flag;
void dfs(int a,int count,int b)
{
	if(flag)
		return;
	if(count==3)//当运算符个数达到三，说明前三个数已经运算，下面进行第四个数的运算
	{
		if(a+b==24)//加
			flag=1;
		else if(a-b==24)//减
			flag=1;
		else if(a*b==24)//乘
			flag=1;
		else if(b!=0&&a%b==0&&a/b==24)//除法要稍加判断，这里要证明算24点过程中不可能*仅由*两个分数
			flag=1;                   //相乘得到，假设有且仅有(a/b)*(c/d)==24这种算法才能得到，那么
		return;                       //a,b,c,d互质（因为不互质都可以通过dfs过程达到较大数整除较小数达到效果）
	}                                 //那么a*c==24*b*d，则a,b,c,d不两两互质，矛盾！
	count++;
	dfs(a+b,count,val[count]);//a和b进行运算，即传入dfs函数的两个值运算
	dfs(a-b,count,val[count]);
	dfs(a*b,count,val[count]);
	if(b!=0&&a%b==0)
		dfs(a/b,count,val[count]);
	dfs(a,count,b+val[count]);//将b和下一个数进行运算
	dfs(a,count,b-val[count]);
	dfs(a,count,b*val[count]);
	if(val[count]!=0&&b%val[count]==0)
		dfs(a,count,b/val[count]);
	return;
}
int main()
{
	char temp[4][2];
	while(cin>>temp[0]>>temp[1]>>temp[2]>>temp[3])
	{
		//cout<<temp[0]<<endl<<temp[1]<<endl<<temp[2]<<endl<<temp[3]<<endl;
		for(int i=0;i<4;i++)
		{
			if(temp[i][0]=='A')val[i]=1;
			else if(temp[i][0]=='J')val[i]=11;
			else if(temp[i][0]=='Q')val[i]=12;
			else if(temp[i][0]=='K')val[i]=13;
			else if(temp[i][0]=='1'&&temp[i][1]=='0')val[i]=10;
			else val[i]=temp[i][0]-'0';
			//printf("%d\n",val[i]);
		}
		sort(val,val+4);
		flag=0;
	//	do
	//	{
	//		dfs(val[0],1,val[1]);
	//	}while(!flag&&next_permutation(val,val+4));
		while(!flag)
		{
			dfs(val[0],1,val[1]);
			if(!flag&&next_permutation(val,val+4));
			else break;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
