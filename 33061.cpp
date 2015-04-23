////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-02 00:01:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:873MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<cstring>
#define mod 10007
struct Mat
{
    long long matnn[4][4];
};
Mat matquickPow(Mat a);
Mat matMultiply(Mat a,Mat b);
long long N,X,Y;
int main()
{
    Mat c,temp,c1,mgoal;
    while(scanf("%I64d %I64d %I64d",&N,&X,&Y)!=EOF)
    {
        int i,j;
        memset(c.matnn,0,sizeof(c.matnn));
        c.matnn[0][0]=1;
        c.matnn[0][1]=1;

        c.matnn[1][1]=(X*X)%mod;
        c.matnn[1][2]=(Y*Y)%mod;
        c.matnn[1][3]=(2*X*Y)%mod;

        c.matnn[2][1]=1;

        c.matnn[3][1]=X%mod;
        c.matnn[3][3]=Y%mod;

        memset(c1.matnn,0,sizeof(c1.matnn));
        c1.matnn[0][0]=1;
        c1.matnn[1][0]=1;
        c1.matnn[2][0]=1;
        c1.matnn[3][0]=1;

        temp=matquickPow(c);
        mgoal=matMultiply(temp,c1);
        printf("%I64d\n",mgoal.matnn[0][0]%10007);
    }
    return 0;
}

Mat matquickPow(Mat a)
{
    int i,j;
    Mat tmp;
    memset(tmp.matnn,0,sizeof(tmp.matnn));
    for(i=0;i<4;i++)
        tmp.matnn[i][i]=1;
    while(N>=1)
    {
        if(N&1)tmp=matMultiply(tmp,a);
        N>>=1;
        a=matMultiply(a,a);
    }
    return tmp;
}

Mat matMultiply(Mat a,Mat b)
{
    Mat tmp;
    int i,j,k;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            tmp.matnn[i][j]=0;
            for(k=0;k<4;k++)
                tmp.matnn[i][j]=(tmp.matnn[i][j]+a.matnn[i][k]*b.matnn[k][j])%10007;
        }
    return tmp;
}
