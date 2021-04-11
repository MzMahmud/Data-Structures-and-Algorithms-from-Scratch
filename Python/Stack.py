from LinkedList import LinkedList


class Stack:
    def __init__(self):
        self.__linked_list = LinkedList()

    def push(self, val):
        self.__linked_list.push_front(val)

    def pop(self):
        try:
            return self.__linked_list.pop_front()
        except:
            raise Exception('Can not pop Empty Stack!')

    def top(self):
        try:
            return self.__linked_list.peek_head()
        except:
            raise Exception('Can not get top of Empty Stack!')

    def is_empty(self):
        return len(self) == 0

    def __len__(self):
        return len(self.__linked_list)

    def __str__(self):
        return f'Stack [{self.__linked_list.get_str_separated_by()}]'

    def __iter__(self):
        return iter(self.__linked_list)

    @classmethod
    def from_array(cls, array):
        stack = cls()
        for elem in array:
            stack.push(elem)
        return stack


def test():
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)
    print(stack)
    print('top', stack.top())
    print('size', len(stack))
    while not stack.is_empty():
        print(stack.pop())
    stack.push(3)
    stack.push(4)
    stack.push(5)
    print(stack)
    print('top', stack.top())
    print('size', len(stack))

    stack = Stack.from_array([1, 2, 3, 4, 5])
    print('iterate with for loop')
    for val in stack:
        print(val)


if __name__ == '__main__':
    test()
