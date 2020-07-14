
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

const LL mx = 1e5;
const LL INF = 10000000000000005;

vector <int> vi, va, vb;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get3.txt","w+",stdout);
    #endif // O_Amay_Valo_Basheni
    cout << 3 << endl;
    int i, j, x, y, z, cns, a, b, c, d;
    for (i = 0; i < 3; i++) {
        cout << mx << " " << mx << endl;
        for (j = 0; j < mx; j++) {
            cns = (rand() % mx) + 1;
            cout << cns << " ";
        }
        for (j = 0; j < mx; j++) {
            a = (rand() % mx) + 1;
            while (1) {
                b = (rand() % mx) + 1;
                if (b >= a) break;
            }
            x = b-a;
            c = (rand() % mx) + 1;
            d = c + x;
            cout << a <<" " << b <<" " << c << " " << d << endl;
        }
    }

    return 0;
}

