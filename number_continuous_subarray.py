from typing import List
# This solution is wrong, not taking all the subarray into account and inefficient
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # [1] [42,41,42,41,41,40] [39,38]
        # 1 + 3 + (6+1)*3 = 25
        # 9 + 5 + 1 + 4 + 3 + 2 + 1
        map1 = list()
        left = 0
        right = 1
        while right < len(nums):
            if (abs(nums[left] - nums[right]) <= 2):
                right += 1
            else:
                map1.append(nums[left:right])  # = right - left
                # left = 1, right = 7
                left = right
                right += 1
        map1.append(nums[left:right])
        dp1 = [0] * (len(nums)+1)
        for sub in map1:
            rec = len(sub)
            if dp1[rec] == 0:
                cal = ((rec + 1) * rec) / 2
                dp1[rec] = cal
        res = 0
        for sub in map1:
            res += dp1[len(sub)]
        return res
    
if __name__ == "__main__":
    s = Solution()
    #nums = [1,42,41,42,41,41,40,39,38]
    nums = [5,4,2,4]
    print(s.continuousSubarrays(nums))
