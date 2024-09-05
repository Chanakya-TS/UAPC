class Solution:
    def balancedStringSplit(self, s: str) -> int:
        # Key Insight -> Given string is a balanced string
        # Let S be a balanced string, if S is split into AB such that A is a balanced string
        # then B has to be a balanced string.
        # Informal proof: if S has x R's and x L's (same because its balanced) and
        #                 and if A (balanced string) has y R's and y L's (where y < x)
        #                 then B will have (x-y) R's and (x-y) L's, since it has the
        #                 same number of R's and L's, B is also balanced.
        # Solution -> Iterate through the string, keep count of R's and L's if #R == #L,
        #               valid balanced string, increment answer by 1 then continue

        numberOfRs = numberOfLs = answer = 0

        for letter in s:
            if letter == 'R':
                numberOfRs += 1
            else: numberOfLs += 1

            if numberOfRs == numberOfLs:
                answer += 1
        
        return answer
