
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

set <int> stx, sty;

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
    if (ax / block != ay / block) {
        return ax / block < ay / block;
    }
//    if (((bx / block) - (ax / block)) != ((by / block) - (ay / block))) {
//        return ((bx / block) - (ax / block)) < ((by / block) - (ay / block));
//    }
    if (((cx / block) - (ax / block)) != ((cy / block) - (ay / block))) {
        return ((cx / block) - (ax / block)) < ((cy / block) - (ay / block));
    }
    if ((dx - cx) != (dy - cy)) {
        return (dx - cx) < (dy - cy);
    }
    if (bx != by) {
        return bx < by;
    }
    return dx < dy;
}


int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get2.txt","r",stdin);
        freopen ("got2.txt", "w+",stdout);
    #endif // O_Amay_Valo_Basheni
    int t, n, q, i, j, x, y, a, b, c, d, cnsOne, cnsTwo, ret1, ret2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        block = sqrt(n);
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
//        stx.clear();
//        sty.clear();
//        stx.insert(1);
//        sty.insert(1);
        memset(ans, 0, sizeof ans);
        memset(tree, 0, sizeof tree);
        memset(val, 0, sizeof val);
        sort (vph.begin(), vph.end(), cmp);
//        for (i = 0; i < vph.size(); i++) {
//            printf("%d %d %d %d %d\n", vph[i].second, vph[i].first.first.first+1, vph[i].first.first.second+1, vph[i].first.second.first+1, vph[i].first.second.second+1);
//        }
//        cout <<"Sorting done!"<< endl;
        int cura, curb, curc, curd, cnt = 0, id;
        id = vph[0].second;
        cura = a = vph[0].first.first.first;
        curb = b = vph[0].first.first.second;
        curc = c = vph[0].first.second.first;
        curd = d = vph[0].first.second.second;
        for (i = cura; i <= curb; i++) {
            x = vi[i];
//            if (val[x] == 0) {
                    //cnt++;
//                    stx.insert(x);
//            }
            cnt -= abs(val[x]);
            val[x]++;
            cnt += abs(val[x]);
            //update(0,x,1);
//            if (val[x] == 0) {
                    //cnt--;
//                    stx.erase(x);
//                    sty.erase(x);
//            }
        }
        for (i = curc; i <= curd; i++) {
            x = vi[i];
//            if (val[x] == 0) {
                    //cnt++;
//                    sty.insert(x);
//            }
            cnt -= abs(val[x]);
            val[x]--;
            cnt += abs(val[x]);
            //update(1, x, 1);
//            if (val[x] == 0) {
                    //cnt--;
//                    stx.erase(x);
//                    sty.erase(x);
//            }
        }
//        cout << cnt << "id " << id << endl;
        if (cnt == 0) {
            ans[id] = 1;
        }
        else if (cnt <= 2) {
//            cnsOne = *(stx.begin());
//            cnsTwo = *(sty.begin());
            memset(tree, 0, sizeof tree);
            for (i = cura; i <= curb; i++) {
                update(0, vi[i], 1);
                if (val[vi[i]] > 0) {
                    cnsOne = vi[i];
                    //break;
                }
            }
            for (i = curc; i <= curd; i++) {
                update(1, vi[i], 1);
                if (val[vi[i]] < 0) {
                    cnsTwo = vi[i];
                    //break;
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
//            ans[id] = 1;
        }
//        cout << ans[0] << endl;
        for (i = 1; i < vph.size(); i++) {
            id = vph[i].second;
            a = vph[i].first.first.first;
            b = vph[i].first.first.second;
            c = vph[i].first.second.first;
            d = vph[i].first.second.second;
            while (cura < a) {
                x = vi[cura];
//                if (val[x] == 0) {
                        //cnt++;
//                        sty.insert(x);
//                }
                cnt -= abs (val[x]);
                val[x]--;
                cnt += abs(val[x]);
//                update(0, x, -1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
                cura++;
            }
            while (cura > a) {
                cura--;
                x = vi[cura];
//                if (val[x] == 0) {
                        //cnt++;
//                        stx.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
//                update(0, x, 1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
            }
            while (curb > b) {
                x = vi[curb];
//                if (val[x] == 0) {
                        //cnt++;
//                        sty.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
//                update(0, x, -1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
                curb--;
            }
            while (curb < b) {
                curb++;
                x = vi[curb];
//                if (val[x] == 0) {
                        //cnt++;
//                        stx.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
//                update(0, x, 1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
            }
            while (curc < c) {
                x = vi[curc];
//                if (val[x] == 0) {
                        //cnt++;
//                        stx.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
//                update(1, x, -1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
                curc++;
            }
            while (curc > c) {
                curc--;
                x = vi[curc];
//                if (val[x] == 0) {
                        //cnt++;
//                        sty.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
//                update(1, x, 1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
            }
            while (curd < d) {
                curd++;
                x = vi[curd];
//                if (val[x] == 0) {
                        //cnt++;
//                        sty.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]--;
                cnt += abs(val[x]);
//                update(1, x, 1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
            }
            while (curd > d) {
                x = vi[curd];
//                if (val[x] == 0) {
                        //cnt++;
//                        stx.insert(x);
//                }
                cnt -= abs(val[x]);
                val[x]++;
                cnt += abs(val[x]);
//                update(1, x, -1);
//                if (val[x] == 0) {
                        //cnt--;
//                        stx.erase(x);
//                        sty.erase(x);
//                }
                curd--;
            }
//            cout << cnt << " id " << id << endl;
            if (cnt == 0) {
                ans[id] = 1;
            }
            else if (cnt <= 2) {
//                cout <<"id " << id << endl;
//                cnsOne = *(stx.begin());
//                cnsTwo = *(sty.begin());
//                cout << "CnsOne " << " " << cnsOne << " CnsTwo " << cnsTwo << endl;
//                cout << stx.size() << " " << sty.size() << endl;
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
                //ret1 = query (0, cnsOne);
                //ret2 = query (1, cnsTwo);
//                cout <<"ret1 " << ret1 << " ret2 " << ret2 << endl;
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
//                ans[id] = 1;
//                cout << ans[id] << endl;
            }
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

