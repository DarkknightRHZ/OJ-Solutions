
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
const LL INF = 100000000000000005;

vector <LL> vl;

LL ara[mx];
LL lsum[mx], rsum[mx];


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, n, h, x, y, i, j, beg, cns, ans, cn;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        vl.clear();
        for (i = 0; i < n; i++) {
            scanf("%lld", &x);
            vl.PB(x);
        }
        h = 0;
        for (i = 0; i < n; i++) {
            h++;
            h = min (h, vl[i]);
            ara[i] = h;
        }
        h = 0;
        for (i = n - 1LL; i >= 0; i--) {
            h++;
            h = min (h, vl[i]);
            ara[i] = min (ara[i], h);
            h = ara[i];
        }
        memset(lsum, 0, sizeof lsum);
        memset(rsum, 0, sizeof rsum);
        lsum[0] = vl[0];
        for (i = 1LL; i < n; i++) {
            lsum[i] = lsum[i - 1] + vl[i];
        }
        rsum[n - 1LL] = vl[n - 1LL];
        for (i = n - 2LL; i >= 0; i--) {
            rsum[i] = rsum[i + 1] + vl[i];
        }
        ans = INF;
//        cout << ans << endl;
//        for (i = 0; i < n; i++) {
//            cout << "a " << ara[i] << endl;
//            cout << "l " << lsum[i] << endl;
//            cout << "r " << rsum[i] << endl;
//        }
        for (i = 0; i < n; i++) {
            cns = (ara[i] * (ara[i] + 1LL)) / 2LL;
            cn = lsum[i] - cns;
            if (i < n - 1LL) {
                cns = (ara[i] * (ara[i] - 1LL)) / 2LL;
                cn += (rsum[i + 1LL] - cns);
            }
//            cout << cns << " ";
            ans = min (cn, ans);
        }
//        cout << endl;
        printf("%lld\n", ans);
    }
    return 0;
}

