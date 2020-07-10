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
    int n, i, j, x, y, k, mx, mn;
    vector <int> vi;
    while (~scanf("%d %d %d", &n, &k, &x)) {
        mx = -1e9;
        mn = 1e9;
        vi.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &y);
            vi.PB(y);
        }
        sort (vi.begin(),vi.end());
        mx = vi[vi.size()-1];
        mn = vi[0];
        k %= 2;
        if (k) {
            mx = -1e9;
            mn = 1e9;
            for (i = 0; i < n; i++) {
                if (i%2 == 0) vi[i] ^= x;
                mx = max (mx, vi[i]);
                mn = min (mn, vi[i]);
            }
        }
        printf("%d %d\n", mx, mn);
    }
    return 0;
}
