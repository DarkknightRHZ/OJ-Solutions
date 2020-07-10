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

LL solve(LL val, LL b, LL e, LL l, LL r) {
    if (b == e && b >= l && b <= r) {
        return val;
    }
    else if (e < l || b > r) return 0LL;
    LL left = 0, right = 0, mid, p1, p2, rem, ret = 0;
    mid = (b+e) / 2LL;
    rem = val % 2LL;
    if (mid >= l && mid <= r) ret = rem;
    left = solve(val / 2LL, b, mid - 1, l , r);
    right = solve(val / 2LL, mid + 1, e, l, r);
    return ret + left + right;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n, l, r, i, j, m, x, y, cnt, ans;
    while (~scanf("%I64d %I64d %I64d", &n, &l, &r)) {
        cnt = 0;
        m = n;
//        cout << yes << endl;
        while (m) {
            cnt++;
            m /= 2LL;
        }
        m = powl(2LL,cnt) - 1LL;
        ans = solve (n,1,m,l,r);
        printf("%I64d\n", ans);
    }
    return 0;
}
