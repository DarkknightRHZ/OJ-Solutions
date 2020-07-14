
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
#define INT_SIZE 32

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int MX = 3 * (1e5 + 5);
const LL INF = 10000000000000005;

//Declares
int asn, R, CN;
vector <int> graph[MX];
map <int, int> mp;
int ky[MX];
vector <PII> qurList[MX];
PII resList[MX];
bool vis[MX];
int xorK[MX];
int parent[MX];

// A Trie Node
struct TrieNode
{
    int value; // used in leaf node
    TrieNode * Child[2];
    int cnt[2];
};

// Utility function to create a new Trie node
TrieNode * getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->value = 0;
    newNode->Child[0] = newNode->Child[1] = NULL;
    newNode->cnt[1] = newNode->cnt[0] = 0;
    return newNode;
}

TrieNode *root;

// utility function insert new key in trie
void insert(TrieNode *root, int key)
{
    TrieNode *temp = root;

    // start from the most significant bit , insert all
    // bit of key one-by-one into trie
    for (int i = INT_SIZE-1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = (key & (1<<i));

        // Add a new Node into trie
        if (temp->Child[current_bit] == NULL)
            temp->Child[current_bit] = getNode();

        temp = temp->Child[current_bit];
        temp->cnt[current_bit]++;
    }

    // store value at leafNode
    temp->value = key ;
}

// Returns minimum XOR value of an integer inserted
// in Trie and given key.
int  minXORUtil(TrieNode * root, int key)
{
    TrieNode * temp = root;

    for (int i=INT_SIZE-1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = ( key & ( 1<<i) );

        // Traversal Trie, look for prefix that has
        // same bit
        if (temp->Child[current_bit] != NULL && temp->cnt[current_bit] >= 0)
            temp = temp->Child[current_bit];

        // if there is no same bit.then looking for
        // opposite bit
        else if(temp->Child[1-current_bit] !=NULL)
            temp = temp->Child[1-current_bit];
    }

    // return xor value of minimum bit difference value
    // so we get minimum xor value
    return key ^ temp->value;
}

void del(TrieNode* cur)
{
    for (int i = 0; i < 1; i++)
        if (cur->Child[i])
            del(cur->Child[i]);
    delete (cur);
}

void reduce(TrieNode * root, int key) {
    TrieNode * temp = root;
    for (int i=INT_SIZE-1; i >= 0; i--)
    {
        // Find current bit in given prefix
        bool current_bit = ( key & ( 1<<i) );

        // Traversal Trie, look for prefix that has
        // same bit
        if (temp->Child[current_bit] != NULL)
            temp = temp->Child[current_bit];
        temp->cnt[current_bit]--;
//        if (temp->cnt[current_bit] <= 0) {
//            temp->Child[current_bit] = NULL ;
//            break;
//        }
    }
}

