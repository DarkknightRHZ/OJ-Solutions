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
const LL INF = 2e9 + 5;

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

bool check (LL mid, LL n, LL m) {
    LL l, crp;
    l = ((mid * (mid - 1)) / 2) + mid + m;
    if (l >= n) return true;
    else return false;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n,m,i,j;
    scanf("%I64d %I64d", &n, &m);
    if ( m >= n) {
        printf("%I64d\n", n);
        return 0;
    }
    LL crp = n;
    LL l, r, mid;
    l = 0;
    r = INF;
    while (r - l > 1) {
        mid = (r + l) / 2;
        if (check(mid, n, m)) {
            r = mid;
        }
        else l = mid + 1;
    }
    if (check(r - 1, n, m)) r = r - 1;
    LL ans = r + m;
    printf("%I64d\n", ans);
    return 0;
}
