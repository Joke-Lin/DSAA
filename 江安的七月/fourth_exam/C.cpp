#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define LOCAL

int number[10];
char FM[40000][6];//分母
char FZ[6];

char to_Char(int x){return '0'+x;}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int index = 0;
    memset(number,0,sizeof(number));
    for(int a = 0;a < 10;a++)//分母全排列
    {
        if(number[a]) continue;
        number[a] = 1;
        for(int b = 0;b < 10;b++)
        {
            if(number[b]) continue;
            number[b] = 1;
            for(int c = 0;c < 10;c++)
            {
                if(number[c]) continue;
                number[c] = 1;
                for(int d = 0;d < 10;d++)
                {
                    if(number[d]) continue;
                    number[d] = 1;
                    for(int e = 0; e < 10;e++)
                    {
                        if(number[e]) continue;
                        number[e] = 1;
                        FM[index][0] = to_Char(a); 
                        FM[index][1] = to_Char(b);
                        FM[index][2] = to_Char(c);
                        FM[index][3] = to_Char(d);
                        FM[index][4] = to_Char(e);
                        FM[index++][5] = '\0';
                        number[e] = 0;
                    }
                    number[d] = 0;
                }
                number[c] = 0;
            }
            number[b] = 0;
        }
        number[a] = 0;
    }
    int n;
    int kase = 0;
    while(scanf("%d",&n),n)
    {
       if(kase) printf("\n");
       kase++;
       bool big_flag = false;
       for(int i = 0;i < index;i++)//遍历分母
       {
           int a;
           sscanf(FM[i],"%d",&a);
           int b = a*n;
           int k = 0;
           while(b)
           {
               int mid = b%10;
               FZ[k++] = to_Char(mid);
               b /= 10;
           }
           FZ[k] = '\0';
           bool flag = false;
           memset(number,0,sizeof(number));
           for(int j = 0;j < 5;j++)
           {
               number[FM[i][j]-'0'] = 1;
           }
           for(int j = 0;j < k;j++) 
           {
               if(number[FZ[j]-'0'] == 1) flag = true;
               else number[FZ[j]-'0'] = 1;
           }
           if(flag == false && k!= 4)
           {
               big_flag = true;
               for(int j = k-1;j >= 0;j--) printf("%c",FZ[j]);
               printf(" / %s = %d\n",FM[i],n);
           }
       }
       if(big_flag == false) 
       {
           printf("There are no solutions for %d.\n",n);
       }
    }
    return 0;
}