void dfs (int u, int min_xor) {
    vis[u] = 1;
    int res, i, j, k, id, v;
    insert(root, ky[u]);
//    if (u == R) {
//        insert(root, ky[u]);
//    }
//    else {
//        min_xor = min(min_xor,minXORUtil(root, ky[u]));
////    cout << " YES " << endl;
//        insert(root, ky[u]);
//    }
    for (i = 0; i < qurList[u].size(); i++) {
        k = qurList[u][i].second;
        id = qurList[u][i].first;
        if (id != CN) {
//            res = min(min_xor, minXORUtil(root, k));
            res = minXORUtil(root, k);
            resList[id].first = res;
            resList[id].second = res^xorK[id+1];
//            cout << res << " " << (res^xorK[id+1]) << " " << xorK[id+1] << endl;
        }
    }
    for (i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        if (!vis[v]) {
            dfs(v, min_xor);
        }
    }
    reduce(root, ky[u]);
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, N, Q, k, r, i, j, u, v, x, y, z, d, xorR = 0, tmp, cnt = -1, lstV = -1, lstK = -1, I, X, Y;
    string s;
    scanf("%d %d", &N, &Q);
    asn = -1;
    scanf("%d %d", &r, &k);
    if (!mp[r]) mp[r] = ++asn;
    R = mp[r];
    ky[R] = k;
    parent[R] = -1;
    for (i = 0; i < N - 1; i++) {
        scanf("%d %d %d", &v, &u, &k);
        if (!mp[v]) mp[v] = ++asn;
        v = mp[v];
        u = mp[u];
        //graph[u].PB(v);
        graph[v].PB(u);
        ky[v] = k;
        parent[v] = u;
    }
    cin.ignore();
    for (I = 0; I < Q; I++) {
        getline(cin, s);
        //cout << s << endl;
        tmp = 0;
        for (j = 0; s[j] != ' '; j++) {
            tmp *= 10;
            tmp += (s[j] - '0');
        }
        d = tmp;
        tmp = 0;
        while (s[j] == ' ') {
            j++;
        }
        for (; s[j] != ' '; j++) {
            tmp *= 10;
            tmp += (s[j] - '0');
        }
        x = tmp;
        tmp = 0;
        while (s[j] == ' ') {
            j++;
        }
        for (; s[j] != ' ' && s[j] != '\0'; j++) {
            tmp *= 10;
            tmp += (s[j] - '0');
        }
        y = tmp;
        //x = mp[x];
        if (s[j] != '\0') {
            tmp = 0;
            while (s[j] == ' ') {
                j++;
            }
            for (; s[j] != '\0'; j++) {
                tmp *= 10;
                tmp += (s[j] - '0');
            }
            k = tmp;
            //cout <<"q " << d << " " << x << " " << y << " " << k << endl;
            xorR = d^0;
            x ^= xorR;
            y ^= xorR;
            k ^= xorR;
            if (!mp[y]) mp[y] = ++asn;
            x = mp[x];
            y = mp[y];
            graph[x].PB(y);
            //graph[y].PB(x);
            ky[y] = k;
            parent[y] = x;
            //cout << "q " << x << " " << y << " " << k << endl;
        }
        else {
            //cout <<"q " << d << " " << x << " " << y << endl;
            //xorR = d^1;
//            cout <<"xorR "<< xorR << endl;
            x ^= xorR;
            y ^= xorR;
            x = mp[x];
            qurList[x].PB({++cnt, y});
            xorK[cnt] = xorR;
            lstV = x;
            lstK = y;
            X = Y = ky[x]^y;
            for (j = x; j != -1; j = parent[j]) {
                X = min(X, ky[j]^y);
                Y = max(Y, ky[j]^y);
            }
            printf("%d %d\n", X, Y);
            xorR = X^Y;
            //cout << "q " << x << " " << y << endl;
        }
    }
    return 0;
    int mn = INT_MAX, mx = -1;
    if (N <= 5000 && Q <= 5000) {
        for (i = 0; i <= asn; i++) {
            for (j = 0; j < qurList[i].size(); j++) {
                x = qurList[i][j].first;
                k = qurList[i][j].second;
                mn = INT_MAX;
                mx = -1;
                for (y = i; y != -1; y = parent[y]) {
                    mn = min(mn, ky[y]^k);
                    mx = max(mx, ky[y]^k);
                }
                resList[x].first = mn;
                resList[x].second = mx;
            }
        }
        for (i = 0; i <= cnt; i++) {
            printf("%d %d\n", resList[i].first, resList[i].second);
        }
        return 0;
    }

//    cout << "OK" << endl;
    CN = cnt;
    memset(vis, 0, sizeof vis);
    root = getNode();
//    cout << " O K" << endl;
    dfs(R, INT_MAX);
//    cout << "P" << endl;
    for (i = 0; i < cnt; i++) {
        printf("%d %d\n", resList[i].first, resList[i].second);
    }
    if (lstV != -1) {
        x = lstV;
        for (i = x; i != -1; i = parent[i]) {
            mn = min(mn, ky[i]^lstK);
            mx = max(mx, ky[i]^lstK);
        }
        printf("%d %d\n", mn, mx);
    }
    //cout << "cnt " << cnt << endl;
    return 0;
}

