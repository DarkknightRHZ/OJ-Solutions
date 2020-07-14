
/**


  ######                                                                     ######   #     #  #######
  #     #    ##    #####   #    #  #    #  #    #  #   ####   #    #  #####  #     #  #     #       #
  #     #   #  #   #    #  #   #   #   #   ##   #  #  #    #  #    #    #    #     #  #     #      #
  #     #  #    #  #    #  ####    ####    # #  #  #  #       ######    #    ######   #######     #
  #     #  ######  #####   #  #    #  #    #  # #  #  #  ###  #    #    #    #   #    #     #    #
  #     #  #    #  #   #   #   #   #   #   #   ##  #  #    #  #    #    #    #    #   #     #   #
  ######   #    #  #    #  #    #  #    #  #    #  #   ####   #    #    #    #     #  #     #  #######



**/
/*

    BismiLLAHIR RAHMANIR RAHIM
    It's not how you look or who you are underneath, it's what you do that defines you

                                ------********-------

    Status : ;
    TC: xxx/xxx;
    DOS: ;
    OJ: ;

*/

#include <bits/stdc++.h>

using namespace std;

#define PB          push_back
#define PF          push_front
#define  V          vector
#define PII         pair <int,int>
#define PLL         pair <LL,LL>

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;

int ara[mx];
char s[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, i, j, x, cnt, pos, tot;
    LL ans;
    scanf("%d", &t);
    while(t--) {
        memset(ara, 0, sizeof ara);
        scanf("%s", s);
        tot = 0;
        int len = strlen(s);
        for (i = 0; i < len; i++) {
            x = s[i] - '0';
            tot += x;
            ara[i+1] = ara[i] + x;
        }
        cnt = ans = 0;
        for (i = 0; i < len - 1; i++) {
            if (s[i] == '1' && s[i+1] == '0') {
                cnt = 0;
                for (j = i + 1; j < len && s[j] != '1'; j++) {
                    cnt++;
                }
                ans += LL((LL(cnt + 1)) * (LL (ara[j])));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
