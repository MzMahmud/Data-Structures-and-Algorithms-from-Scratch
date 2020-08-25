#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *insert_in_head(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

node *insert_head_accending(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    node *prev = NULL;
    node *curr = head;
    while (curr && new_node->data > curr->data) {
        prev = curr;
        curr = curr->next;
    }
    if (prev)
        prev->next = new_node;
    new_node->next = curr;

    return prev ? head : new_node;
}

node *remove_head(node *head) {
    if (!head)
        return head;

    node *new_head = head->next;
    free(head);
    return new_head;
}

node *get_mid_prev(node *head) {
    node *slow, *fast, *mid_prev;
    slow = fast = head;
    while (fast && fast->next) {
        mid_prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return mid_prev;
}

node *marged_accending(node *h1, node *h2) {
    node dummy_head;
    dummy_head.next = NULL;
    node *marged_curr = &dummy_head;

    while (h1 && h2) {
        node *to_add = NULL;
        if (h1->data < h2->data) {
            to_add = h1;
            h1 = h1->next;
        } else {
            to_add = h2;
            h2 = h2->next;
        }
        marged_curr->next = to_add;
        marged_curr = marged_curr->next;
    }
    marged_curr->next = h1 ? h1 : h2;
    return dummy_head.next;
}

node *marge_sort(node *head) {
    // Base Case: null list or single element list
    if (!head || !head->next)
        return head;

    node *mid_prev = get_mid_prev(head);

    // right - mid_prev->next  ..... NULL
    node *sorted_right = marge_sort(mid_prev->next);

    // left  - head ..... mid_prev
    mid_prev->next = NULL;
    node *sorted_left = marge_sort(head);

    return marged_accending(sorted_left, sorted_right);
}

void free_list(node *head) {
    node *prev = NULL;
    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

void print_list(node *head) {
    while (head) {
        printf("(%d) -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char *args[]) {
    // node *head1 = NULL;
    // node *head2 = NULL;

    // head1 = insert_in_head(head1, 8);
    // head2 = insert_in_head(head2, 7);
    // head1 = insert_in_head(head1, 6);
    // head2 = insert_in_head(head2, 5);
    // head1 = insert_in_head(head1, 4);
    // head2 = insert_in_head(head2, 3);
    // head1 = insert_in_head(head1, 2);
    // head2 = insert_in_head(head2, 1);

    // head = insert_head_accending(head, 1);
    // head = insert_head_accending(head, -2);
    // head = insert_head_accending(head, 13);
    // head = remove_head(head);
    // head = insert_head_accending(head, -4);
    // head = insert_head_accending(head, 3);

    // print_list(head1);
    // print_list(head2);

    // node *marged = marge_accending(head1, head2);
    // print_list(marged);

    // node *mid = find_mid(head);
    // if (mid)
    //     printf("\nmid = (%d)\n", mid->data);

    // free_list(head1);
    // free_list(head2);

    const int SIZE = 50;
    const int MAX = 20;

    node *head = NULL;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        int val = rand() % MAX + 1;
        head = insert_in_head(head, val);
    }
    printf("Unsorted:\n");
    print_list(head);

    head = marge_sort(head);
    printf("Sorted:\n");

    head = remove_head(head);
    head = remove_head(head);
    head = remove_head(head);

    print_list(head);

    free_list(head);

    return 0;
}