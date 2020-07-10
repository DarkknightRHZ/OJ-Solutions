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

int t;
vector <int> vi;
int ara[100005];

bool check (int mid) {
    int i, j;
    for (i = 0; i + mid <= vi.size(); i++) {
        j = ara[i + mid - 1];
        if (i) j-= ara[i-1];
        if (j <= t) {
            return true;
        }
    }
    return false;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, i, j, x;
    scanf("%d %d", &n, &t);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        vi.PB(x);
        ara[i] = x;
        if (i) ara[i] += ara[i-1];
    }
    int l = 0, r = n, mid;
    while (r - l > 1) {
        mid = (r + l) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (check(l + 1)) l++;
    printf("%d\n", l);
    return 0;
}
