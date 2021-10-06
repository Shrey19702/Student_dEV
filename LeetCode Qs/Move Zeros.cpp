class Solution {

public:

    void moveZeroes(vector<int>& nums) {

        if(nums.size()<=1)

            return;

        int z=0,n=1;

        while(z < nums.size() && n < nums.size() && z < n)

        {

            while(z < nums.size() && nums[z] != 0)

                z++;

            if(n < z)

                n= z+1;

            while(n < nums.size() && nums[n]==0)

                n++;

            if(n<=z || n>=nums.size() || z>=nums.size())

                return;

            int temp=nums[z];

            nums[z]=nums[n];

            nums[n]=temp;

        }

    }

};
