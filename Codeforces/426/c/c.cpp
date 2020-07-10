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

const int mx = 1e5 + 5;

bool pr [mx];

bool has[mx];

vector <int > prm, pra, prb;

int cna[mx];
int cnb[mx];

bool tr;

void init() {
    int i, j;
    for (i = 4; i < mx; i+=2) pr[i]= 1;
    pr[0] = pr[1] = 0;
    for (i = 3 ;i * i < mx; i+=2) {
        if (!pr[i]) {
            for (j = i * i; j < mx; j+=i) {
                pr[j] = 1;
            }
        }
    }
    prm.PB(2);
    for (i = 3; i < mx; i+= 2) {
        if (!pr[i]) {
            prm.PB(i);
        }
    }
}

void faca(int a) {
    pra.clear();
    //memset(has, 0, sizeof has);
    memset(cna, 0, sizeof cna);
    int sq = sqrt(a), i, j,cnt,x;
    for (i = 0; prm[i] <= sq && prm[i] <= a; i++) {
        x = prm[i];
        if (a % x == 0) {
            pra.PB(x);
            cnt = 0;
            while (a % x == 0) {
                cnt++;
                a /= x;
            }
            cna[x] = cnt;
        }
    }
    if (a > 1) {
        pra.PB(a);
        if (a >= mx){
            tr = 0;
            return;
        }
        cna[a] = 1;
    }
}

void facb(int b) {
    prb.clear();
    //memset(has, 0, sizeof has);
    memset(cnb, 0, sizeof cnb);
    int sq = sqrt(b), i, j,cnt,x;
    for (i = 0; prm[i] <= sq && prm[i] <= b; i++) {
        x = prm[i];
        if (b % x == 0) {
            prb.PB(x);
            cnt = 0;
            while (b % x == 0) {
                cnt++;
                b /= x;
            }
            cnb[x] = cnt;
        }
    }
    if (b >1) {
        prb.PB(b);
        if (b >= mx){
            tr = 0;
            return;
        }
        cnb[b] = 1;
    }
}


int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    init();
    int n, a, b, x, y, cns, i, j;
    scanf("%d", &n);
    while (n--) {
        tr = 1;
        scanf("%d %d", &a, &b);
        faca(a);
        if (tr) facb(b);
//        cout <<"SZ " << pra.size() <<"  " << prb.size() << endl;
//        if (n == 2)
//        for (i = 0; i < pra.size(); i++) {
//            cout << pra[i] << " ";
//        }
//        cout << endl;
//        for (i = 0; i < prb.size(); i++) {
//            cout << prb[i] <<" ";
//        }
//        cout << endl;
        if (tr) {
            for (i = 0; i < pra.size(); i++) {
                a = pra[i];
                x = cna[a];
                y = cnb[a];
                if (x > y) {
                    swap(x, y);
                }
                if (y > 2 * x) {
                    tr = 0;
                    break;
                }
                else if (y == 2 * x) {
                    continue;
                }
                else {
                    cns = (2 * x - y) / 3;
                    a = x - (2 * cns);
                    b = (y - cns) / 2;
                    if (a != b) {
                        tr = 0;
                        break;
                    }
                }
            }
            if (tr) {
                for (i = 0; i < prb.size(); i++) {
                    x = prb[i];
                    if (cna[x] == 0) {
                        tr = 0;
                        break;
                    }
                }
            }
        }
        if (tr) printf ("Yes\n");
        else printf ("No\n");
    }
    return 0;
}
