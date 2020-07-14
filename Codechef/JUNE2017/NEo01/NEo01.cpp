
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

vector <LL> vl,vln;
LL cum[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, happy, i, j, x, y, n, cns, ans;
    scanf("%lld", &t);
    while(t--) {
        happy = 0LL;
        vl.clear();
        vln.clear();
        scanf("%lld", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &x);
            if (x >= 0LL) vl.PB(x);
            else vln.PB(x);
        }
        sort (vln.rbegin(), vln.rend());
        cns = 0;
        for (i = 0; i < vl.size(); i++) {
            cns += vl[i];
        }
        happy = cns;
        memset(cum, 0, sizeof cum);
//        cout << "ITS OKAY" << endl;
        for (j = vln.size()- 1LL; j >= 0; j--) {
            cum[j] = cum[j + 1LL] + vln[j];
        }
        ans = (happy * vl.size()) + cum[0];
        for (i = 1LL; i <= vln.size(); i++) {
            happy += vln[i - 1];
            ans = max (ans, (happy * (vl.size() + i)) + cum[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

