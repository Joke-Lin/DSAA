#include<iostream>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;
const int maxn = 1e6+10;

char str[maxn];
int NEXT[maxn];
int n;//告诉n了就不要strlen TLE(￣▽￣)""

void get_next()//aabaabaab next = 6
{
    int j = 0,k = -1;
    NEXT[0] = -1;
    while(j < n)
    {
        if(k == -1 || str[k]==str[j]) NEXT[++j] = ++k;
        else k = NEXT[k];
    }
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int kase = 0;
    while(scanf("%d",&n),n)
    {
        scanf("%s",str);
        printf("Test case #%d\n",++kase);
        get_next();
        for(int i = 2;i <= n;i++)
        {
            if(i%(i-NEXT[i])==0 && i/(i-NEXT[i]) > 1)//轮回字符串，这样可以获得单个串 例子见get_next //避免单个字符
            {
                printf("%d %d\n",i,i/(i-NEXT[i]));
            }
        }
        printf("\n");
    }

    return 0;
}
