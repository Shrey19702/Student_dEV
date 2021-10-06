#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a;
        cin>>a;
        string b;
        cin>>b;
        int cnt=0;
        int i=0;
        while(i<n)
        {
            if(((a[i]==b[i])&& (a[i+1]!=a[i])&&(b[i+1]==a[i+1]))&& i<(n-1))
            {
                    cnt=cnt+2;
                    i=i+2;//00100
            }
            else if(a[i]==b[i] && a[i]=='0')
            {
                i++;
             cnt++;
             
            }
            else if(a[i]!=b[i])
            {
                i++;
                cnt=cnt+2;
                
            }// 101 1 0 1 001
            else
            {
                i++;
                continue;
            }
        }
      cout<<cnt<<endl;
    }
    return 0;
}
