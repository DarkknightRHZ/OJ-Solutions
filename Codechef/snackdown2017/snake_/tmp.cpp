
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

bool issame(LL x1, LL y1, LL x2, LL y2) {
    if (x1 == x2 && y1 == y2) return true;
    else return false;
}

bool overlap(LL x1, LL y1, LL x2, LL y2, LL a1, LL b1, LL a2, LL b2) {
    if (x1 == x2 && a1 == a2 && x1 == a1) {
        if ((max (y1, y2) >= min (b1, b2) && max (y1, y2) <= max (b1, b2)) || (max (b1, b2) >= min (y1, y2) && max (b1, b2) <= max (y1, y2))) {
            return true;
        }
    }
    else if (y1 == y2 && b1 == b2 && b1 == y1) {
        if ((max (x1, x2) >= min (a1, a2) && max (x1, x2) <= max (a1, a2)) || (max (a1, a2) >= min (x1, x2) && max (a1, a2) <= max (x1, x2))) {
            return true;
        }
    }
    return false;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t;
    LL x1, y1, x2, y2, a1, b1, a2, b2;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld",&x1, &y1, &x2, &y2);
        scanf("%lld %lld %lld %lld",&a1, &b1, &a2, &b2);
        //if (x1 == x2) {
            if (issame(x1, y1, a1, b1) || issame(x1,y1,a2,b2) || issame(x2,y2,a1,b1) || issame(x2,y2,a2,b2) || overlap(x1, y1, x2, y2, a1, b1, a2, b2)) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        //}
    }
    return 0;
}

