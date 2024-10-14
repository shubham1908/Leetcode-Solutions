import heapq
from math import ceil

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = []
        heapq.heapify(pq)
        for item in nums:
            heapq.heappush(pq, item *-1)
         
        ans = 0
        for _ in range(k):
            x = -1* heapq.heappop(pq)
            ans += x
            heapq.heappush(pq, ceil(x/3) * -1)
        return ans