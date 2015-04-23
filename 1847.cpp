////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-22 19:57:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1847
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		if(n % 3)
			cout << "Kiki\n";
		else
			cout << "Cici\n";
	}
	return 0;
}
