/* HDU1686 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LOCAL

using namespace std;

char des[1000000+10];//目标串
char res[1000000+10];//匹配串
int NEXT[1000000+10];

void get_next();
int KMP();
int len_des,len_res;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    while(T--)
    {
        scanf("%s",res);
        scanf("%s",des);
        len_des = strlen(des);
        len_res = strlen(res);
        printf("%d\n",KMP());
    }

    return 0;
}

void get_next()
{
    int j = 0, k = -1;
    NEXT[0] = -1;
    while(j < len_res)
    {
        if(k == -1 || res[k]==res[j]) NEXT[++j] = ++k;
        else k = NEXT[k];
    }
}

int KMP()
{
    get_next();
    int i = 0,j = 0;
    int ans = 0;
    while(i < len_des)
    {
        if(j == -1 || des[i]==res[j]){ j++,i++;}
        else j = NEXT[j];
        if(j == len_res) 
        {
            ans++;
            j = NEXT[j];
        }
    }
    return ans;
}