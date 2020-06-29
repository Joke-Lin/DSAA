#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<string>
#define LOCAL

using namespace std;
const int maxn = 100000+10;

int max_len;
char stand[maxn];
char rise[maxn];
int UP[maxn];
int DOWN[maxn];

int bit_find_1(char* a,int len,char c)//找一个比他大的
{
    int l = 1,r = len;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(a[mid] == c) return mid+1;
        else if(a[mid] > c) r = mid;
        else l = mid+1;
    }
    return l;
}

int bit_find_2(char* a,int len,char c)//找一个比他小的
{
    int l = 1,r = len;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(a[mid] == c) return mid+1;
        else if(a[mid] < c) r = mid;
        else l = mid+1;
    }
    return l;
}

void Solution_1(char* stand)
{
    rise[0] = 40;
    int ans = -1;
    for(int i = 1;i <= max_len;i++) rise[i] = '9';
    for(int i = 0;i < max_len;i++)
    {
        int k = bit_find_1(rise,max_len,stand[i]);
        ans = max(ans,k);
        UP[i] = ans;
        rise[k] = stand[i];
    }
}

void Solution_2(char* stand)
{
    int ans = -1;
    rise[0] = 60;
    for(int i = 1;i <= max_len;i++) rise[i] = '0';
    for(int i = 0;i < max_len;i++)
    {
        int k = bit_find_2(rise,max_len,stand[i]);
        ans = max(ans,k);
        // printf("%d: %d\n",i,ans);
        DOWN[i] = ans;
        rise[k] = stand[i];
    }
}


int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%s",stand);
        max_len = strlen(stand);
        Solution_1(stand);
        reverse(stand,stand+max_len);
        Solution_2(stand);
        int ans = -1;
        for(int i = 0;i < max_len-2;i++)
        {
            ans = max(ans,UP[i]+DOWN[max_len-i-2]);
        }
        printf("%d\n",ans);
   }
    return 0;
}
