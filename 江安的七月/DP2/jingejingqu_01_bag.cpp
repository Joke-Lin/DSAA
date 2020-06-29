#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 55;
int n,t;
int a[maxn];
int dp[maxn*180];

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        scanf("%d%d",&n,&t);
        for(int i = 1;i <= n;i++) scanf("%d",a+i);
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = t-1;j >=0;j--)
            {
                if(j>=a[i] && dp[j-a[i]]>=0)
                {
                    dp[j] = max(dp[j],dp[j-a[i]]+1);
                }
                ans = max(ans,dp[j]);
            }
        }
        for(int i = t-1;i >= 0;i--)
        {
            if(dp[i] == ans)
            {
                printf("Case %d: %d %d\n",kase,ans+1,i+678);
                break;
            }
        }
    }
    return 0;
}
// #include<cstdio>
// #include<cstring>
// #include<iostream>
// using namespace std;
// const int maxn=55;
// int n,t;
// int a[maxn];
// int dp[maxn*180];
// int main()
// {
//     int T;
//     scanf("%d",&T);
//     for(int kase=1;kase<=T;++kase)
//     {
//         scanf("%d%d",&n,&t);
//         for(int i=1;i<=n;i++)
//             scanf("%d",&a[i]);
//         int ans=0;
//         memset(dp,-1,sizeof(dp));
//         dp[0]=0;
//         for(int i=1;i<=n;i++)
//             for(int j=t-1;j>=0;j--)
//             {
//                 if(j>=a[i]&&dp[j-a[i]]>=0)
//                     dp[j]=max(dp[j],dp[j-a[i]]+1);
//                 ans=max(ans,dp[j]);
//             }
//         for(int i=t-1;i>=0;i--)
//             if(dp[i]==ans)
//             {
//                 printf("Case %d: %d %d\n",kase,ans+1,i+678);
//                 break;
//             }
//     }
// }