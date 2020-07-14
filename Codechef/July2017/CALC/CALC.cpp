
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

LL n, b, hand;
LL ret (LL val) {
    if (val * b > n) return 0;
    LL i, j, cns, x, y, ans;
    cns = hand + (val * b);
    ans = ((n - (val * b)) / b) * cns;
    return ans;
}


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, i, j, x, y, lo, hi, mid1, mid2, ans1, ans2, mid, ans;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &b);
        if (n < b) {
            printf ("%lld\n", 0LL);
            continue;
        }
        hand = n % b;
        n -= hand;
        lo = 0, hi = n / b;
        mid = 0;
        while (hi - lo > 3LL) {
            mid1 = (2LL * lo + hi) / 3LL;
            mid2 = (2LL * hi + lo) / 3LL;
            ans1 = ret(mid1);
            ans2 = ret(mid2);
            if (ans1 > ans2) {
                hi = mid2;
                mid = mid1;
            }
            else {
                lo = mid1;
                mid = mid2;
            }
        }
//        cout << "mid " << mid << " " << n << endl;
        ans = ret (mid);
        ans = max (ans, ret(mid+1LL));
        ans = max (ans, ret(mid+2LL));
        ans = max (ans, ret(mid+3LL));
        ans = max (ans, ret(mid-1LL));
        ans = max (ans, ret(mid-2LL));
        ans = max (ans, ret(mid-3LL));
        printf ("%lld\n", ans);
    }
    return 0;
}

