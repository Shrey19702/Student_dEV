#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;


//FLOYD WARSHALL ALGORITHM FOR ALL PAIRS SHORTEST PATH
int main() {
    
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;//NUMBER OF NODES
    cin>>n;//ENTER NUMBER OF EDGES
    int d[n][n];
    //ENTER THE VALUE OF THE EDGES
    //IF THERE IS NO EDGE 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
       
    //FLOYD WARSHALL ALGORITHM
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
        
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]<1e9)cout<<d[i][j]<<" ";
                else cout<<"INF ";
            }
        cout<<"\n";
    }
        
        
    
        
    
        
    
    return 0;
}
