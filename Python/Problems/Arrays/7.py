"""
https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
Given two arrays a[] and b[] of size n and m respectively. The task is to find intersection between these two arrays.

Intersection of the two arrays can be defined as the set common elements from both the arrays.

Example 1:

Input:
1 2 3 4 5
1 2 3
Output:
3
Explanation:
1, 2 and 3
elements which comes in the intersection set
of both arrays. So count is 3.
"""


# Time Complexity O((m+n) log (m+n))
def intersection(input_list_a, input_list_b):
    input_list_a.sort()  # O(log m)
    input_list_b.sort()  # O(log n)

    pointer_a, pointer_b = 0, 0

    intersection_list = []
    intersection_count = 0

    while pointer_a < len(input_list_a) and pointer_b < len(input_list_b):
        if input_list_a[pointer_a] < input_list_b[pointer_b]:
            pointer_a += 1
        elif input_list_b[pointer_b] < input_list_a[pointer_a]:
            pointer_b += 1
        else:
            intersection_list.append(input_list_a[pointer_a])
            pointer_a += 1
            pointer_b += 1
            intersection_count += 1

    return intersection_count


if __name__ == "__main__":
    a = [5, 3, 6, 7, 8]
    b = [1, 2, 3, 4, 5]

    union_list = intersection(a, b)

    print union_list
