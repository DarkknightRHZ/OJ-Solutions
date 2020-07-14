
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

vector <LL> vi;
LL ara[mx];

bool check(LL val, LL lim, LL k) {
    int x, y, hand, req, has, st, tmp, cnt = 0;
    while (vi[lim] >= k) {
            lim--;
            cnt++;
            if (cnt >= val) return true;
    }
    val -= cnt;
    req = val * k;
    if (lim - val < 0) {
        has = ara[lim];
        if (req > has) return false;
        else return true;
    }
    has = ara[lim] - ara[lim - val];
    hand = lim - val + 1LL;
    if (has + hand >= req) return true;
    else return false;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t;
    LL n, q, l, k, i, j, x, y, lo, hi, liml, limr, cnt, hand, mid;
    scanf("%d", &t);
    while(t--) {
        vi.clear();
        scanf("%lld %lld", &n, &q);
        for (i = 0; i < n; i++) {
            scanf("%lld", &x);
            vi.PB(x);
        }
        sort (vi.begin(), vi.end());
//        for (i = 0; i < vi.size(); i++) {
//            cout << vi[i] << " ";
//        }
//        cout << endl;
        memset(ara, 0, sizeof ara);
        ara[0] = vi[0];
        for (i = 1LL; i < vi.size(); i++) {
            ara[i] = ara[i-1LL] + vi[i];
        }
//        cout << n << " " << q << endl;
        for (i = 0; i < q; i++) {
            scanf("%lld", &k);
//            cout << "K " << k << endl;
            limr = lower_bound(vi.begin(), vi.end(), k) - vi.begin();
//            cout << "limr " << limr << endl;
            hand = vi.size() - limr;
            if (hand >= vi.size()) {
                printf("%lld\n", hand);
                continue;
            }
//            cout << hand << " It's hand you nutt!" << endl;
            lo = 0, hi = limr;
            //if (limr >= vi.size()) limr--;
            cnt = 0;
            while (hi - lo > 1LL) {
//                cout << hi << " " << lo << endl;
                mid = (lo + hi) >> 1LL;
                if (check(mid, limr - 1LL, k)) {
                    lo = mid;
                    cnt = mid;
                }
                else {
                    hi = mid - 1LL;
                }
            }
            if (check(cnt + 1LL, limr - 1LL, k)) cnt++;
            cnt = cnt + hand;
            printf("%lld\n", cnt);
        }
    }
    return 0;
}

