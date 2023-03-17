export class LinkedList<T> implements Stack<T>, Queue<T> {
    private head: Optional<ListNode<T>>;
    private tail: Optional<ListNode<T>>;
    private nNodes: number;

    constructor() {
        this.head = null;
        this.tail = null;
        this.nNodes = 0;
    }

    pushFront(value: T): void {
        const newNode = new ListNode<T>(value, this.head);
        if (this.head == null) {
            this.tail = newNode;
        }
        this.head = newNode;
        this.nNodes++;
    }

    pushBack(value: T): void {
        const newNode = new ListNode<T>(value);
        if (this.tail == null) {
            this.head = newNode;
        } else {
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.nNodes++;
    }

    popFront(): Optional<T> {
        if (this.head == null) {
            return null;
        }
        this.nNodes--;
        const ret = this.head.value;
        this.head = this.head.next;
        if (this.nNodes == 0) {
            this.tail = this.head;
        }
        return ret;
    }

    isEmpty(): boolean {
        return this.nNodes == 0;
    }

    push(value: T): void {
        this.pushFront(value);
    }

    add(value: T): void {
        this.pushBack(value);
    }

    pop(): Optional<T> {
        return this.popFront();
    }

    poll(): Optional<T> {
        return this.popFront();
    }

    top(): Optional<T> {
        if (this.head == null) {
            return null;
        }
        return this.head.value;
    }

    front(): Optional<T> {
        return this.top();
    }

    length(): number {
        return this.nNodes;
    }

    size(): number {
        return this.length();
    }
}

export interface Stack<T> {
    isEmpty(): boolean;
    size(): number;
    push(value: T): void;
    pop(): Optional<T>;
    top(): Optional<T>;
}

export interface Queue<T> {
    isEmpty(): boolean;
    size(): number;
    add(value: T): void;
    poll(): Optional<T>;
    front(): Optional<T>;
}

export type Optional<T> = T | null;

class ListNode<T> {
    value: T;
    next: Optional<ListNode<T>>;

    constructor(value: T, next: Optional<ListNode<T>> = null) {
        this.value = value;
        this.next = next;
    }
}