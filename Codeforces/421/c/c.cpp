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
    LL a, b, l, r, i, j, cns, rem, div, tot, cn, cnt, ans;
    while (~scanf("%I64d %I64d %I64d %I64d", &a, &b, &l, &r)) {
        tot = a+b;
        if (r <= a) {
            cout << (r - l + 1) << endl;
            continue;
        }
        else if (r <= a + tot) {
            cn = r - l + 1;
            if (cn <= b + a) {
                cout << cn << endl;
                continue;
            }
            else {
                ans = b + 1;
                if (a < b) {
                    ans += cn - (a + b) - 1;
                }
                cout << ans << endl;
                continue;
            }
        }
        else {

        }
    }
    return 0;
}
