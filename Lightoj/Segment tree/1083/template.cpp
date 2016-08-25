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
#define MII         map <int,int>
#define MSI         map <string,int>
#define MIS         map <int,string>
#define MLI         map <long long int,int>
#define MIL         map <int,long long int>
typedef long long int           LL;
typedef int                     I;
typedef double                  D;
typedef float                   F;
typedef bool                    B;
typedef char                    C;
typedef string                  S;
typedef vector <string>         VS;
typedef vector <int>            VI;
typedef vector <char>           VC;

#define left(n) n<<1
#define right(n) (n<<1)+1

/* Functions */

I GCD (I x, I y){if (x%y==0) return y; else return (GCD(y,x%y));}

int ara[30005];
int tree[3*30005];

void mini(int node, int a, int b);
int fmini(int node,int a,int b,int i,int j);
int fans(int i,int j);
int n;

int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
    #endif // LU_SERIOUS
    int t,i,cs=0;
    scanf("%d",&t);
    while (t--)
    {
        cs++;
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        mini(1,1,n);
        //cout<<"Y"<<endl;
        printf("Case %d: %d\n",cs,fans(1,n));
    }
    return 0;
}

void mini(int node, int a, int b)
{
    //cout<<"Y"<<endl;
    if (a==b)
    {
        tree[node]=a;
        return;
    }
    int mid;
    mid = (a+b)/2;
    mini(left(node),a,mid);
    mini(right(node),mid+1,b);
    if (ara[tree[left(node)]]<ara[tree[right(node)]])
        tree[node]=tree[left(node)];
    else
        tree[node]=tree[right(node)];
    return;
}

int fans(int i,int j)
{
    //cout<<"U"<<endl;
    if (i>j) return 0;
    if (i==j) return ara[i];
    int minindex,ans;
    minindex = fmini(1,1,n,i,j);
    ans = max(fans(i,minindex-1),fans(minindex+1,j));
    return max (ans,(j-i+1)*ara[minindex]);
}

int fmini(int node,int a,int b,int i, int j)
{
    //cout<<"Y"<<endl;
    if (j<a|| i>b) return -1;
    if (i<=a && b<=j) return tree[node];
    int left=-1,right=-1,mid;
    mid = (a+b)/2;
    if (mid>=i)
        left=fmini(left(node),a,mid,i,j);
    if (mid<j)
        right=fmini(right(node),mid+1,b,i,j);
    //cout<<node<<endl;
    if (left==-1) return right;
    if (right==-1) return left;
    if (ara[left] < ara[ right])
    {
        return left;
    }
    else
    {
        return right;
    }
}
