//:POJ1703
//https://www.cnblogs.com/HpuAcmer/p/4172775.html

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<cstring>

const int maxn = 1e5+5;
int father[maxn];//存父节点,即已知关系的集合
int rel_to_fal[maxn];//与父节点的关系0表示同类，1，表示对立

void init();//初始化
void query(int,int);//询问操作
void Uion(int,int);//合并操作
int find(int);//找根节点,路径压缩的同时更新每个与根节点的关系

using namespace std;

int main()
{
    //freopen("./in.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--){
        init();
        int n,m,a,b; scanf("%d%d",&n,&m);//n个罪犯，m条命令
        for(int i = 0;i < m;i++){
            getchar();
            char cmd; scanf("%c %d %d",&cmd,&a,&b);
           // printf("m = %d\n",i);
            if(cmd == 'A'){
                query(a,b);
            }
            else Uion(a,b);
        }
    }

    //freopen("CON","r",stdin);
    //system("pause");
    return 0;
}

void init(){
    memset(father,0,sizeof(father));
    memset(rel_to_fal,0,sizeof(rel_to_fal));

    for(int i = 1;i <= maxn;i++) father[i] = i;
    for(int i = 1;i <= maxn;i++) rel_to_fal[i] = 0;//自己和自己是同类
}

int find(int x){
   if(x == father[x]) return x;
   int rel = find(father[x]);
   rel_to_fal[x] ^= rel_to_fal[father[x]];//敌人的敌人就是朋友
   return father[x] = rel;
}

void Uion(int x,int y){//x和y是默认敌对的关系
    int fx = find(x);
    int fy = find(y);
    father[fx] = fy;//根节点指向fy
    if(rel_to_fal[y] == 1)  rel_to_fal[fx] = rel_to_fal[x]; 
    //如果y与他的根敌对 因为x与y默认敌对所以 x与y的根是同类，所以fx与y的根的关系就是x的
    else rel_to_fal[fx] = 1-rel_to_fal[x];//同上解释
}

void query(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) printf("Not sure yet.\n");
    else{ //说明根节点是一个，与根节点的关系是知道的，所以可以判断关系
        if(rel_to_fal[x] == rel_to_fal[y]) printf("In the same gang.\n");
        else printf("In different gangs.\n");
    }
}