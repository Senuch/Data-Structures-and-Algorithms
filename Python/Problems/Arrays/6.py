"""
https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output:
5
Explanation:
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.
"""


# Time Complexity O((m+n) log (m+n))
def union(input_list_a, input_list_b):
    input_list_a.sort()  # O(log m)
    input_list_b.sort()  # O(log n)

    pointer_a, pointer_b = 0, 0

    union_list = []
    union_count = 0

    while pointer_a < len(input_list_a) and pointer_b < len(input_list_b):
        if input_list_a[pointer_a] < input_list_b[pointer_b]:
            union_list.append(input_list_a[pointer_a])
            pointer_a += 1
        elif input_list_b[pointer_b] < input_list_a[pointer_a]:
            union_list.append(input_list_b[pointer_b])
            pointer_b += 1
        else:
            union_list.append(input_list_a[pointer_a])
            pointer_a += 1
            pointer_b += 1
        union_count += 1

    # Pushing remaining values
    while pointer_a < len(input_list_a):
        union_list.append(input_list_a[pointer_a])
        pointer_a += 1
        union_count += 1

    # Pushing remaining values
    while pointer_b < len(input_list_b):
        union_list.append(input_list_b[pointer_b])
        pointer_b += 1
        union_count += 1

    return union_count


if __name__ == "__main__":
    a = [5, 3, 6, 7, 8]
    b = [1, 2, 3, 4, 5]

    union_list = union(a, b)

    print union_list
