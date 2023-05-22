class ListNode<T> {
    data: T;
    next: ListNode<T> | null;

    constructor(data: T, next?: ListNode<T> | null) {
        this.data = data;
        this.next = next === undefined ? null : next;
    }
}

class Queue<T> implements Iterable<T> {
    private head: ListNode<T> | null = null;
    private tail: ListNode<T> | null = null;
    private length: number = 0;

    constructor(array: T[] = []) {
        for (const data of array) {
            this.add(data);
        }
    }

    size(): number {
        return this.length;
    }

    isEmpty(): boolean {
        return this.length === 0;
    }

    peek(): T {
        if (this.head === null) throw new Error("queue is empty");
        return this.head.data;
    }

    add(value: T) {
        const newNode = new ListNode<T>(value);
        if (this.tail === null) {
            this.head = this.tail = newNode;
        } else {
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.length++;
    }

    poll(): T {
        if (this.head === null) throw new Error("queue is empty");
        const front = this.head.data;
        this.head = this.head.next;
        this.length--;
        if (this.length === 0) {
            this.tail = null;
        }
        return front;
    }

    [Symbol.iterator](): Iterator<T> {
        let head = this.head;
        return {
            next: (): IteratorResult<T> => {
                if (head === null) return { value: undefined, done: true };
                const value = head.data;
                head = head.next;
                return { value: value, done: false };
            }
        }
    }
}
