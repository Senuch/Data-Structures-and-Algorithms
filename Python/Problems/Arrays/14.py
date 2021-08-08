"""
https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.


Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which
is a contiguous subarray
"""

# Time Complexity O(n)
# Space Complexity O(1)
def kadane_algorithm(input_array):
    max_sum = float("-inf")
    sub_array_sum = 0

    for value in input_array:
        sub_array_sum += value
        max_sum = max(sub_array_sum, max_sum)
        sub_array_sum = max(0, sub_array_sum)

    return max_sum


if __name__ == "__main__":
    array = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print kadane_algorithm(array)
