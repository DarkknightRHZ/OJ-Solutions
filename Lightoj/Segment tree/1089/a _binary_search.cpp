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

#define test        cout<<"thiq ase boss"<<endl;
#define PB          push_back
#define PF          push_front
#define PII         pair <int,int>
#define MII         map <int,int>
#define MSI         map <string,int>
#define MIS         map <int,string>
#define MLI         map <long long int,int>
#define MIL         map <int,long long int>
typedef long long int           LL;
typedef vector <string>         VS;
typedef vector <int>            VI;
typedef vector <char>           VC;
typedef vector <LL>             VLL;

/* Functions */

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}


int main()
{
    #ifdef LU_SERIOUS
        freopen("get.txt","r",stdin);
        freopen("got.txt","w+",stdout);
    #endif // LU_SERIOUS
    int t,cs=0,i,j,n,q,x,y,a;
    vector <int> low,high;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&q);
        low.clear();
        high.clear();
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            low.PB(x);
            high.PB(y);
        }
        sort(low.begin(),low.end());
        sort(high.begin(),high.end());
//        for (i=0;i<high.size();i++) cout<<high[i]<<" ";
//        cout<<endl;
        printf("Case %d:\n",++cs);
        for (i=0;i<q;i++)
        {
            scanf("%d",&a);
            x = lower_bound(low.begin(),low.end(),a+1) - low.begin();
            x++;
//            cout <<low[x]<<" x "<<x<<" ";
            if (low[x-1] >= a+1 || x > low.size()) x--;
            y = lower_bound(high.begin(),high.end(),a) - high.begin();
            y++;
//            cout<<high[y]<<" y "<<y<<" ";
            if (high[y-1] >= a) y--;
            printf("%d\n",max(0,x-y));
        }
    }
    return 0;
}


