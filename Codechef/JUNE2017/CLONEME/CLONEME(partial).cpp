
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

vector <int> vi, va, vb;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, n, q, i, j, x, y, a, b, c, d;
    int cnt;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        vi.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            vi.PB(x);
        }
        for (i = 0; i < q; i++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--,b--,c--,d--;
            va.clear();
            vb.clear();
            for (j = a; j <= b; j++) {
                va.PB(vi[j]);
            }
            for (j = c; j <= d; j++) {
                vb.PB(vi[j]);
            }
            sort (va.begin(), va.end());
            sort (vb.begin(), vb.end());
            for (j = 0, cnt = 0; j < b - a + 1; j++) {
                if (va[j] != vb[j]) cnt++;
            }
            if (cnt > 1) printf("NO\n");
            else printf ("YES\n");
        }
    }
    return 0;
}

