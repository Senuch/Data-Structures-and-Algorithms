"""
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
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
is a contiguous subarray.
"""


# Time Complexity O(n)
# Space Complexity O(1)
def kadane_subarray_sum(input_list):
    max_sum = float("-INF")
    itr_sum = 0

    for value in input_list:
        itr_sum += value
        max_sum = itr_sum if itr_sum > max_sum else max_sum
        itr_sum = 0 if itr_sum < 0 else itr_sum

    return max_sum


if __name__ == "__main__":
    input_list = [1, 2, 3, -2, 5]
    print kadane_subarray_sum(input_list)
