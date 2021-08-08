"""
https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.
"""


# Time Complexity O(n)
# Space Complexity O(n)
def find_sum_pair_count(array, target_sum):
    pairs = 0
    value_hash = {}

    for value in array:
        diff = target_sum - value
        if diff in value_hash:
            pairs += value_hash[diff]
        value_hash[value] = 1 if value not in value_hash else value_hash[value] + 1
    return pairs


if __name__ == "__main__":
    input_array = [1, 1, 1, 1]
    print find_sum_pair_count(input_array, 2)
