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
    int n, i, j, x, y, k, mx, mn, div, cns, count;
    int cnt[1050];
    int ara[1050];
    while (~scanf("%d %d %d", &n, &k, &x)) {
        memset(ara, 0, sizeof ara);
        memset(cnt, 0, sizeof cnt);
        for (i = 0; i < n; i++) {
            scanf("%d", &y);
            ara[y]++;
        }
//        cout << " YES " << endl;
//        cout << n << " " << k << " " << x << endl;
        while (k--) {
            //cnt[1] = ara[0];
            for (i = 0; i < 1024; i++) {
                cnt[i] = ara[i];
//                cout << i << " " << cnt[i] << endl;
            }
//            cout << "P" << endl;
            count = 0;
            for (i = 0; i < 1024; i++) {
//                    cout << "inner loop" << endl;
//                if (ara[i]) cout << i << endl;
                if (count % 2){
                    div = ara[i] / 2;
                    cns = i^x;
//                    if (i == 7) cout << cns << " " << ara[i] << " " << div << endl;
                    //if (cns > 1049) cout << cns << endl;
                    cnt[cns] += div;
                    cnt[i] -= div;
                }
                else {
                    div = ara[i] / 2;
                    if (ara[i] % 2) div++;
                    cns = i^x;
//                    if (i == 5) cout << ara[i] << " " << div << endl;
//                    if (cns > 1049) cout << i << " " << x << " " << cns << endl;
                    cnt[cns] += div;
                    cnt[i] -= div;
                }
                count += ara[i];
            }
            for (i = 0; i < 1024; i++) {
                ara[i] = cnt[i];
            }
        }
        mx = -1e8;
        mn = 1e8;
        for (i = 0; i < 1050; i++) {
            if (ara[i]) {
                mx = max(mx, i);
                mn = min(mn,i);
            }
        }
        printf("%d %d\n", mx, mn);
    }
    return 0;
}
