////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-22 20:33:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:352KB
//////////////////System Comment End//////////////////
    #include<stdio.h>  
    __int64 map[110][110];  
    __int64 station[110];  
    #define  Max  0x7fffffffffffff//设一最大值  
    __int64 l1,l2,l3,l4,c1,c2,c3,c4,d;  
    int n,m;  
    __int64 deng(__int64 d)//计算费用  
    {  
        if(d==0)  
            return 0;  
        else if(d<=l1)  
            return c1;  
        else if(d<=l2)  
            return c2;  
        else if(d<=l3)  
            return c3;  
        else if(d<=l4)  
            return c4;  
        else return Max;  
    }  
    void floyd()  
    {  
        int i,j,k;  
        for(k=1;k<=n;k++)  
            for(i=1;i<=n;i++)  
                for(j=1;j<=n;j++)  
                    if(map[i][k]!=Max&&map[k][j]!=Max&&map[i][j]>map[i][k]+map[k][j])  
                        map[i][j]=map[i][k]+map[k][j];  
    }  
    int main()  
    {  
        int i,j,t,num=1;  
        scanf("%d",&t);  
        while(t--)  
        {  
            scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);  
            scanf("%d%d",&n,&m);  
            for(i=1;i<=n;i++)  
                scanf("%I64d",&station[i]);  
            for(i=1;i<=n;i++)  
                for(j=i+1;j<=n;j++)  
                {  
                    d=station[i]-station[j];  
                    if(d<0)  
                        d=-d;  
                    map[i][j]=map[j][i]=deng(d);  
                }  
            floyd();  
            printf("Case %d:\n",num++);  
            while(m--)  
            {  
                scanf("%d%d",&i,&j);  
                if(map[i][j]!=Max)  
                    printf("The minimum cost between station %d and station %d is %I64d.\n",i,j,map[i][j]);  
                else printf("Station %d and station %d are not attainable.\n",i,j);  
            }  
        }  
        return 0;  
    }  