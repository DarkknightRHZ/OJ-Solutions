
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
const LL mod =  1000000007LL;

LL A[mx], C[mx];

vector <LL> va, vb, vc;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, ans, i, j, x, y, a, b, c, id, cnsA, cnsC;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        memset(A, 0, sizeof A);
        memset(C, 0, sizeof C);
        va.clear();
        vb.clear();
        vc.clear();
        for (i = 0; i < a; i++) {
            scanf("%lld", &x);
            va.PB(x);
        }
        for (i = 0; i < b; i++) {
            scanf("%lld", &x);
            vb.PB(x);
        }
        for (i = 0; i < c; i++) {
            scanf("%lld", &x);
            vc.PB(x);
        }
        sort (va.begin(), va.end());
        sort (vc.begin(), vc.end());
        for (i = 0; i < va.size(); i++) {
            if (!i) A[i] = va[i];
            else A[i] = A[i-1LL] + va[i];
            if (A[i] >= mod) A[i] -= mod;
        }
        for (i = 0; i < vc.size(); i++) {
            if (!i) C[i] = vc[i];
            else C[i] = C[i-1LL] + vc[i];
            if (C[i] >= mod) C[i] -= mod;
        }
        for (i = 0, ans = 0; i < vb.size(); i++) {
            x = vb[i];
            id = upper_bound(va.begin(), va.end(), x) - va.begin();
            id--;
            cnsA = (A[id] + (((id + 1LL) * x) % mod)) % mod;
            id = upper_bound(vc.begin(), vc.end(), x) - vc.begin();
            id--;
            cnsC = (C[id] + (((id + 1LL) * x) % mod)) % mod;
            ans += ((cnsA * cnsC) % mod);
            ans = ans % mod;
//            cout << ans << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

