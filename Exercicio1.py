from typing import List

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def merge_sort(arr, indices):
            if len(arr) <= 1:
                return arr, indices
            
            mid = len(arr) // 2
            left, left_indices = merge_sort(arr[:mid], indices[:mid])
            right, right_indices = merge_sort(arr[mid:], indices[mid:])
            return merge(left, right, left_indices, right_indices)
        
        def merge(left, right, left_indices, right_indices):
            merged = []
            count = 0
            i = j = 0
            merged_indices = []
            
            while i < len(left) and j < len(right):
                if left[i] <= right[j]:
                    merged.append(left[i])
                    merged_indices.append(left_indices[i])
                    counts[left_indices[i]] += count
                    i += 1
                else:
                    merged.append(right[j])
                    merged_indices.append(right_indices[j])
                    count += 1
                    j += 1
            
            while i < len(left):
                merged.append(left[i])
                merged_indices.append(left_indices[i])
                counts[left_indices[i]] += count
                i += 1
            
            while j < len(right):
                merged.append(right[j])
                merged_indices.append(right_indices[j])
                j += 1
            
            return merged, merged_indices
        
        n = len(nums)
        counts = [0] * n
        merge_sort(nums, list(range(n)))
        
        return counts
