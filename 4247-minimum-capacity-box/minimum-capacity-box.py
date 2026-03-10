class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        n = len(capacity)
        cap = 101
        idx = -1
        for i in range (0,n) :
            if capacity[i] >= itemSize and capacity[i] < cap :
                cap = capacity[i]
                idx = i    
        return idx
