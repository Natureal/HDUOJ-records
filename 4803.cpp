////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-20 00:40:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4803
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <math.h>
#define eps 1e-6
using namespace std;

int main()
{
    double a,b,k,x,y;
    int cnt;
    while(scanf("%lf %lf",&x,&y) != EOF){
        if(y < x){
            printf("-1\n");
            continue;
        }
        cnt = 0;
        a = 1.0;
        b = 1.0;
        k = (y + 1) / x;
        while(!(fabs(x - a) < eps && (fabs(b - y) < eps || (b > y && b < y + 1)))){
            if(a * k - b <= 1 && a != x) {//加数量
                int n;
                if(fabs(k - b / a) < eps)
                    n = (int)(x - a);
                else{
                    double num =  (1 - a * k + b) / (k - b / a);
                    n = (int)num;
                    if(!num || num != (int)num) ++n;
                }
                if((int)a + n <= (int)x){
                    b += n * (b / a);
                    a += n;
                    cnt += n;
                }
                else{
                    cnt += (int)(x - a);
                    b += (x - a) * (b / a);
                    a += (int)(x - a);
                }
            }
            else{//升单价
                double num = (a * k - b - 1);
                int n = (int)num;
                if(num != (int)num) ++n;
                b += n;
                cnt += n;
            }
            //printf("%.4lf %.4lf\n",a,b);
            //printf("%d %d\n",(int)a,(int)b);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
