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

char s[200005];
char t[200005];
//set <int> mark;
bool mark[200005];
vector <int> vi;
int n,m;

bool check(int len) {
    memset(mark, 0, sizeof mark);
//    mark.clear();
    int i, j, ans = 0, x;
    for (i = 0; i < len; i++) {
        x = vi[i];
//        mark.insert(x-1);
        mark[x-1] = 1;
    }
    for (i = 0, j = 0; i < n && j < m; i++) {
        if (mark[i]) continue;
        if (s[i] == t[j]) {
            ans++;
            j++;
        }
    }
    if (ans == strlen(t)) return true;
    else return false;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int i, j, x;
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s) , m = strlen(t);
    vi.clear();
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        vi.PB(x);
    }
    int ans = 0, l, r, mid;
    l = 0;
    r = n + 1;
    //cout << l << r << endl;
//    i = 0;
    while (r - l > 1) {
//        i++;
        //cout << l << r << endl;
        mid = (l + r) / 2;
        if (check (mid)) {
            l = mid;
        }
        else r = mid;
//        if (mid == 4) cout << "HAS" << endl;
    }
    if (check (l + 1)) l = l + 1;
    printf("%d\n", l);
    return 0;
}
