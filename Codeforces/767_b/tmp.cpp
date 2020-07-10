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
    vector <LL> vi;
    LL tF,tS,val,n,i,j,x,y,busyTime,pos,mn,cnt;
    while (~scanf("%I64d %I64d %I64d", &tF, &tS, &val)) {
        scanf("%I64d", &n);
        vi.clear();
        mn = 1e12 + 10;
        pos = 1e12;
        for (i = 0; i < n; i++) {
            scanf ("%I64d", &x);
            vi.PB(x);
        }
        busyTime = tF;
        for (i = 0; i < n; i++) {
            x = vi[i] - 1;
            if (!i && vi[i] > tF) {
                x = tF;
            }
            if (x >= 0 && x + val <= tS) {
                y = max(0LL, busyTime - x);
                if (y <= mn) {
                    mn = y;
                    pos = x;
                }
            }
            y = vi[i];
            cnt = 0;
            while (y == vi[i]) {
                busyTime += val;
                i++;
                cnt++;
            }
            i--;
            busyTime = max (busyTime, vi[i] + (cnt * val));
        }
        if (busyTime + val <= tS) {
            pos = busyTime;
        }
        printf("%I64d\n", pos);
    }
    return 0;
}
