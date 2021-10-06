#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int a[n],b[n];//O(3)
for(int i=0;i<n;i++){
  cin>>a[i];//o(n)
}
for(int i=0;i<n;i++){
 b[i] =a[i];
}
sort(a,a+n);
for(int i=0;i<n-1;i++){
if(a[i]==b[a[i]]&&b[a[i]-1]==b[a[i]])
{
  cout<<i+1;
  exit;
}

}

}