"""
https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
Given an array (or string), the task is to reverse the array/string.
Examples :


Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}
"""


# Time Complexity O(n)
# Space Complexity O(1)
def reverse(input):
    length = len(input)

    if length is 0:
        print "Passed input is empty!"
        return

    i, j = 0, length - 1

    while i < j:
        temp = input[i]
        input[i] = input[j]
        input[j] = temp

        i += 1
        j -= 1


if __name__ == '__main__':
    input = [1, 2]

    reverse(input)

    print input
