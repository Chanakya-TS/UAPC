class Solution:
    def minimumSum(self, num: int) -> int:
        # its always best to divide into two 2-digit numbers (because its always better
        # to put a digit in tens place than the hundred's place)
        # Solution -> split digits, put smallest two digits in the two ten's place, and next
        #               smallest digits in the ones place

        digits = [int(d) for d in str(num)]
        digits.sort()

        answer = digits[0] * 10 + digits[1] * 10 + digits[2] + digits[3]

        return answer
