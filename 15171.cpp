////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-29 02:20:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1517
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define RAN 17
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        double temp = n;
        while(temp > 18) temp /= 18;
        if(temp <= 9)
        {
            printf("Stan wins.\n");
        }
        else
        {
            printf("Ollie wins.\n");

        }
    }
    return 0;
}
