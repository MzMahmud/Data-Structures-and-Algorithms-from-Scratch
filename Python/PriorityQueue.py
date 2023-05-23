from functools import cmp_to_key

default_compare_fn = lambda a, b: -1 if a < b else 0 if a == b else 1

class PriorityQueue:
    def __init__(self, data=None, compare_fn=None):
        self._heap = [] if data is None else list(data)
        self._compare_fn = default_compare_fn if compare_fn is None else compare_fn
        self._build_heap()
    
    def __len__(self):
        return len(self._heap)
    
    def is_empty(self):
        return len(self) == 0
    
    def __bool__(self):
        return not self.is_empty()
    
    def add(self, value):
        self._heap.append(value)
        self._heapify_up(len(self._heap) - 1)
    
    def peek(self):
        if self.is_empty():
            raise "PriorityQueue empty"
        return self._heap[0]
    
    def poll(self):
        if self.is_empty():
            raise "PriorityQueue empty"
        top = self._heap[0]
        self._swap(0, len(self._heap) - 1)
        self._heap.pop()
        self._heapify_down(0)
        return top
    
    def __iter__(self):
        self._sorted_heap = sorted(self._heap, key=cmp_to_key(self._compare_fn))
        self.index = 0
        return self

    def __next__(self):
        if self.index >= len(self._sorted_heap):
            raise StopIteration
        value = self._sorted_heap[self.index]
        self.index += 1
        return value
    
    def _swap(self, i, j):
        self._heap[i], self._heap[j] = self._heap[j], self._heap[i]
    
    def _parent(self, index):
        return (index - 1) >> 1
    
    def _left(self, index):
        return (index << 1) + 1
    
    def _right(self, index):
        return (index << 1) + 2
    
    def _more_priority(self, i, j):
        return self._compare_fn(self._heap[i], self._heap[j]) < 0

    def _heapify_up(self, start):
        while start > 0 and self._more_priority(start, parent := self._parent(start)):
            self._swap(start, parent)
            start = parent

    def _high_priority_idx(self, start):
        high_priority = start
        size, left, right = len(self), self._left(start), self._right(start)
        if left < size and self._more_priority(left, high_priority):
            high_priority = left
        if right < size and self._more_priority(right, high_priority):
            high_priority = right
        return high_priority
        
    def _heapify_down(self, start):
        while start != (high_priority := self._high_priority_idx(start)):
            self._swap(start, high_priority)
            start = high_priority

    def _build_heap(self):
        last_parent = self._parent(len(self._heap) - 1)
        for start in range(last_parent, -1, -1):
            self._heapify_down(start)
