class PriorityQueue:
    def __init__(self, compare_function=None):
        self.__array = []
        self.__compare_function = compare_function

    def add(self, value):
        self.__array.append(value)
        self.__heapify_up(len(self.__array) - 1)

    def peek(self):
        return self.__array[0]

    def poll(self):
        top_item = self.peek()
        n = len(self.__array) - 1
        self.__array[0], self.__array[n] = self.__array[n], self.__array[0]
        self.__array.pop()
        self.__heapify_down(0)
        return top_item

    def __len__(self):
        return len(self.__array)

    def __repr__(self):
        return f'PriorityQueue([{self.__array}])'

    def is_empty(self):
        return len(self) == 0

    def __heapify_up(self, current_index):
        parent_index = PriorityQueue.__i_parent(current_index)
        while current_index > 0 and self.__has_more_priority(current_index, parent_index):
            PriorityQueue.__swap(current_index, parent_index, self.__array)
            current_index = parent_index
            parent_index = PriorityQueue.__i_parent(current_index)

    def __heapify_down(self, current_index):
        max_index = len(self.__array)
        while (left_child_index := PriorityQueue.__i_left_child(current_index)) < max_index:
            min_value_index = left_child_index
            right_child_index = left_child_index + 1
            if right_child_index < max_index and self.__has_more_priority(right_child_index, min_value_index):
                min_value_index = right_child_index
            if self.__has_more_priority(min_value_index, current_index):
                PriorityQueue.__swap(min_value_index, current_index, self.__array)
                current_index = min_value_index
            else:
                break

    def __has_more_priority(self, index_1, index_2):
        if self.__compare_function is None:
            return self.__array[index_1] < self.__array[index_2]
        return self.__compare_function(self.__array[index_1], self.__array[index_2]) < 0

    @staticmethod
    def __swap(i, j, array):
        array[i], array[j] = array[j], array[i]

    @staticmethod
    def __i_parent(index):
        return (index - 1) // 2

    @staticmethod
    def __i_left_child(index):
        return 2 * index + 1
