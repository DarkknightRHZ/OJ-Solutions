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

const int mx = 505;
const LL INF = 10000000000000005;

int ara[3][mx], n;


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get2.txt","w+",stdout);
    #endif // O_Amay_Valo_Basheni
//    int t, odd = 0, even = 0, i, j, x = 0, y = 0, tmp, pos, cnt = 0;
//    bool tr = 0, emp, f;
//    char ch;
//    scanf("%d", &t);
//    while(t--) {
//        odd = 0;
//        scanf("%d", &n);
//        for (i = 0; i < 2; i++) {
//            for (j = 0; j < n; j++) {
//                cin >> ch;
//                if (ch == '#') {
//                    ara[i][j] = 1;
//                }
//                else {
//                    ara[i][j] = 0;
//                }
//            }
//        }
//        tr = 1;
//        f = 0;
//        cnt = 0;
//        emp = 0;
//        pos = -1;
//        for (i = 0; i < n; i++) {
//            if (emp && (ara[0][i] == 1 || ara[1][i] ==  1)) {
//                tr = 0;
//                break;
//            }
//            if (ara[0][i] == 1 && ara[1][i] == 1) {
//                cnt++;
//                f = 1;
//            }
//            else if (ara[0][i] == 1){
//                if (cnt % 2 == 0 && pos == 1) {
//                    tr = 0;
//                    break;
//                }
//                else if (cnt % 2 == 1 && pos == 0) {
//                    tr = 0;
//                    break;
//                }
//                cnt = 0;
//                pos = 0;
//                f = 1;
//            }
//            else if (ara[1][i] == 1) {
//                if (cnt % 2 == 0 && pos == 0) {
//                    tr = 0;
//                    break;
//                }
//                else if (cnt % 2 == 1 && pos == 1) {
//                    tr = 0;
//                    break;
//                }
//                cnt = 0;
//                pos = 1;
//                f = 1;
//            }
//            else {
//                emp = 1;
//            }
//        }
//        if (!f) tr = 0;
//        if (!tr) {
//            printf("no\n");
//        }
//        else {
//            printf("yes\n");
//        }
//    }
    cout << 1 << endl << 500 << endl;
    for (int i = 0; i < 500; i++) {
        cout <<"#";
    }
    cout << endl;
    for (int i = 0; i < 500; i++) {
        cout <<".";
    }
    cout << endl;
    return 0;
}
