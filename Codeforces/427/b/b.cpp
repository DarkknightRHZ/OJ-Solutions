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

const int mx = 1e5 + 5;

char s[mx];

vector <int> vc;

int cum[mx];

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int k, len, i, j, x, y, cn;
    while (~scanf("%d", &k)) {
        scanf("%s", s);
        len = strlen(s);
        vc.clear();
        int sum = 0;
        for (i = 0; i < len; i++) {
            x = s[i] - '0';
            sum += x;
            vc.PB(x);
        }
        if (sum >= k) {
            printf ("0\n");
            continue;
        }
        int cns = 0;
        sort (vc.begin(), vc.end());
        memset(cum , 0, sizeof cum);
        for (i = vc.size()-1;i >= 0; i-- ) {
            cum[i] = vc[i] + cum[i+1];
        }
        cn = 0;
        for (i = 0; i < vc.size(); i++) {
            if (vc[i] < 9) {
                cn++;
            }
            cns += 9;
            if (cns + cum[i+1] >= k) break;
        }
        printf ("%d\n", cn);
    }
    return 0;
}
