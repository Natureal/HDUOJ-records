////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-19 20:53:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int count,m,c,a[105];
	while(cin >> m && m)
	{
		c = count = 0;
		for(int i = 1;i <= m;i ++)
		{
			cin >> a[i];
			c ^= a[i];
		}
		if(c == 0)
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i <= m;i ++)
		{
			if((c ^ a[i]) < a[i])
				count ++;
		}
		cout << count << endl;
	}
	return 0;
}