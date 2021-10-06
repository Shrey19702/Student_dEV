// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<int> ar;
//     int sum=0;
//     int n, count1=0,count2=0,diff=0;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         ar.push_back(x);
//     }
//     sort(ar.begin(),ar.end());
//         for (int i = 0; i < n-1; i++)
//         {
//            if(ar[i]!=ar[i+1]) {
//                count1++;
//            }
//         //    else if(ar[i]==ar[i+2]){
//         //        count2=count2+1;
//         //    }
//         //    if(count1>count2){
//         //        diff++;
//         //    }
//         }
        
        
//             // diff=(n-count1);
        
        


//         cout<<diff/2<<"\n";
        

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<int> ar,b;
//     int sum=0;
//     int n, count1=0,count2=0,diff=0;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         ar.push_back(x);
//     }
//     sort(ar.begin(),ar.end());
//         for (int i = 0; i < n-1; i++)
//         {
//            if(ar[i]!=ar[i+1]&&ar[i+1]=ar[i+2]) {
//                count1++;
//            }


//            else if(ar[i]==ar[i+1]&&ar[i+1]!=ar[2+2]){
//                count2=count2+1;
//            }
        //    else if(ar[i]==ar[i+2]){
        //        count2=count2+1;
        //    }
        //    if(count1>count2){
        //        diff++;
        //    }
        // }
        #include <bits/stdc++.h>
using namespace std;
int sockMerchant(int n, vector<int> ar)
{
    unordered_map<int, int> m;
    for (int i = 0; i < ar.size(); i++)
    {
        m[ar[i]]++;
    }
    int ans=0;
    for(auto i : m)
    {
      ans+=(i.second)/2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
        
        
            
        
        


        cout<<diff/2<<"\n";
        

    return 0;
}
