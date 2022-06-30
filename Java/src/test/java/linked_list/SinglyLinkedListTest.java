package linked_list;

import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.NoSuchElementException;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class SinglyLinkedListTest {

    @Test
    void printEmptyList() {
        var singlyLinkedList = new SinglyLinkedList<>();
        System.out.println(singlyLinkedList);
        System.out.printf("size = %d\n", singlyLinkedList.size());
    }

    @Test
    void givenEmptyList_pushBackTest() {
        var singlyLinkedList = new SinglyLinkedList<>();
        singlyLinkedList.pushBack(1);
        System.out.println(singlyLinkedList);
        System.out.printf("size = %d\n", singlyLinkedList.size());
    }

    @Test
    void givenEmptyList_pushFrontTest() {
        var singlyLinkedList = new SinglyLinkedList<>();
        singlyLinkedList.pushFront(1);
        System.out.println(singlyLinkedList);
        System.out.printf("size = %d\n", singlyLinkedList.size());
    }

    @Test
    void givenEmptyList_pushFrontPushBackTest() {
        var singlyLinkedList = new SinglyLinkedList<>();
        singlyLinkedList.pushFront(1);
        singlyLinkedList.pushBack(2);
        singlyLinkedList.pushFront(3);
        singlyLinkedList.pushFront(4);
        singlyLinkedList.pushBack(5);
        System.out.println(singlyLinkedList);
        System.out.printf("size = %d\n", singlyLinkedList.size());
    }

    @Test
    void constructorTest() {
        System.out.println(new SinglyLinkedList<>());
        System.out.println(new SinglyLinkedList<>(1));
        System.out.println(new SinglyLinkedList<>(1, 2, 3));
        System.out.println(new SinglyLinkedList<>(List.of(1, 2, 3)));
    }

    @Test
    void streamTest() {
        new SinglyLinkedList<>()
                .stream()
                .forEach(System.out::println);

        new SinglyLinkedList<>(1, 2, 3)
                .stream()
                .map(n -> n * n)
                .forEach(System.out::println);
    }

    @Test
    void givenEmptyList_throwsNoSuchElementException() {
        assertThrows(
                NoSuchElementException.class,
                () -> new SinglyLinkedList<>().peekHead()
        );
        assertThrows(
                NoSuchElementException.class,
                () -> new SinglyLinkedList<>().peekTail()
        );
        assertThrows(
                NoSuchElementException.class,
                () -> new SinglyLinkedList<>().popFront()
        );
    }

    <T> void assertIsEmpty(SinglyLinkedList<T> singlyLinkedList) {
        assertEquals(0, singlyLinkedList.size());
        assertThrows(NoSuchElementException.class, singlyLinkedList::peekHead);
        assertThrows(NoSuchElementException.class, singlyLinkedList::peekTail);
        assertThrows(NoSuchElementException.class, singlyLinkedList::popFront);
    }

    @Test
    void givenSingleElementList_peekPopTest() {
        var singlyLinkedList = new SinglyLinkedList<>(1);
        assertEquals(1, singlyLinkedList.peekHead());
        assertEquals(1, singlyLinkedList.peekTail());

        assertEquals(1, singlyLinkedList.popFront());
        assertIsEmpty(singlyLinkedList);
    }

    @Test
    void givenMultiElementList_peekTest() {
        var singlyLinkedList = new SinglyLinkedList<>(1, 2, 3);
        assertEquals(1, singlyLinkedList.peekHead());
        assertEquals(3, singlyLinkedList.peekTail());

        System.out.println(singlyLinkedList.popFront());
        System.out.printf("singlyLinkedList %s\nsize %d\n", singlyLinkedList, singlyLinkedList.size());
        System.out.println(singlyLinkedList.popFront());
        System.out.printf("singlyLinkedList %s\nsize %d\n", singlyLinkedList, singlyLinkedList.size());
        System.out.println(singlyLinkedList.popFront());
        System.out.printf("singlyLinkedList %s\nsize %d\n", singlyLinkedList, singlyLinkedList.size());

        assertIsEmpty(singlyLinkedList);
    }

    @Test
    void forEachLoopTest() {
        System.out.println("empty list");
        for (var number : new SinglyLinkedList<>()) {
            System.out.println(number);
        }

        System.out.println("[1]");
        for (var number : new SinglyLinkedList<>(1)) {
            System.out.println(number);
        }

        System.out.println("[1,2,3]");
        for (var number : new SinglyLinkedList<>(1, 2, 3)) {
            System.out.println(number);
        }
    }
}