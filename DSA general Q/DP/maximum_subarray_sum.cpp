#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0];
        int max_now=nums[0];

      for( int x=1;x<nums.size();x++){
          max_now=max(max_now+nums[x],nums[x]);
          max_so_far=max(max_so_far,max_now);
      }

        return max_so_far;
    }

int main(){
    int n;
    cout<<"Enter number of numbers: " ;
    cin>>n;
    cout<<endl;
  
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
  
    cout<<"The maximum subarray sum is: "<<maxSubArray(nums);
  
    return 0;
}
