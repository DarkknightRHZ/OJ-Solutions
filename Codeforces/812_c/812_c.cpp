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

const LL mx = 1e5 + 5;
const LL INF = 1e17 + 5;

LL n, s;
vector <LL> vl;
vector <LL> tmp;
//LL cum[mx];

LL check (LL bound) {
    LL i, j, k, l, x, y, cns, cn, ans = 0LL, ret, ret1;
    tmp.clear();
    for (i = 1; i <= n; i++) {
        cns = vl[i] + i * bound;
        tmp.PB(cns);
    }
    sort (tmp.begin(), tmp.end());
    for (i = 0; i < bound; i++) {
        ans += tmp[i];
    }
    if (ans > s) return INF;
    return ans;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    LL i, j, k, l, m, x, y, lo, hi, mid, ans = 0;
    scanf("%I64d %I64d", &n, &s);
    vl.PB(0);
    for (i = 0; i < n; i++) {
        scanf("%I64d", &x);
        vl.PB(x);
    }
//    for (i = 1LL; i <= n; i++) {
//        cum[i] = vl[i] + cum[i-1LL];
//    }
    lo = 0, hi = n;
    while (hi > lo + 1LL) {
//        cout << hi << " hi" << endl;
        mid = (hi + lo) / 2LL;
        y = check(mid);
        if (y != INF) {
            lo = mid;
            ans = y;
        }
        else hi = mid - 1;
    }
    y = check(lo + 1);
    if (y != INF) {
        lo++;
        ans = y;
    }
    printf ("%I64d %I64d\n", lo, ans);
    return 0;
}
