"""
https://leetcode.com/problems/find-the-duplicate-number/
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
"""


# Time Complexity O(n)
# Space Complexity O(1)
def find_duplicates(arr):
    slow_pointer = fast_pointer = arr[0]
    while True:
        slow_pointer = arr[slow_pointer]
        fast_pointer = arr[arr[fast_pointer]]
        if slow_pointer == fast_pointer:
            break

    slow_pointer = arr[0]
    while True:
        if slow_pointer == fast_pointer:
            return slow_pointer
        slow_pointer = arr[slow_pointer]
        fast_pointer = arr[fast_pointer]


if __name__ == "__main__":
    nums = [2, 6, 4, 1, 3, 1, 5]
    print find_duplicates(nums)
