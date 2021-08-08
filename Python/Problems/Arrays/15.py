"""
https://leetcode.com/problems/merge-intervals/
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
"""


# Time Complexity O(n+nlogn) => O(nlogn)
# Space Complexity O(n)
def merge_intervals(input_array):
    input_array.sort()  # Time Complexity O(n log n)
    merged_intervals = []

    for interval in input_array:  # Time Complexity O(n)
        if len(merged_intervals) is 0:
            merged_intervals.append(interval)
            continue

        last_merged_interval = merged_intervals[len(merged_intervals) - 1]

        if last_merged_interval[1] >= interval[0]:
            last_merged_interval = [last_merged_interval[0], interval[1]]
            merged_intervals[len(merged_intervals) - 1] = last_merged_interval
        else:
            merged_intervals.append(interval)
    return merged_intervals


if __name__ == "__main__":
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]

    print merge_intervals(intervals)
