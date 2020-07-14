
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

const int mx = 50005;
const int INF = 2147483647;

int ky[mx];
bool vis[mx];
int r, k;
vector <int> vi[mx];

//PII solve(int u) {
//    if (u == r) {
//        return {k^ky[u],k^ky[u]};
//    }
//    //printf("%lld\n", k^key[u]);
//    vis[u] = 1;
//    int v, i;
//    PII res, res2;
//    res = {INF,-1*INF};
//    for (i = 0; i < vi[u].size(); i++) {
//        v = vi[u][i];
//        if (!vis[v]) {
//            res2 = solve(v);
//            res.first = min(res2.first, res.first);
//            res.second = max(res2.second, res.second);
//        }
//    }
//    if (res.first != INF || res.second != -INF) {
//        int tmp = k^ky[u];
//        res.first = min(tmp, res.first);
//        res.second = max(tmp, res.second);
//    }
//    return res;
//}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, q, i, j, u, v, x, y, d;
    PII res;
//    cout << INF << endl;
    scanf("%d %d", &n, &q);
    scanf("%d %d", &r, &k);
//    ky[r] = k;
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &v, &u, &k);
//        vi[u].PB(v);
//        vi[v].PB(u);
//        ky[v] = k;
    }
//    scanf ("%lld", &d);
    int xorR = 0;
//    cout << "q " << q << endl;
    for (i = 0; i < q; i++) {
        scanf("%d", &d);
        d = d^xorR;
//        cout << "T " << d << " " << xorR << endl;
        if (d == 0) {
            scanf("%d %d %d", &u, &v, &k);
//            cout << "Up " << u << " " << v << " " << k << endl;
            u = u^xorR;
            v = v^xorR;
            k = k^xorR;
//            cout << "U " << u << " " << v << " " << k << endl;
//            vi[u].PB(v);
//            vi[v].PB(u);
//            ky[v] = k;
        }
        else if (d == 1) {
            scanf("%d %d", &v, &k);
//            cout << "Pp " << v << " " << k << endl;
            v = v^xorR;
            k = k^xorR;
//            cout << "P " << v << " " << k << endl;
             memset(vis, 0, sizeof vis);
            //res = solve(v);
            //cout << res.first << " " << res.second << endl;
            //xorR = res.first^res.second;
            //printf("%d %d\n", res.first, res.second);
            printf("%d %d\n", rand() % 100, rand() % 100);
        }
    }
    return 0;
}

