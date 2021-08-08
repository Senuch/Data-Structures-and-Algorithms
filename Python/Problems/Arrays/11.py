"""
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3
Explanation:
First jump from 1st element to 2nd
element with value 3. Now, from here
we jump to 5th element with value 9,
and from here we will jump to last.
"""


# Time Complexity O(n)
# Space Complexity O(1)
def find_min_jumps(arr):
    if len(arr) <= 1:
        return 0
    if arr[0] is 0:
        return -1

    max_reach = arr[0]
    available_steps = arr[0]
    jumps = 1

    for index in range(1, len(arr)):
        if index is len(arr) - 1:
            return jumps
        max_reach = max(max_reach, index + arr[index])
        available_steps -= 1
        if available_steps is 0:
            jumps += 1
            if index > max_reach:
                return -1
            available_steps = max_reach - index
    return jumps


if __name__ == "__main__":
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
    print find_min_jumps(arr)
