"""
https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
Move all negative numbers to beginning and positive to end with constant extra space
Difficulty Level : Easy
Last Updated : 09 Jun, 2021
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples :

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.
"""


def swap_index_values(input_list, i, j):
    temp = input_list[i]
    input_list[i], input_list[j] = input_list[j], temp

# Time Complexity O(n)
# Space Complexity O(1)
def sort_array(input_list):
    i, j = 0, len(input_list) - 1

    while i < j:

        if input_list[i] >= 0 and input_list[j] < 0:
            swap_index_values(input_list, i, j)

        i = i + 1 if input_list[i] < 0 else i
        j = j - 1 if input_list[j] > -1 else j


if __name__ == "__main__":
    input_list = [-12, 11, -13, -5, 6, -7, 5, -3, -6]

    sort_array(input_list)

    print input_list
