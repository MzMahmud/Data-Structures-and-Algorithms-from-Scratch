class DoublyLinkedList:
    class Node:
        def __init__(self, value, prev=None, next=None):
            self.value = value
            self.next = next
            self.prev = prev

    def __init__(self, iterable=None):
        self.head = None
        self.tail = None
        self.length = 0
        if iterable is not None:
            self.extend_back(iterable)

    def append_back(self, value):
        new_node = DoublyLinkedList.Node(value, self.tail, None)
        if self.tail is None:
            self.head = new_node
        else:
            self.tail.next = new_node
        self.tail = new_node
        self.length += 1

    def append(self, value):
        self.append_back(value)

    def extend_back(self, iterable):
        for value in iterable:
            self.append_back(value)

    def extend(self, iterable):
        self.extend_back(iterable)

    def append_front(self, value):
        new_node = DoublyLinkedList.Node(value, None, self.head)
        if self.head is None:
            self.tail = new_node
        else:
            self.head.prev = new_node
        self.head = new_node
        self.length += 1

    def extend_front(self, iterable):
        for value in reversed(iterable):
            self.append_front(value)

    def pop_back(self):
        if self.tail is None:
            raise Exception
        if self.tail.prev is None:
            self.head = None
        else:
            self.tail.prev.next = None
        popped = self.tail.value
        self.tail = self.tail.prev
        self.length -= 1
        return popped

    def pop(self):
        return self.pop_back()

    def pop_front(self):
        if self.head is None:
            raise Exception
        if self.head.next is None:
            self.tail = None
        else:
            self.head.next.prev = None
        popped = self.head.value
        self.head = self.head.next
        self.length -= 1
        return popped

    def peek_back(self):
        if self.tail is None:
            raise Exception
        return self.tail.value

    def peek_front(self):
        if self.head is None:
            raise Exception
        return self.head.value

    def get_str(self, prefix, seperator, suffix):
        list_str = []
        curr = self.head
        while curr is not None:
            list_str.append(f'{curr.value}')
            curr = curr.next
        return f'{prefix}{seperator.join(list_str)}{suffix}'

    def __str__(self):
        return self.get_str("", " <-> ", "")

    def __repr__(self):
        return f'DoublyLinkedList({self.get_str("[", ",", "]")})'

    def __len__(self):
        return self.length

    def __iter__(self):
        self.iter_curr = self.head
        return self

    def __next__(self):
        if self.iter_curr is None:
            raise StopIteration
        next_value = self.iter_curr.value
        self.iter_curr = self.iter_curr.next
        return next_value

    def __reversed__(self):
        curr = self.tail
        while curr is not None:
            yield curr.value
            curr = curr.prev


def test():
    doubly_linked_list = DoublyLinkedList([1, 2])
    doubly_linked_list.append_back(3)
    doubly_linked_list.append_back(4)
    doubly_linked_list.append_front(0)
    print(doubly_linked_list)
    print(doubly_linked_list.peek_back())
    print(doubly_linked_list.peek_front())
    print('len', len(doubly_linked_list))
    print(doubly_linked_list.pop_front())
    print('len', len(doubly_linked_list))
    print(doubly_linked_list)
    doubly_linked_list.extend_back([4, 5, 6])
    print(doubly_linked_list)
    doubly_linked_list.extend_front([-2, -1, 0])
    print(doubly_linked_list)

    for value in doubly_linked_list:
        print(value, end=" <-> ")
    print()
    for value in doubly_linked_list:
        print(value, end=" <-> ")
    print()
    for value in reversed(doubly_linked_list):
        print(value, end=" <-> ")
    print()
    print(repr(doubly_linked_list))


if __name__ == '__main__':
    test()
