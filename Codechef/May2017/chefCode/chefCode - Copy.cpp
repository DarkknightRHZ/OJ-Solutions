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

LL k;
LL ara[32];
LL mnv[32];


LL solve(LL n, LL val, bool flag) {
    if (n < 0LL && flag == 0) return 0LL;
    if (n < 0LL) return 1LL;
    if (mnv[n] > val) {
        if (flag) return 1LL;
        else return 0LL;
    }
    LL ret = 0LL;
//    if (ara[n] == 1) {
//        LL cnt = 0, m = n, cns;
//        while (ara[m] == 1) {
//            m--;
//            cnt++;
//        }
//        ret = (powl(2,cnt) - 1);
////        cout <<"ret "<< ret << " cnt " << cnt << endl;
//        cns = (solve(m, val, 1));
//        ret *= cns;
//        ret += solve(m, val, flag);
//    }
//    if (mxv[n] > val) {
        ret = solve (n-1LL, val, flag);
//    }
    if (val >= ara[n]) {
        LL cns = val / ara[n];
        ret += solve(n-1LL, cns, 1);
    }
    return ret;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
        freopen("get2.txt","w+",stdout);
    #endif // O_Amay_Valo_Basheni
    cout << 30 << " " << 30 << endl;
    for (int i = 0; i < 30; i++) {
        cout << 1 << " ";
    }
 //    LL n, i, j, x, y;
////    cout << INF << endl;
//    scanf("%lld %lld", &n, &k);
//    for (i = 0; i < n; i++) {
//        scanf("%lld", &ara[i]);
//    }
//    mnv[0] = ara[i];
//    for (i = 1; i < n; i++) {
//        mnv[i] = min(mnv[i-1], ara[i]);
//    }
//    LL ans = solve(n-1LL, k, 0);
//    printf("%lld\n", ans);
    return 0;
}
