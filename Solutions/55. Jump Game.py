class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # Iterate through the nums, calculate the max index you can reach from that point, store the max
        # of max indexes, because you should be able to reach every index before max index.
        # if i ever is greater than max index, you shouldn't be able to reach it, hence, return False
        # return True if max index is greater than the last index, self explanatory
        maxIndex = 0
        for i in range(len(nums)):
            if i > maxIndex:
                return False

            maxIndex = max(maxIndex, nums[i] + i)
        
        return maxIndex >= len(nums)-1
