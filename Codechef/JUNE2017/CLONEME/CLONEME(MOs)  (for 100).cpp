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
#define PH          pair < pair < PII, PII >, int >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;
const LL INF = 10000000000000005;

int block, treeMx;
int val[mx];
vector <int> vi;
vector <PH> vph;
int ans[mx];

int tree[2][mx];

int query(int id, int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[id][idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int id, int idx, int x)
{
       while(idx<=treeMx)
       {
             tree[id][idx]+=x;
             idx += idx & (-idx);
       }
}

bool cmp (PH x, PH y) {
    int ax, bx, cx, ay, by, cy, dx, dy;
    ax = x.first.first.first;
    bx = x.first.first.second;
    cx = x.first.second.first;
    dx = x.first.second.second;
    ay = y.first.first.first;
    by = y.first.first.second;
    cy = y.first.second.first;
    dy = y.first.second.second;
    int bd1, bd2, bd;
    bd1 = (ax / block) - (ay / block);
    bd2 = (cx / block) - (cy / block);
    bd = bd1 + bd2;
    if (bd != 0) {
         return bd < 0;
    }
    if (ax / block != ay / block) {
        return ax / block < ay / block;
    }
    if (cx / block != cy / block) {
        return cx / block < cy / block;
    }
    if (bx != by) {
        return bx < by;
    }
    return dx < dy;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get3.txt","r",stdin);
        freopen ("got3.txt", "w+",stdout);
    #endif // O_Amay_Valo_Basheni
    int t, n, q, i, j, x, y, a, b, c, d, cnsOne, cnsTwo, ret1, ret2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        block = sqrt(n);
//        block = sqrt(block);
        vi.clear();
        vph.clear();
        treeMx = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            vi.PB(x);
            treeMx = max (treeMx, x);
        }
        treeMx++;
        for (i = 0; i < q; i++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--,b--,c--,d--;
            if (a > c) {
                swap (a, c);
                swap (b, d);
            }
            vph.PB({{{a, b}, {c, d}}, i});
        }
        memset(ans, 0, sizeof ans);
        memset(tree, 0, sizeof tree);
        memset(val, 0, sizeof val);
        sort (vph.begin(), vph.end(), cmp);
//        sort (vph.begin(), vph.end(), cmp2);
        int cura, curb, curc, curd, cnt = 0, id;
        bool changed;
        int prevA;
        id = vph[0].second;
        cura = a = vph[0].first.first.first;
        curb = b = vph[0].first.first.second;
        curc = c = vph[0].first.second.first;
        curd = d = vph[0].first.second.second;
        for (i = cura; i <= curb; i++) {
            x = vi[i];
            cnt -= abs(val[x]);
            val[x]++;
            cnt += abs(val[x]);
        }
        for (i = curc; i <= curd; i++) {
            x = vi[i];
            cnt -= abs(val[x]);
            val[x]--;
            cnt += abs(val[x]);
        }
        if (cnt == 0) {
            ans[id] = 1;
        }
        else if (cnt <= 2) {
//            ans[id] = 1;
            memset(tree, 0, sizeof tree);
            for (i = cura; i <= curb; i++) {
                update(0, vi[i], 1);
                if (val[vi[i]] > 0) {
                    cnsOne = vi[i];
                }
            }
            for (i = curc; i <= curd; i++) {
                update(1, vi[i], 1);
                if (val[vi[i]] < 0) {
                    cnsTwo = vi[i];
                }
            }
            if (cnsOne < cnsTwo) {
                if (query(0, cnsOne) > query(1, cnsTwo - 1)) {
                    ans[id] = 1;
                }
            }
            else {
                if (query(0, cnsOne - 1) < query(1, cnsTwo)) {
                    ans[id] = 1;
                }
            }
        }
        prevA = ans[id];
        for (i = 1; i < vph.size(); i++) {
            changed = 0;
            id = vph[i].second;
            a = vph[i].first.first.first;
            b = vph[i].first.first.second;
            c = vph[i].first.second.first;
            d = vph[i].first.second.second;
            if (a == c && b == d) {
                ans[id] = 1;
                continue;
            }
            while (cura < a) {
                changed = 1;
                x = vi[cura];
                cnt -= abs (val[x]);
                val[x]--;
                cnt += abs(val[x]);
                cura++;
            }
            while (cura > a) {
                changed = 1;
                cura--;
                x = vi[cura];
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
            }
            while (curb > b) {
                changed = 1;
                x = vi[curb];
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
                curb--;
            }
            while (curb < b) {
                changed = 1;
                curb++;
                x = vi[curb];
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
            }
            while (curc < c) {
                changed = 1;
                x = vi[curc];
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
                curc++;
            }
            while (curc > c) {
                changed = 1;
                curc--;
                x = vi[curc];
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
            }
            while (curd < d) {
                changed = 1;
                curd++;
                x = vi[curd];
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
            }
            while (curd > d) {
                changed = 1;
                x = vi[curd];
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
                curd--;
            }
            if (!changed) {
                ans[id] = prevA;
            }
            if (cnt == 0) {
                ans[id] = 1;
            }
            else if (cnt <= 2) {
//                ans[id] = 1;
                memset(tree, 0, sizeof tree);
                for (j = cura; j <= curb; j++) {
                    update(0, vi[j], 1);
                    if (val[vi[j]] > 0) {
                        cnsOne = vi[j];
                    }
                }
                for (j = curc; j <= curd; j++) {
                    update(1, vi[j], 1);
                    if (val[vi[j]] < 0) {
                        cnsTwo = vi[j];
                    }
                }
                if (cnsOne < cnsTwo) {
                    if (query(0, cnsOne) > query(1, cnsTwo - 1)) {
                        ans[id] = 1;
                    }
                }
                else {
                    if (query(0, cnsOne - 1) < query(1, cnsTwo)) {
                        ans[id] = 1;
                    }
                }
            }
            prevA = ans[id];
        }
        for (i = 0; i < q; i++) {
            if (ans[i] == 1) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
