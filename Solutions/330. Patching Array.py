class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        # Solution -> Keep track of max possible number (mxSum) can satisfy the question constraints
        # While its less than n (our target), check an element from nums, if its less than max possible,
        # then you can add that to a certain number of elements to find sum from [mxSum, mxSum+nums[i]], hence
        # that increases our mxSum to mxSum + nums[i]
        # if nums[i] > mxSum or there are no elements in nums and mxSum hasnt reached the target, we would need
        # to add a patch to get the number mxSum+1 (the patch would be mxSum+1),
        # with the new number, we can increase the max possible number to  2*mxSum + 1, because you can add
        # mxSum+1 (new patch number) to every number before it to get a bigger number until mxSum.
        # Repeat this until mxSum is greater than or equal to our target (n)
        mxSum = 0
        answer = 0
        curIndex = 0

        while mxSum < n:
            if curIndex < len(nums) and nums[curIndex] <= mxSum+1:
                mxSum += nums[curIndex]
                curIndex += 1
            else:
                answer += 1
                mxSum += mxSum + 1

        return answer
