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
                selected_index = left_child_index if self.input_list[left_child_index] > self.input_list[right_child_index] else right_child_index
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
        self.__heapify_up__(len(self.input_list)-1,value)

    # Time Complexity => O(log n)
    def pop(self):
        top_element = self.peek()

        if top_element is None:
            return top_element

        self.input_list[0] = self.input_list[len(self.input_list) - 1]
        self.input_list.pop()

        if len(self.input_list) > 0:
            self.__heapify_down__(0,self.input_list[0])

        return top_element

    # Time Complexity => O(1)
    def peek(self):
        return self.input_list[0] if len(self.input_list) > 0 else None

    def size(self):
        return len(self.input_list)


if __name__ == "__main__":
    input_list = [5, 20, -1, 30, 50, 70, 88, 92]

    heap = Heap(input_list)