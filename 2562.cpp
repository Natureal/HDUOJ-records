////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-16 13:35:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2562
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    char str[55];
    cin>>t;
    while(t--)
    {
        cin>>str;
        int len=strlen(str);
        for(int i=0;i<len;i+=2)
        {
            cout<<str[i+1]<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
