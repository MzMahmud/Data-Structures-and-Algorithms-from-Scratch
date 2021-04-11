class LinkedList:
    class Node:
        def __init__(self, val, next=None):
            self.val = val
            self.next = next

    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def push_back(self, val):
        new_node = LinkedList.Node(val)
        if self.__tail == None:
            self.__head = self.__tail = new_node
        else:
            self.__tail.next = new_node
            self.__tail = new_node
        self.__size += 1

    def pop_front(self):
        if self.__head == None:
            raise Exception("Can't pop_back from empty list!")
        to_return = self.__head.val
        self.__head = self.__head.next
        self.__size -= 1
        if self.__size == 0:
            self.__tail = None
        return to_return

    def push_front(self, val):
        new_node = LinkedList.Node(val)
        if self.__head == None:
            self.__head = self.__tail = new_node
        else:
            new_node.next = self.__head
            self.__head = new_node
        self.__size += 1

    def peek_head(self):
        if self.__head == None:
            raise Exception("Can't peek head of empty list!")
        return self.__head.val

    def peek_tail(self):
        if self.__tail == None:
            raise Exception("Can't peek tail of empty list!")
        return self.__tail.val

    def comma_separated_str(self):
        curr = self.__head
        out = []
        while curr:
            out.append(f'{curr.val}')
            curr = curr.next
        return ','.join(out)

    def __len__(self):
        return self.__size

    def __str__(self):
        curr = self.__head
        out = []
        while curr:
            out.append(f'{curr.val}')
            curr = curr.next
        return '->'.join(out)

    def __iter__(self):
        curr = self.__head
        while curr:
            yield curr.val
            curr = curr.next

    @classmethod
    def from_array(cls, array):
        linked_list = cls()
        for elem in array:
            linked_list.push_back(elem)
        return linked_list


def test():
    # print(dir(LinkedList))
    linked_list = LinkedList()
    # linked_list.pop_front()
    linked_list.push_back(1)
    linked_list.push_back(2)
    linked_list.push_back(3)
    print(linked_list)
    print('size', len(linked_list))
    linked_list.push_front(4)
    linked_list.push_front(5)
    print(linked_list)
    print('size', len(linked_list))
    print('popped', linked_list.pop_front())
    print('popped', linked_list.pop_front())
    print('popped', linked_list.pop_front())
    print('popped', linked_list.pop_front())
    print('popped', linked_list.pop_front())
    linked_list.push_front(1)
    linked_list.push_back(2)
    linked_list.push_front(3)
    print(linked_list)
    print('size', len(linked_list))
    linked_list = LinkedList.from_array([1, 2, 3, 4])
    print('iterate with for in loop')
    linked_list.push_back(5)
    linked_list.push_back(6)
    for val in linked_list:
        print(val)
    print('list comprehention', [val for val in linked_list])


if __name__ == '__main__':
    test()
