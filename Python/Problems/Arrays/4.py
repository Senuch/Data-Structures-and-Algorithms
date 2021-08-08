"""
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given
array is 7.
"""


class Heap:

    def __init__(self, input_list):
        self.input_list = input_list
        self.__heapify_all__()

    # Time Complexity => n for total number of element and log n for heapify up. O(nlogn)
    def __heapify_all__(self):
        for index, value in enumerate(self.input_list):
            self.__heapify_up__(index, value)

    # Time Complexity => O(log n)
    # Space Complexity => O(1)
    def __heapify_up__(self, index, value):
        while (index - 1) / 2 >= 0 and self.input_list[(index - 1) / 2] < value:
            self.input_list[index] = self.input_list[(index - 1) / 2]
            self.input_list[(index - 1) / 2] = value
            index = (index - 1) / 2

    # Time Complexity => O(log n)
    # Space Complexity => O(1)
    def __heapify_down__(self, index, value):
        while index < len(self.input_list):
            left_child_index = (index * 2) + 1
            right_child_index = (index * 2) + 2

            if left_child_index < len(self.input_list) and right_child_index < len(self.input_list):
                selected_index = left_child_index if self.input_list[left_child_index] > self.input_list[
                    right_child_index] else right_child_index
            elif left_child_index < len(self.input_list):
                selected_index = left_child_index
            elif right_child_index < len(self.input_list):
                selected_index = right_child_index
            else:
                break

            if self.input_list[selected_index] > self.input_list[index]:
                self.input_list[index] = self.input_list[selected_index]
                self.input_list[selected_index] = value
            else:
                break

            index = selected_index

    # Time Complexity => O(log n)
    def push(self, value):
        self.input_list.append(value)
        self.__heapify_up__(len(self.input_list) - 1, value)

    # Time Complexity => O(log n)
    def pop(self):
        top_element = self.peek()

        if top_element is None:
            return top_element

        self.input_list[0] = self.input_list[len(self.input_list) - 1]
        self.input_list.pop()

        if len(self.input_list) > 0:
            self.__heapify_down__(0, self.input_list[0])

        return top_element

    # Time Complexity => O(1)
    def peek(self):
        return self.input_list[0] if len(self.input_list) > 0 else None

    def size(self):
        return len(self.input_list)


# Time Complexity => O(nlogk)
# Space Complexity => O(1)
def find_k_minimum(k, input_list):
    heap = Heap([])

    for value in input_list:
        if heap.size() <= k:
            heap.push(value)
            if heap.size() > k:
                heap.pop()
    return heap.pop()


if __name__ == "__main__":
    input_list = [5, 20, -1, 30, 50, 70, 88, 92]

    k_min = find_k_minimum(5, input_list)
    print k_min
