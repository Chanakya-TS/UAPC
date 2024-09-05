# https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

class Solution(object):
    def minMovesToSeat(self, seats, students):
        """
        :type seats: List[int]
        :type students: List[int]
        :rtype: int
        """
        answer = 0
        n = len(seats)
        
        # Sort both lists
        seats.sort()
        students.sort()

        for i in range(n):
            # student[i] needs to go to ith seat
            # abs(student[i] - seats[i]) is the distance the student needs to travel
            answer += abs(students[i] - seats[i])

        return answer
