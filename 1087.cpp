////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 12:35:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
using namespace std;
int val[1002];
int f[1002];
int main()
{
    int num,i,j,ans;
    while(cin>>num && num != 0)
    {
        for(i = 0; i< num; i++)
            cin>>val[i];
        ans = val[0];
        for(i = 0; i<num; i++)
        {
            f[i] = val[i];
            for(j = 0; j<i; j++)
            {
                if(val[j] < val[i] && f[i] < f[j] + val[i])
                {
                    f[i] = f[j] + val[i];
                }
            }
            if(ans<f[i])
            {
                ans = f[i];
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}