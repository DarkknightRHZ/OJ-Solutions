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
#define PLL         pair < pair <LL,LL>, LL >

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL INF = 1e12;
const LL mx = 2 * (1e5) + 5;
bool taken[mx];
bool done[mx];
vector <LL> store;
vector <PLL> vi[mx];
vector <LL> vl[mx];
vector <LL> cs[mx];

bool cmp (PLL x, PLL y) {
    if (x.first.first != y.first.first) {
        return x.first.first < y.first.first;
    }
    return x.second < y.second;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
//    cout << INF << endl;
    LL n, x, i, j, k, y, z, a, b, r, l, cost, ans = INF, cns, cn, tmp, mn;
    scanf("%I64d %I64d", &n, &x);
    for (i = 0; i < n; i++) {
        scanf("%I64d %I64d %I64d", &l, &r, &cost);
        cns = r - l + 1;
        vi[cns].PB({{l, r}, cost});
        if (!taken[cns]) {
            taken[cns] = 1;
            store.PB(cns);
        }
    }
    for (i = 0; i < store.size(); i++) {
        cns = store[i];
        sort (vi[cns].begin(), vi[cns].end(), cmp);
        for (j = 0; j < vi[cns].size(); j++) {
            vl[cns].PB(vi[cns][j].first.first);
        }
        mn = INF;
        for (j = vi[cns].size() - 1; j >= 0; j--) {
            mn = min (vi[cns][j].second, mn);
            cs[cns].PB(mn);
        }
        reverse(cs[cns].begin(), cs[cns].end());
    }
    for (i = 0; i < store.size(); i++) {
        cns = store[i];
        if (cns > x) continue;
        cn = x - cns;
        if (!taken[cn]) continue;
        //if (done[cn]) continue;
        for (j = 0; j < vi[cns].size(); j++) {
            cost = vi[cns][j].second;
            a = lower_bound(vl[cn].begin(), vl[cn].end(), vi[cns][j].first.second + 1) - vl[cn].begin();
            if (a >= vl[cn].size()) continue;
            cost += cs[cn][a];
            ans = min (ans, cost);
        }
        //done[cns] = 1;
    }
    if (ans < INF) printf ("%I64d\n", ans);
    else printf ("-1\n");
    return 0;
}
