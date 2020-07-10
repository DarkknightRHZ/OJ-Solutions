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
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int a[6], b[6], i, j, n, x;
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            a[x]++;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            b[x]++;
        }
        int ans = 0;
        bool tr = 0;
        for (i = 1; i <= 5; i++) {
            if ((a[i] + b[i]) % 2 != 0) {
                tr = 1;
                break;
            }
            ans += abs(((a[i] + b[i]) / 2) - a[i]);
        }
        if (tr || ans % 2) printf("%d\n", -1);
        else printf("%d\n", ans / 2);
    }
    return 0;
}
