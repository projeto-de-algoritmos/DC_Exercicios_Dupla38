from typing import List

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        def merge_sort(lo: int, hi: int) -> int:
            if lo == hi:
                return 0
            
            mid = (lo + hi) // 2
            count = merge_sort(lo, mid) + merge_sort(mid + 1, hi)
            
            # Contagem de range sums cruzados
            i = j = mid + 1
            for left_sum in prefix_sums[lo:mid+1]:
                while i <= hi and prefix_sums[i] - left_sum < lower:
                    i += 1
                while j <= hi and prefix_sums[j] - left_sum <= upper:
                    j += 1
                count += j - i
            
            # Merge Sort
            merged = []
            i = lo
            j = mid + 1
            while i <= mid and j <= hi:
                if prefix_sums[i] <= prefix_sums[j]:
                    merged.append(prefix_sums[i])
                    i += 1
                else:
                    merged.append(prefix_sums[j])
                    j += 1
            
            while i <= mid:
                merged.append(prefix_sums[i])
                i += 1
            while j <= hi:
                merged.append(prefix_sums[j])
                j += 1
            
            prefix_sums[lo:hi+1] = merged
            
            return count
        
        prefix_sums = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            prefix_sums[i+1] = prefix_sums[i] + nums[i]
        
        return merge_sort(0, len(prefix_sums) - 1)
