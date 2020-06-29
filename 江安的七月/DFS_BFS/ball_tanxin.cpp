//https://blog.csdn.net/jason_crawford/article/details/53217384
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    while(T--)
    {
        int ball[11];
        int l = -1e8,r = -1e8;
        bool flag = true;
        for(int i = 0;i < 10;i++) scanf("%d",ball+i);
        for(int i = 0;i < 10;i++)
        {
            // if(l == -1e8 && r == -1e8)
            // {
            //     l = ball[i];
            //     ans++;
            // }
            bool left = ball[i] >= l;
            bool right = ball[i] >= r;
            if(left && right)
            {
                if(l >= r) l = ball[i];
                else r = ball[i];
            }
            else if(left && !right) l = ball[i];
            else if(!left && right) r = ball[i];
            else flag = false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}