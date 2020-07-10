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
#define PII         pair <LL,LL>

typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

LL GCD (LL x, LL y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL INF = 1000000000;

LL n;
vector <LL> rat,vi;

LL solve (LL val) {
    LL i,j,k,l,ans,ret,x,y;
    for (i = 0; i < n; i++) {
        x = rat[i];
        y = vi[i];
        if(y == 1 && val < 1900) {
            return -INF;
        }
        if (y == 2 && val > 1899) {
            return INF;
        }
        val += x;
    }
     return val;
    //else if (val > 0) return -1;
    //else return 1;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL i,j,x,y,lo,hi,mid,co,ct,check,ans;
    bool tr;
    while (~scanf("%I64d",&n)){
        vi.clear();
        rat.clear();
        co = ct = 0;
        for (i=0;i<n;i++){
            scanf("%I64d %I64d",&x,&y);
            vi.PB(y);
            rat.PB(x);
        }
//        cout << vi.size() << endl;
        lo = -INF;
        hi = INF;
        ans = -INF;
        while (hi >= lo) {
            mid = (lo + hi) / 2;
//            if (mid == 1907) cout <<":"<< endl;
//            cout << mid << endl;
            check = solve(mid);
            if (check == -INF) lo = mid + 1;
            else if (check == INF) hi = mid - 1;
            else {
                    lo = mid + 1;
                    ans = check;
            }
        }

        if (ans >= 2e8) {
            printf("Infinity\n", ans);
        }
        else if (ans <= -2e8) {
            printf("Impossible\n");
        }
        else {
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
