////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-16 13:31:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2561
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    int t,n,str[15];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }
        sort(str,str+n);
        cout<<str[1]<<endl;
    }
    return 0;
}
