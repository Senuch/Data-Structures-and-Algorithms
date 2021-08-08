"""
https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
Given an array, rotate the array by one position in clock-wise direction.

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
"""


# Time Complexity O(n)
# Space Complexity O(1)
def rotate_array(input_list):
    if len(input_list) is 0 or len(input_list) is 1:
        return

    tail_value = input_list[0]
    for index in range(1, len(input_list)):
        temp = input_list[index]
        input_list[index] = tail_value
        tail_value = temp

    input_list[0] = tail_value


if __name__ == "__main__":
    input_list = [1, 2, 3, 4, 5]

    rotate_array(input_list)
    print input_list
