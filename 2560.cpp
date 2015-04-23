////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-16 13:28:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        int sum=0,str;
        cin>>n>>m;
        while(n--)
        {
            for(int i=0;i<m;i++)
            {
                cin>>str;
                if(str)
                    sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
