## MY SOLUTION
class Solution:
    def jump(self, nums: List[int]) -> int:
        minJumps = [1e9] * len(nums)
        minJumps[0] = 0 
        mxIndex = -1
        for i in range(len(nums)):
            if i + nums[i] <= mxIndex:
                continue
            else:
                for j in range(max(1,mxIndex+1), min(len(nums), i+nums[i]+1)):
                    minJumps[j] = minJumps[i] + 1
                mxIndex = min(len(nums)-1, i+nums[i])
        return minJumps[len(nums) - 1]

## EDITORIAL SOLUTION (IS MORE CLEAR AND MAKES MORE SENSE)
# https://leetcode.com/problems/jump-game-ii/solutions/3158218/c-faster-than-75-straight-forward-method-clean-and-concise-code/
class Solution {
public:

    int jump(vector<int>& nums) {
      # Solution -> for each index, calculates the farthest you can jump, also checking if you can jump farther from any other previous indicies
      # Iterate through nums, jumping at every index, count the number of jumps until you reach the end.
      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }
};
