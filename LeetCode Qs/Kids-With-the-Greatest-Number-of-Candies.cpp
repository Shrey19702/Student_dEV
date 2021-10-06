class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<int> v=candies;
        sort(v.begin(),v.end());
        
        vector<bool> b;
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=v[v.size()-1]){
                b.push_back(true);
            }else{
                b.push_back(false);
            }
        }
        return b;
    }
};
