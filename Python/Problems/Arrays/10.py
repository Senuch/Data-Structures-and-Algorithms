"""
https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as
{3, 3, 6, 8}. The difference between
the largest and the smallest is 8-3 = 5.
"""


# Time Complexity O(n log n)
# Space Complexity O(1)
def min_max_diff(input_list, k):
    input_list.sort()
    max_diff = input_list[len(input_list) - 1] - input_list[0]
    current_min = input_list[0] + k
    current_max = input_list[len(input_list) - 1] - k

    for index in range(len(input_list) - 1):
        current_min = min(current_min,
                          ((input_list[index + 1] - k) if (input_list[index + 1] - k) >= 0 else current_min))
        current_max = max(current_max, input_list[index] + k)
        max_diff = min(max_diff, abs(current_max - current_min))

    return max_diff


if __name__ == "__main__":
    input_list = [1, 5, 8, 10]
    print min_max_diff(input_list, 2)
