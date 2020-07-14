
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
LL C[55];
LL cum[55];

void nCrModp(LL n, LL r, LL p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    memset(C, 0, sizeof(C));

    C[0] = 1LL; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (LL i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (LL j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1]);
    }
}


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t;
    LL n, k, m, rem, res, cns, div, i, j;
    scanf("%lld", &t);
//    nCrModp(50, 50, 50);
//    for (i = 0; i <= 50; i++) {
//        cout << C[i] << endl;
//    }
    while(t--) {
        scanf("%lld %lld %lld", &n, &k, &m);
        rem = n%k;
        if (n <= k) {
            printf ("1 1\n");
        }
        else if (rem == 0) {
            res = n / k;
            printf("%lld 1\n", res % m);
        }
        else {
            div = n / k;
            div++;
            cns = k - rem;
//            cout << cns << " cns " << endl;
            nCrModp(div - 1,cns,m);
            cum[0] = C[0];
            cum[1] = C[1];
            for (i = 2; i <= cns; i++) {
                if (i > div) {
                    cum[i] = cum[i-1];
                    continue;
                }
                cum[i] = cum[i-1] + C[i];
            }
//            for (i = 0; i <= cns; i++) {
//                cout << " C " << C[i] << endl;
//            }
            res = 0;
            for (i = 0; i <= cns; i++) {
                res = res + cum[i];
                res %= m;
            }
            printf("%lld %lld\n", div, res % m);
        }
    }
    return 0;
}

