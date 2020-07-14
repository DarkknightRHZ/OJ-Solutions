
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

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;

vector <string> vs;
set <string> result;
string cns;
char S[mx * 2];

struct node {
    bool endmark;
    bool noStop;
    node* next[26 + 1];
    node()
    {
        endmark = false;
         noStop = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void insrt(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        curr->noStop = true;
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->noStop = true;
    curr->endmark = true;
}
bool sarch(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        if (curr->noStop == false) {
            cns = "";
            for (int j = 0; j < i; j++) {
                cns = cns + str[j];
            }
            result.insert(cns);
            return true;
        }
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    if (curr->noStop == true) {
        return false;
    }
    cns = "";
    for (int i = 0; i < len; i++) {
        cns = cns + str[i];
    }
    result.insert(cns);
    return true;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, i, j, x, y;
    char ch;
    string s;
    scanf("%d", &n);
    root = new node();
//    cout << n << endl;
    for (i = 0; i < n; i++) {
        scanf(" %c", &ch);
//        cout << i << " " << ch << endl;
        if (ch == '+') {
            scanf("%s", S);
            insrt(S, strlen(S));
        }
        else {
            cin >> s;
            vs.PB(s);
        }
    }
//    cout << "THIQ ASE" << endl;
    sort(vs.begin(), vs.end());
    for (i = 0; i < vs.size(); i++) {
        s = vs[i];
        if (sarch(s, s.size()) == false) {
                printf("-1\n");
                return 0;
        }
    }
    printf("%d\n", result.size());
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}

