
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

LL snake[mx], n, l;
vector <LL> vl;

LL solve (LL id) {
    LL i, j, ans = 0LL;
    for (i = id, j = 0; j < n; i += l, j++) {
        ans += abs (snake[j] - i);
    }
    return ans;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, a, b, i, j, x, y, beg, en, cnt, mxx, lim, gap, lo, hi, mid1, mid2;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld", &n, &l, &a, &b);
        vl.clear();
        for (i = 0; i < n; i++) {
            scanf("%lld", &x);
            vl.PB(x);
        }
        memset (snake, 0, sizeof snake);
        sort (vl.begin(), vl.end());
        for (i = 0; i < n; i++) {
            snake[i] = vl[i];
        }

        lo = a, hi = b - (n * l);
        lim = a;
        LL re1, re2;
        while (hi > lo + 2) {
//                cout << "ASI" << endl;
//            cout << hi << " " << lo << endl;
            mid1 = (2LL * lo + hi) / 3LL;
            mid2 = (2LL * hi + lo) / 3LL;
            re1 = solve (mid1);
//            cout << "P" << endl;
            re2 = solve (mid2);
            if (re1 < re2) {
                hi = mid2;
                lim = mid1;
            }
            else {
                lo = mid1;
                lim = mid2;
            }
        }
        LL ans = solve (lim);
        if (lim + 1LL + (n * l) <= b) {
            ans = min (solve(lim + 1LL), ans);
        }
        if (lim + 2LL + (n * l) <= b) {
            ans = min (solve (lim + 2LL), ans);
        }
        if (lim - 1LL + (n * l) <= b && lim - 1LL >= a) {
            ans = min (solve(lim - 1LL), ans);
        }
        if (lim - 2LL + (n * l) <= b && lim - 2LL >= a) {
            ans = min (solve (lim - 2LL), ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

