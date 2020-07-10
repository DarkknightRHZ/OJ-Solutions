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

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    double n, a, i, j, x, y, cns, ans, ang, tot, id, mn, cn, div;
    while (~scanf("%lf %lf", &n, &a)) {
        tot = (n-2) * 180;
        ang = tot / n;
        div = ang / (n-2);
        cns = 3;
        mn = 10000000000;
        while (cns <= n) {
            ans = (ang - ((cns - 3) * div)) - a;
            if (fabs (ans) < mn) {
                mn = fabs (ans);
                id = cns;
            }
            cns += 1.0;
        }
//        cout << mn << " " << ang << " " << a << endl;
        printf ("%d %d %.0lf\n", 1, 2, id);
    }
    return 0;
}
