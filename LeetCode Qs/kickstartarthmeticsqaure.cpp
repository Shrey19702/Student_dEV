#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define W(t) int t;cin>>t;while(t--)
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define pb push_back
#define V(x) vector<x>
#define mod 1000000007
int z =1;


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
W(t)
{
    int g00,g01,g02,g10,g12,g20,g21,g22;
    cin>>g00>>g01>>g02>>g10>>g12>>g20>>g21>>g22;
    V(float) a;
    // int hash[1000000000]={0};
    int count=0,c2=0;
     if((g00+g02)/2==g01) count++;
     if((g00+g20)/2==g10) count++;
     if((g02+g22)/2==g12) count++;
     if((g20+g22)/2==g21) count++;

     a.pb((g00+g22)/2);
     a.pb((g02+g20)/2);
     a.pb((g01+g21)/2);
     a.pb((g10+g12)/2);
     sort(a.begin(),a.end());

    for(int i=0;i<a.size()-1;i++)
     {
         if(a[i]!=a[i+1]) c2++;
     }

     if(c2==a.size()-1) cout<<"Case #"<<z<<": "<<count+1<<endl;

     else cout<<"Case #"<<z<<": "<< count +(a.size()-c2)<<endl;

   

  

z++;
    
    

    

}
return 0;
}