type CompareFn<T> = (a: T, b: T) => number;

class PriorityQueue<T> implements Iterable<T> {
    private heap: T[] = [];
    private compareFn: CompareFn<T> = (a, b) => a === b ? 0 : (a < b ? -1 : 1);

    constructor(data?: Iterable<T>, compareFn?: CompareFn<T>) {
        if (data != null) this.heap = [...data];
        if (compareFn != null) this.compareFn = compareFn;
        this.buildHeap();
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    add(value: T) {
        this.heap.push(value);
        this.heapifyUp(this.heap.length - 1);
    }

    peek() {
        if (this.isEmpty()) throw new Error('PriorityQueue is empty');
        return this.heap[0];
    }

    poll() {
        if (this.isEmpty()) throw new Error('PriorityQueue is empty');
        const top = this.heap[0];
        this.swap(0, this.heap.length - 1);
        this.heap.pop();
        this.heapifyDown(0);
        return top;
    }

    [Symbol.iterator](): Iterator<T> {
        const heap = [...this.heap].sort(this.compareFn);
        let index = 0;
        return {
            next: (): IteratorResult<T> => {
                if (index === heap.length) {
                    return { value: undefined, done: true };
                }
                return { value: heap[index++], done: false };
            }
        };
    }

    private parent(index: number) {
        return (index - 1) >> 1;
    }

    private left(index: number) {
        return (index << 1) + 1;
    }

    private right(index: number) {
        return (index << 1) + 2;
    }

    private compare(i: number, j: number) {
        return this.compareFn(this.heap[i], this.heap[j]);
    }

    private swap(i: number, j: number) {
        const temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }

    private heapifyUp(start: number) {
        while (start > 0 && this.compare(start,this.parent(start)) < 0) {
            const parent = this.parent(start);
            this.swap(start, parent);
            start = parent;
        }
    }

    private heapifyDown(start: number) {
        const size = this.size(), left = this.left(start), right = this.right(start);
        let minIndex = start;
        if (left < size && this.compare(left, minIndex) < 0) {
            minIndex = left;
        }
        if (right < size && this.compare(right, minIndex) < 0) {
            minIndex = right;
        }
        if (minIndex !== start) {
            this.swap(start, minIndex);
            this.heapifyDown(minIndex);
        }
    }

    private buildHeap() {
        let start = (this.size() >> 1) - 1;
        for (; start >= 0; start--) {
            this.heapifyDown(start);
        }
    }
}
