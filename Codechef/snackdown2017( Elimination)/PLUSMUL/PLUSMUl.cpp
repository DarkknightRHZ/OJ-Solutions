
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
#define PLLL        pair < LL, PLL >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;
const LL mod = 1e9 + 7;

LL dp[mx];
vector <LL> vi;
LL cum[mx];

LL solve (LL id) {
//    cout << "OO" << endl;
    if (id < 0) {
        return 0LL;
    }
    if (id == 0) {
        return vi[id] % mod;
    }
    if (dp[id] != -1LL) return dp[id];
    LL i, j, ret1 = vi[id], ret2 = 0, ret = 0, ret3 = 0, ret4 = 0;
    for (i = id - 1LL; i >= -1; i--) {
        ret2 += (((ret1 % mod) + (solve(i))) % mod);
        ret2 %= mod;
        ret1 *= (vi[i] % mod);
        ret1 %= mod;
    }
    return dp[id] = ret2 % mod;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, n, i, j, k, l, x;
    scanf("%lld", &t);
    while(t--) {
        vi.clear();
        scanf("%lld", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &x);
            vi.PB(x);
        }
        if (n == 1) {
            printf ("%lld\n", vi[0]);
            continue;
        }
        memset(cum, 0, sizeof cum);
        for (i = 1LL; i <= n; i++) {
            cum[i] = (cum[i-1LL] + ((vi[i]) % mod)) % mod;
        }
        memset(dp, -1LL, sizeof dp);
//        cout << "P" << endl;
//        LL ans = (solve (0LL, n-1LL) + solve (1LL, n-1LL)) % mod;
        LL ans = 0;
        for (i = n; i >= 1; i++) {
            ans = ans + (cum[i])
        }
        for (i = 0; i < n; i++) {
            cout << dp[i] << endl;
        }
        printf ("%lld\n", ans);
    }
    return 0;
}

