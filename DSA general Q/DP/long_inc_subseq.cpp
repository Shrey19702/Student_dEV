/*
	find the longest increasing subsequence in an array of n elements
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10];
    for(int i=0; i<10; i++){
        cin>>a[i];
    }

    int b[10];
    sort(a, a+10);
    for(int i=0; i<10; i++){
        b[i]=a[i];
    }

    int length[10];

    for(int i=0; i<10; i++){
        length[i]=1;
        
    }

    int length[10];
    for(int i=0; i<10; i++){
        length[i]=1;
        for(int j=0; j<i; j++){
            if(a[i]>a[j]){
                length[i]=max(length[i], length[j]+1);
            }
        }
    }

    for(auto i: length){
        cout<<i<<endl;
    }
    return 0;
}