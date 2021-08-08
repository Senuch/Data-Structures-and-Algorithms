"""
https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).
"""
import math


# Time Complexity O(nlogn)
# Space Complexity O(n)
def merge(arr, low, mid, high):
    i, j = low, mid + 1
    sorted_array = []
    inversions = 0
    while i <= mid and j <= high:
        if arr[i] <= arr[j]:
            sorted_array.append(arr[i])
            i += 1
        else:
            sorted_array.append(arr[j])
            inversions += len(range(i, mid + 1))
            j += 1

    if i <= mid:
        sorted_array += arr[i: mid + 1]
    if j <= high:
        sorted_array += arr[j: high + 1]

    for index in range(len(sorted_array)):
        arr[low + index] = sorted_array[index]

    return inversions


def merge_sort(arr, low, high):
    inversion = 0
    if low < high:
        mid = int(math.floor(low + high) / 2)
        inversion += merge_sort(arr, low, mid)
        inversion += merge_sort(arr, mid + 1, high)
        inversion += merge(arr, low, mid, high)
    return inversion


def inversion_count(arr):
    return merge_sort(arr, 0, len(arr) - 1)


if __name__ == "__main__":
    input_array = [2, 4, 1, 3, 5]
    print inversion_count(input_array)
