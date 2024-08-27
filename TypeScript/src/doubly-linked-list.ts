class DoublyLinkedList<T> {
    private head: DoublyLinkedListNode<T> | undefined = undefined;
    private tail: DoublyLinkedListNode<T> | undefined = undefined;
    private size: number = 0;
    get length() { return this.size; }

    constructor(data?: Iterable<T>) {
        if (data != null) for (const value of data) this.pushBack(value);
    }

    pushBack(value: T) {
        this.size++;
        if (this.tail == null) {
            this.tail = this.head = { value };
        } else {
            this.tail = this.tail.next = { prev: this.tail, value };
        }
        return this.tail;
    }

    pushFront(value: T) {
        this.size++;
        if (this.head == null) {
            this.head = this.tail = { value };
        } else {
            this.head = this.head.prev = { value, next: this.head };
        }
        return this.head;
    }

    popBack() {
        if (this.tail == null) {
            throw Error("can not popBack from empty list");
        }
        this.size--;
        const value = this.tail.value;
        if (this.tail.prev == null) {
            this.head = this.tail = undefined;
        } else {
            this.tail.prev.next = undefined;
            this.tail = this.tail.prev;
        }
        return value;
    }

    popFront() {
        if (this.head == null) {
            throw Error("can not popFront from empty list");
        }
        this.size--;
        const value = this.head.value;
        if (this.head.next == null) {
            this.head = this.tail = undefined;
        } else {
            this.head.next.prev = undefined;
            this.head = this.head.next;
        }
        return value;
    }

    pop(node: DoublyLinkedListNode<T>) {
        if (node === this.head) return this.popFront();
        if (node === this.tail) return this.popBack();
        this.size--;
        node.prev!.next = node.next;
        node.next!.prev = node.prev;
        return node.value;
    }

    pushAfter(node: DoublyLinkedListNode<T>, value: T) {
        if (node === this.tail) return this.pushBack(value);
        this.size++;
        const pushed: DoublyLinkedListNode<T> = { value };
        const next = node.next!;
        next.prev = pushed;
        pushed.next = next;
        node.next = pushed;
        pushed.prev = node;
        return pushed;
    }

    pushBefore(node: DoublyLinkedListNode<T>, value: T) {
        if (node === this.head) return this.pushFront(value);
        this.size++;
        const pushed: DoublyLinkedListNode<T> = { value };
        const prev = node.prev!;
        prev.next = pushed;
        pushed.prev = prev;
        node.prev = pushed;
        pushed.next = node;
        return pushed;
    }

    toString() {
        const values: string[] = [];
        for (let node = this.head; node != null; node = node.next) {
            values.push(`${node.value}`);
        }
        return `DoublyLinkedList(${values.join(" <-> ")})`;
    }
}

type DoublyLinkedListNode<T> = {
    prev?: DoublyLinkedListNode<T>;
    value: T
    next?: DoublyLinkedListNode<T>;
}
