////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-07 14:56:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2897
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
	int n,p,q;
	while(cin >> n >> p >> q)
	{
		n = n - n/(p+q)*(p+q);
		if(n > p || n == 0)
			cout << "WIN" << endl;
		else
			cout << "LOST" << endl;
	}
	return 0;
}
