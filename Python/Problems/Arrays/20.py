"""
https://practice.geeksforgeeks.org/problems/common-elements1132/1
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
"""


# Time Complexity O(n)
# Space ComplexityO(1)
def find_common_elements(arr1, arr2, arr3):
    i, j, k = 0, 0, 0
    common_elements = []

    while i < len(arr1) and j < len(arr2) and k < len(arr3):
        if arr1[i] == arr2[j] == arr3[k]:
            if arr1[i] not in common_elements:
                common_elements.append(arr1[i])
            i += 1
            j += 1
            k += 1
            continue

        current_max = max(arr1[i], arr2[j], arr3[k])

        if arr1[i] < current_max:
            i += 1
        if arr2[j] < current_max:
            j += 1
        if arr3[k] < current_max:
            k += 1

    return -1 if len(common_elements) is 0 else common_elements


if __name__ == "__main__":
    arr1 = [1, 5, 10, 20, 40, 80]
    arr2 = [6, 7, 20, 80, 100]
    arr3 = [3, 4, 15, 20, 30, 70, 80, 120]

    print find_common_elements(arr1, arr2, arr3)
