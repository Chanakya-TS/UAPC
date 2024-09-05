class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Sort all items in list in descending order, iterate through the list and 
        # consider every ith element to be the smaller one of the two endpoints,
        # hence height[i] will always be the height of the water rectangle. Now, we need to
        # find the best pillar j (where j < i && height[j] > height[i]).
        # Since we are iterating in descending order, every pillar we encountered will be bigger
        # than the ith pillar, if we keep track of the minimum index we encountered, and max index
        # we encountered, we can calculate two possible water holds. Iterate through every element
        # and return max of all possible water holds.
        
        height = sorted(enumerate(height), key=lambda x: x[1], reverse=True)
        minIndex = len(height)
        maxIndex = -1

        answer = 0

        for h in height:
            minIndex = min(minIndex, h[0])
            maxIndex = max(maxIndex, h[0])
            answer = max(answer, h[1] * abs(h[0] - minIndex), h[1] * abs(h[0] - maxIndex))

        return answer
