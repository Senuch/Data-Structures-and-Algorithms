"""
https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
Maximum and minimum of an array using minimum number of comparisons
"""


# Time Complexity O(n)
def find_pair(input):
    if len(input) == 0:
        return None, None

    if len(input) == 1:
        return input[0], input[0]

    min, max = input[0], input[1]

    for i in range(2, len(input), 1):
        min = input[i] if input[i] < min else min
        max = input[i] if input[i] > max else max

    return min, max


if __name__ == '__main__':
    input = [1, 2, 3, 4, 5, 6, 7, 8, 9, -1]

    min, max = find_pair(input)

    print min, max
