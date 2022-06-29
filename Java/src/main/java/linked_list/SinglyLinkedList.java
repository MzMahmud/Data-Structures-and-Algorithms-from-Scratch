package linked_list;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class SinglyLinkedList<T> implements Iterable<T> {

    private Node<T> head, tail;
    private int length;

    public SinglyLinkedList() {
        head = tail = null;
        length = 0;
    }

    @SafeVarargs
    public SinglyLinkedList(T... values) {
        this();
        Arrays.stream(values)
              .sequential()
              .forEach(this::pushBack);
    }

    public SinglyLinkedList(Collection<T> collection) {
        this();
        collection.forEach(this::pushBack);
    }

    public int size() {
        return length;
    }

    public void pushFront(T value) {
        head = new Node<>(value, head);
        if (tail == null) {
            tail = head;
        }
        ++length;
    }

    public void pushBack(T value) {
        var newNode = new Node<>(value);
        if (tail != null) {
            tail.next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        ++length;
    }

    public T popFront() throws NoSuchElementException {
        if (head == null) {
            throw listEmptyException;
        }
        T headData = head.data;
        head = head.next;
        --length;
        if (length == 0) {
            tail = head;
        }
        return headData;
    }

    public T peekHead() throws NoSuchElementException {
        if (head == null) {
            throw listEmptyException;
        }
        return head.data;
    }

    public T peekTail() throws NoSuchElementException {
        if (tail == null) {
            throw listEmptyException;
        }
        return tail.data;
    }

    public Stream<T> stream() {
        return Stream.iterate(head, Objects::nonNull, current -> current.next)
                     .map(Node::getData);
    }

    private String getString() {
        return stream().map(Objects::toString)
                       .collect(Collectors.joining(", ", "[", "]"));
    }

    @Override
    public String toString() {
        return getString();
    }

    @Override
    public Iterator<T> iterator() {
        return new SinglyLinkedListIterator<>(head);
    }

    public static final class SinglyLinkedListIterator<T> implements Iterator<T> {
        private Node<T> current;

        public SinglyLinkedListIterator(Node<T> current) {
            this.current = current;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            var data = current.data;
            current = current.next;
            return data;
        }
    }

    private static final NoSuchElementException listEmptyException = new NoSuchElementException("list is empty");

    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }

        Node(T data) {
            this(data, null);
        }

        T getData() {
            return data;
        }
    }
}