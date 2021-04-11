from LinkedList import LinkedList


class Queue:
    def __init__(self):
        self.__linked_list = LinkedList()

    def enqueue(self, val):
        self.__linked_list.push_back(val)

    def dequeue(self):
        try:
            return self.__linked_list.pop_front()
        except:
            raise Exception('Can not dequeue Empty Queue!')

    def front(self):
        try:
            return self.__linked_list.peek_head()
        except:
            raise Exception('Can not get front of Empty Queue!')

    def back(self):
        try:
            return self.__linked_list.peek_tail()
        except:
            raise Exception('Can not get back of Empty Queue!')

    def is_empty(self):
        return len(self) == 0

    def __len__(self):
        return len(self.__linked_list)

    def __str__(self):
        return f'Queue [{self.__linked_list.get_str_separated_by()}]'

    def __iter__(self):
        return iter(self.__linked_list)

    @classmethod
    def from_array(cls, array):
        q = cls()
        for elem in array:
            q.enqueue(elem)
        return q


def test():
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    print(q)
    print('size', len(q))
    print('front', q.front())
    print('back', q.back())
    while not q.is_empty():
        print(q.dequeue())

    q = Queue.from_array([1, 2, 3])
    print(q)
    print('size', len(q))
    print('front', q.front())
    print('back', q.back())
    print('iterate with for loop')
    for val in q:
        print(val)


if __name__ == '__main__':
    test()
