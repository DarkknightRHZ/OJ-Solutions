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

int pos[60005];
double speed[60005];
int n;

double check (double mid) {
    double mx = 0.0, x, y;
    for (int i = 0; i < n; i++) {
        x = double (pos[i]);
        y = speed[i];
        mx = max (mx, fabs(x - mid) / y);
    }
    return mx;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int i, j, a, b, mn;
    double x, y, lo, hi, mid1, mid2;
    mn = 1e9 + 5;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%lf", &speed[i]);
    }
    lo = 0.0;
    hi = 1000000000;
    i = 0;
    while (i < 100) {
        i++;
        mid1 = (2 * lo + hi) / 3.0;
        mid2 = (2 * hi + lo) / 3.0;
        if (check (mid1) >= check(mid2)) {
            lo = mid1;
        }
        else {
            hi = mid2;
        }
    }
    printf("%0.8lf\n",check(lo));
    return 0;
}
