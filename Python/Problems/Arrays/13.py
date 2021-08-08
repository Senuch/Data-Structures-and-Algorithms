"""
https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any
extra space, modify the given arrays
to form
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}
"""


# Time Complexity O(m+n)
# Space Complexity O(1)
def merge_sorted_arrays(arr1, arr2):
    pointer_1 = 0
    pointer_2 = 0

    while pointer_1 < len(arr1) and pointer_2 < len(arr2):
        pointer_1_value = arr1[pointer_1]
        pointer_2_value = arr2[pointer_2]

        if pointer_1_value < pointer_2_value:
            print pointer_1_value
            pointer_1 += 1
        elif pointer_2_value < pointer_1_value:
            print pointer_2_value
            pointer_2 += 1
        else:
            print pointer_1_value
            pointer_1 += 1
            pointer_2 += 1

    while pointer_1 < len(arr1):
        print arr1[pointer_1]
        pointer_1 += 1

    while pointer_2 < len(arr2):
        print arr2[pointer_2]
        pointer_2 += 1


if __name__ == "__main__":
    arr_1 = [1, 3, 5, 7]
    arr_2 = [0, 2, 6, 8, 9]

    merge_sorted_arrays(arr_1, arr_2)
