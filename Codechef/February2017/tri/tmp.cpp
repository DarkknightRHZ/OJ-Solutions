
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

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

//LL vi[1000005];
vector <PLL> vl;

bool cmp (PLL x, PLL y) {
    return x.first < y.first;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n, l, r, i, j, x, y, a, b, cl, cu, ans;
//    ans = 2 * 1e18;
//    cout << ans << endl;
    scanf("%lld %lld %lld", &n, &l, &r);
    LL vi[n + 5];
//    while (~scanf("%lld %lld %lld", &n, &l, &r)) {
//        memset(vi,0,sizeof vi);
//        vl.clear();
        for (i = 0; i < n; i++) {
            scanf("%lld", &vi[i]);
//            vi.PB(x);
        }
        sort (vi, vi + n);
        for (i = 0; i < n - 1; i++) {
            //for (j = i + 1; j < n; j++) {
                j = i + 1;
                a = vi[i];
                b = vi[j];
                cl = b - a + 1;
                cu = a + b - 1;
                if (cl < l) cl = l;
                if (cu > r) cu = r;
                if (cu < cl || cl > r || cu < l) continue;
                vl.PB({cl, cu});
            //}
        }
        sort (vl.begin(), vl.end());
        ans = 0;
        cl = cu = 0;
        for (i = 0; i < vl.size(); i++) {
            x = vl[i].first;
            y = vl[i].second;
            if (x > cu) {
                cl = x;
                cu = y;
                ans += (cu - cl + 1);
            }
            else if (y > cu) {
                ans += y - cu;
                cu = y;
            }
            if (ans >= (r - l + 1)) break;
        }
        printf("%lld\n", ans);
//    }
    return 0;
}
