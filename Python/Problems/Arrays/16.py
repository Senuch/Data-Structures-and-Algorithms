"""
https://leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
"""


# Time Complexity O(n)
# Space Complexity O(1)
def next_permutation(array_input):
    if len(array_input) is 0:
        return array_input

    min_pointer = len(array_input) - 1
    for index, value in reversed(list(enumerate(array_input))):
        if value < array_input[min_pointer]:
            min_pointer = index
            break

    if min_pointer == len(array_input) - 1:
        array_input.reverse()
        return

    next_min_pointer = min_pointer + 1
    current_diff = abs(array_input[next_min_pointer] - array_input[min_pointer])
    for index in range(min_pointer + 2, len(array_input)):
        new_diff = abs(array_input[index] - array_input[min_pointer])
        if new_diff < current_diff:
            next_min_pointer = index
            current_diff = new_diff

    array_input[min_pointer], array_input[next_min_pointer] = array_input[next_min_pointer], array_input[min_pointer]

    i, j = min_pointer + 1, len(array_input) - 1
    while i < j:
        array_input[i], array_input[j] = array_input[j], array_input[i]
        i += 1
        j -= 1


if __name__ == "__main__":
    input_array = [1, 3, 2]
    next_permutation(input_array)
    print input_array
