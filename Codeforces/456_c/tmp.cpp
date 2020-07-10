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

typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

LL cnt[100005];
LL dp[100005];

LL solve (LL val) {
    if (val < 0) return 0LL;
    if (dp[val] != -1) return dp[val];
    LL ret, i, j;
    ret = val * cnt[val] + solve(val - 2);
    ret = max (ret, solve(val - 1));
    return dp[val] = ret;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    LL n, i, j, x, y = 0;
    memset(dp, -1, sizeof dp);
    scanf("%I64d", &n);
    for (i = 0; i < n; i++) {
        scanf("%I64d", &x);
        cnt[x]++;
        y = max(y,x);
    }
    LL ans = solve(y);
    printf("%I64d\n", ans);
    return 0;
}
