class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cur = 0;
        while(cur < nums.size() && nums[cur] < k){
            cur++;
        }
        return cur;
    }
};
