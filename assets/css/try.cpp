#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define test int t;cin>>t;while(t--)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define F first
#define S second
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define endl "\n"
#define all(v) v.begin(),v.end()
#define print(v) for(auto it:v) cout<<it<<" "; cout<<endl;
#define print2(pr) for(int i=pr.size()-1;i>=0;i--)cout<<pr[i];cout<<endl;
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rvs(v) reverse(v.begin(),v.end());
#define cinv(v) for(auto &it:v)cin>>it;
#define rall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pr pair<int,int>
#define Tasrik ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

void abrakadabra()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vl ar;
    ll x=gcd(n,m);
    cout<<x<<endl;

    for(ll i=2; i*i<=100; i++)
    {
        if(i%x==0){
            continue;
        }

        if(i%n==0){
          ar.pb(i);
        }
        else if(i%m==0){
          ar.pb(i);
        }
    }

    srt(ar);

    //cout<<ar[k-1]<<endl;


}

int main ()
{
    Tasrik;
    int cs=1;
   // test
    {
//        cout << "Case " <<cs << ": ";
//        cs++;
        abrakadabra();
    }

    return 0;
}


