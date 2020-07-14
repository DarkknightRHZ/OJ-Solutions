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
#define PLL         pair <LL,LL>
#define PLLL        pair < LL, PLL >

//typedef unsigned long           LL;
typedef long long int           LL;
#define PII         pair <LL, LL>

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL mx = 1e6 + 5;
const LL INF = 1e7;

bool pr[mx];
vector <LL> prime, vi;
vector <PII> arr;
PII pos[mx];
LL mp[1000005], mxv;
vector <PII> store[mx];
LL cnt[mx];

struct nod{
    LL mn, mx, cnt;
    nod () {
        mn = INF;
        mx = 0;
        cnt = 0;
    }
};

nod tree[2097152];

void initP() {
    LL i, j;
    for (i = 4; i < mx; i += 2) pr[i] = 1;
    for (i = 3; i * i < mx; i += 2) {
        if (!pr[i]) {
            for (j = i * i; j < mx; j += i) {
                pr[j] = 1;
            }
        }
    }
    for (i = 2; i < mx; i++) {
        if (!pr[i]) {
                prime.PB(i);
//                prPos[i] = prime.size() - 1;
        }
    }
}

void init(LL node, LL b, LL e)
{
    if (b == e) {
        tree[node].mn = arr[b].first;
        tree[node].mx = arr[b].first;
        tree[node].cnt = arr[b].first == 0? 0: arr[b].second;
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].mn = min(tree[Left].mn, tree[Right].mn);
    tree[node].mx = max(tree[Left].mx, tree[Right].mx);
    tree[node].cnt = tree[Left].cnt + tree[Right].cnt;
}
LL query(LL node, LL b, LL e, LL i, LL j, LL x, LL y)
{
    if (i > e || j < b || tree[node].cnt <= 0)
        return 0;
    if (b >= i && e <= j && tree[node].mn >= x && tree[node].mx <= y)
        return tree[node].cnt;
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    LL p1 = query(Left, b, mid, i, j, x, y);
    LL p2 = query(Right, mid + 1, e, i, j, x, y);
    return p1 + p2;
}

void build(LL id, LL val) {
    LL x, y, i, j, cns;
    if (id >= prime.size()) {
        if (mp[val]) {
            x = mp[val];
            for (i = )
        }
    }
}


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL n, m, q, l, r, x, y, i, j, cnt, cns, ans, u, v, mxP = 0, asn = 1, put = 0, z, mpx, mpy;
    initP();
    bool tr = 0;
//    cout << prime.size() << endl;
    scanf("%lld", &n);
    mxv = 0;
    for (i = 0; i < n; i++) {
        scanf("%lld", &x);
        vi.PB(x);
        mxv = max (mxv, x);
        if (!mp[x]) {
            mp[x] = ++put;
        }
    }

    build (0, 1);

    arr.PB({-1,0});
    for (i = 0; i < n; i++) {
        x = vi[i];
        pos[i+1].first = asn;
        if (mp[x]) {
            y = mp[x];
            for (j = 0; j < store[y].size(); j++) {
                arr.PB(store[y][j]);
                asn++;
            }
            pos[i+1].second = asn-1;
            continue;
        }
    }
//    if (n < mx)
//    for (i = 0; i < prime.size(); i++) {
//        //if (prime[i] > mxP) break;
//        for (j = 1; j <= n; j++) {
//            cum[i][j] += cum[i][j - 1];
//        }
//    }
//    for (i = 0; i < n; i++) {
//        cout << arr[i + 1] << " ";
//    }
//    cout << endl;
//    for (i = 0; i < 3; i++) {
//        cout << "I = " << prime[i] << " ";
//        for (j = 1; j <= n; j++) {
//            cout << cum[i][j] << " ";
//        }
//        cout << endl;
//    }
    init(1, 1, asn-1);
    scanf("%lld", &q);
    for (i = 0; i < q; i++) {
        scanf("%lld %lld %lld %lld", &l, &r, &x, &y);
        ans = 0;
//        u = lower_bound(prime.begin(), prime.end(), x) - prime.begin();
//        v = lower_bound(prime.begin(), prime.end(), y) - prime.begin();
//        if (u < prime.size()) {
//            if (v >= prime.size()) v--;
//            if (prime[v] > y) v--;
////            cout << u << " " << v << endl;
//            for (j = u; j <= v; j++) {
//                ans += (cum[j][r] - cum[j][l - 1]);
//            }
//        }
//        cout << "asi" << endl;
        ans += query(1, 1, asn-1, pos[l].first, pos[r].second, x, y);
        printf("%lld\n", ans);
    }
    return 0;
}
