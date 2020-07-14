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
const LL INF = 1e18;

LL k, asn;
LL ara[32];
map <LL, LL> mp;
LL dp[32][1005];
LL mnv[32];

LL solve(LL n, LL val, bool flag) {
//    cout << n << endl;
//    LL res = mp[val];
//    if (dp[n][res] != -1LL) return dp[n][res];
    if (n < 0LL && flag == 0) return 0LL;
    if (n < 0LL) return 1LL;
    if (mnv[n] > val) {
        if (flag) return 1LL;
        else return 0LL;
    }
    LL ret = 0LL;
    if (ara[n] == 1) {
        LL cnt = 0LL, m = n, cns;
        while (ara[m] == 1) {
            m--;
            cnt++;
        }
        ret = (powl(2,cnt));
//        cout <<"ret "<< ret << " cnt " << cnt << endl;
        if (flag == 0) {
            ret--;
            ret *= solve(m, val, 1);
            ret += solve(m, val, flag);
        }
        else {
            ret *= solve(m, val, flag);
        }
        return ret;
    }
//    if (mxv[n] > val) {
        ret = solve (n-1LL, val, flag);
//    }
    if (val >= ara[n]) {
        LL cns = val / ara[n];
//        if (!mp[cns]) mp[cns] = ++asn;
        ret += solve(n-1LL, cns, 1);
    }
    return ret;
//    return dp[n][res] = ret;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n, i, j, x, y;
//    cout << INF << endl;
    scanf("%lld %lld", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%lld", &ara[i]);
    }
    mnv[0] = ara[0];
    for (i = 1; i < n; i++) {
        mnv[i] = min(mnv[i-1], ara[i]);
    }
    memset(dp, -1, sizeof dp);
    asn = 0;
//    if (!mp[k]) mp[k] = ++asn;
    LL ans = solve(n-1LL, k, 0);
//    LL cns = 1;
//    for (i = 0; i < 30; i++) {
//        cns *= 2LL;
//    }
////    cout << cns << endl;
    printf("%lld\n", ans);
    return 0;
}
