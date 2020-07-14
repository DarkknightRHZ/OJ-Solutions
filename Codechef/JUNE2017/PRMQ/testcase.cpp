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

const int mx = 1e5 + 5;
const int INF = 1e7;

bool pr[mx];
vector <int> prime, vi;
vector <PII> arr;
PII pos[mx];
int mp[1000005];
vector <PII> store[mx];

struct nod{
    int mn, mx, cnt;
    nod () {
        mn = INF;
        mx = 0;
        cnt = 0;
    }
};

nod tree[2097152];

void initP() {
    int i, j;
    for (i = 4; i < 1000; i += 2) pr[i] = 1;
    for (i = 3; i * i < 1000; i += 2) {
        if (!pr[i]) {
            for (j = i * i; j < 1000; j += i) {
                pr[j] = 1;
            }
        }
    }
    for (i = 2; i < 1000; i++) {
        if (!pr[i]) {
                prime.PB(i);
//                prPos[i] = prime.size() - 1;
        }
    }
}

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].mn = arr[b].first;
        tree[node].mx = arr[b].first;
        tree[node].cnt = arr[b].first == 0? 0: arr[b].second;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].mn = min(tree[Left].mn, tree[Right].mn);
    tree[node].mx = max(tree[Left].mx, tree[Right].mx);
    tree[node].cnt = tree[Left].cnt + tree[Right].cnt;
}
int query(int node, int b, int e, int i, int j, int x, int y)
{
    if (i > e || j < b || tree[node].cnt <= 0)
        return 0;
    if (b >= i && e <= j && tree[node].mn >= x && tree[node].mx <= y)
        return tree[node].cnt;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j, x, y);
    int p2 = query(Right, mid + 1, e, i, j, x, y);
    return p1 + p2;
}

const int mxx = 1000000 - 1;
const int mxxx = 100000 - 1;

int main()
{
    #ifdef O_Amay_Valo_Basheni
//        freopen("get.txt","r",stdin);
        freopen("get2.txt","w+",stdout);
    #endif // O_Amay_Valo_Basheni
    printf ("%d\n", mxxx+1);
    int i, j, x, y, l, r, cns;
    for (i = 1; i <= mxxx+1; i++) {
        cns = (rand() % mxx) + 2;
        cout << cns << " ";
    }
    cout << endl;
    printf ("%d\n", mxxx+1);
    for (i = 1; i <= mxxx+1; i++) {
        x = (rand() % mxxx) + 1;
        while (1) {
            y = (rand() % mxxx) + 1;
            if (y >= x) break;
        }
        l = (rand() % mxx) + 1;
        while (1) {
            r = (rand() % mxx) + 1;
            if (r >= l) break;
        }
        printf ("%d %d %d %d\n", x, y, l, r);
    }
    return 0;
}
