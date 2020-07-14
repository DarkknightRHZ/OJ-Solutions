
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

LL solve(LL n, LL val) {
    LL cns, mask, i, j, cnt = 0;
    bool tr = 0;
    mask = powl(2,n);
    for (i = 1; i < mask; i++) {
        cns = val;
        tr = 1;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (cns < ara[j]) {
                    tr = 0;
                    break;
                }
                else {
                    cns /= ara[j];
                }
            }
        }
        if (tr) cnt++;
    }
    return cnt;
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
    LL ans = solve(n, k);
    printf("%lld\n", ans);
    return 0;
}

