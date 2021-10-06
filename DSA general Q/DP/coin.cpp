/*
	Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to form the sum n using as few coins as possible.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    int sum;
    cin>>sum;

    int ans[sum+1];

    ans[0]=0;
    for(int i=0; i<=sum; i++){

        if(i==0){
            ans[i]=0;
            continue;
        }

        int min_ans=INT_MAX;
        for(auto coin: coins){
            if(i<coin){
                continue;
            }
            min_ans=min(min_ans, ans[i-coin]+1);
        }
        ans[i]=min_ans;
    }

    for(int i=0; i<=sum; i++){
        cout<<"ans["<<i<<"]= "<<ans[i]<<endl;
    }

    return 0;
}
