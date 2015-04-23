////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-07-20 14:56:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1603
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: Uva387.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 20 Jul 2014 12:26:06 AM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;

int n,num;
int used[20],G[5][5];

struct pie{
	int r,c;
	int vol;
	int g[5][5];
};
pie p[20];

bool Check(int row,int col,int k){ // only used to check and update the graph
	int tG[5][5];
	memcpy(tG,G,sizeof(G));
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(p[k].g[i][j] == 1){
				if(row + i < 4 && col + j < 4 && tG[row + i][col + j] == -1)
					tG[row + i][col + j] = k;
				else
					return false;
			}
	memcpy(G,tG,sizeof(tG));
	return true;
}

void Back_Graph(int row,int col,int k){
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(p[k].g[i][j] == 1 && row + i < 4 && col + j < 4)
				G[row + i][col + j] = -1;
}

bool Dfs(int row,int col,int cnt){
	if(cnt == 16)
		return true;
	if(row >= 4 && col >= 4)
		return false;
	int next_row = row,next_col = col;
	if(col == 3){
		next_col = 0;
		++next_row;
	}
	else ++next_col;
	int flag = 1;
	for(int i = 0; i < n; ++i){
		if(used[i]) continue;
		if(Check(row,col,i)){
            used[i] = 1;
            if(Dfs(row,col,cnt + p[i].vol))
                return true;
			//if(Dfs(next_row,next_col,cnt + p[i].vol))
			//	return true;
			used[i] = 0;
			Back_Graph(row,col,i);
		}
	}
    if(G[row][col] != -1 && Dfs(next_row,next_col,cnt))
        return true;
	return  false;
}

void Init(){
	num = 0;
	memset(p,0,sizeof(p));
	memset(G,-1,sizeof(G));
	memset(used,0,sizeof(used));
}

int main(){
 	int tr,tc,head = 1;
	char s[5];
  	while(scanf("%d",&n) == 1 && n){
		Init();
		for(int i = 0; i < n; ++i){
			scanf("%d%d",&tr,&tc);
			p[i].r = tr;
			p[i].c = tc;
			for(int j = tr - 1; j >= 0; --j){
				scanf("%s",s);
				for(int k = 0; k < tc; ++k){
					p[i].g[j][k] = s[k] - '0';
					if(s[k] - '0') ++p[i].vol;
				}
			}
			num += p[i].vol;
		}
		//if(!head) printf("\n");
		//head = 0;
		if(num == 16 && Dfs(0,0,0)){
			for(int i = 3; i >= 0; --i){
				for(int j = 0; j < 4; ++j)
					printf("%d",G[i][j] + 1);
				puts("");
			}
		}
		else
			printf("No solution possible\n");
        printf("\n");
	}
	return 0;
}
