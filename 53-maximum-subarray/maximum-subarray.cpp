class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi =  INT_MIN;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(nums[i] > sum){
                sum = nums[i];
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};