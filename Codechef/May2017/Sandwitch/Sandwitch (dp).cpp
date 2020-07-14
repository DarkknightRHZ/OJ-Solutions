
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

LL dp[55][55];
LL m, k;

LL solve (LL box, LL ball) {
    if (box == 1 && ball <= k) {
        return 1LL;
    }
    else if (box == 1) {
        return 0LL;
    }
    if (dp[box][ball] != -1) return dp[box][ball];
    LL i, j, res = 0, cns;
    cns = (box - 1) * k;
    i = max (ball - cns, 1LL);
    for (i = 1; i <= min (ball - box + 1, k); i++) {
        res += solve(box - 1, ball - i);
    }
//    cout << "box " << box << " " << res <<endl;
    return dp[box][ball] = res;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t;
    LL n, rem, res, cns, div, i, j;
    scanf("%lld", &t);
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
            memset(dp, -1, sizeof dp);
//            cout << div << " " << n << endl;
            res = solve(div, n);
            printf("%lld %lld\n", div, res % m);
        }
    }
    return 0;
}

