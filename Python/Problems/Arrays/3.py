"""
https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.
"""

# Time Complexity O(n)
# Space Complexity O(n)
def swap_index_values(input, a, b):
    temp = input[a]
    input[a] = input[b]
    input[b] = temp

# Time Complexity O(n)
# Space Complexity O(n)
def sort_array(input):
    if len(input) is 0:
        return None

    low, mid, high = 0, 0, len(input) - 1

    while mid <= high:
        if input[mid] is 0:
            swap_index_values(input, low, mid)
            low += 1
            mid += 1
        elif input[mid] is 1:
            mid += 1
        else:
            swap_index_values(input, mid, high)
            high -= 1


if __name__ == "__main__":
    input = [0,2,1,2,0]

    sort_array(input)

    print input