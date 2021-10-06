//in this question we have to add the value (k) between the indecies (a&b)
/*
LOGIC
LET SAY A 6 SIZE ARRAY WE HAVE TO ADD +4FR0M 3-4 AND +2 FROM5 5-2
                           1  2  3  4  5  6
TAKE VALUE IN ARRAY AS     0  0  +4 0  -4
                             +2           -2
                     NOW TAKE PREFIX SUM
                     1 2 3 4 5 6
                     0 2 6 6 2 0  (MAX VALUE IS 6)   

                     GENRAL FORMULA- WE HAVE ADD X FROM INDEX P TO Q IN ARRAY A[Z]
                     THEN ADD A[P]=X+A[P]
                            A[Q+1]=-X + A[Q+1]
                            AND TAKE PREFFIX SUM               
*/

# include<bits/stdc++.h>
using namespace std;
const int N= 1e7+10;
long long ar[N]; //global array are always zero


int main()
{
 int n,m;
 cin>>n>>m;
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        // for(int i=a;i<=b;i++){
        //     ar[i]+=d; for optimising time
        // }
        ar[a] +=d;
        ar[b+1] -=d;
    }
    for(int i=1;i<=n;i++){
        ar[i]+=ar[i-1];
    }
    long long mx=-1;
    for (int i = 1; i <=n; i++)
    {
        if(mx<ar[i]){
            mx=ar[i];
        }
    }
    cout<<mx<<endl;
    


return 0;
}