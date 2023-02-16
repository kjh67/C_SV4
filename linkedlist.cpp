#include <iostream>

struct Node {
    int head;
    Node* tail;

    public:
        Node(int n): head(n), tail(nullptr) {}
};


class LinkList {
    Node* head;

    public:
        LinkList(int[], int);
        LinkList(): head(nullptr) {};
        LinkList(const LinkList&);
        LinkList& operator=(const LinkList&);

        int pop(void);
};

// Constructor taking array and array size
LinkList::LinkList(int arr[], int s) {
    // start construction from the back
    Node* back = nullptr;
    for (int i=s-1; i>=0; i--) {
        Node* current = new Node(arr[i]);
        current->tail = back;
        back = current;
    }
    head = back;
}

// copy CONSTRUCTOR: populate new object using the one passed
LinkList::LinkList(const LinkList& list) {
    head = new Node(list.head->head);
    Node* current_node = head; // target
    Node* to_copy = list.head->tail;
    // keep constructing fresh nodes
    // we want a deep copy
    while (to_copy != nullptr) {
        // keep copying the nodes
        current_node->tail = new Node(to_copy->head);
        current_node = current_node->tail;
        to_copy = to_copy->tail;
    }
}

// assignment operator
LinkList& LinkList::operator=(const LinkList& list) {
    // we want to tidy up the object being overwritten,
    // then make a deep copy
    if (head != nullptr) {
        Node* to_clean_up = head->tail;
        while (to_clean_up != nullptr) {
            Node* next = to_clean_up->tail;
            delete to_clean_up;
            to_clean_up = next;
        }
    }
    // copied from the copy constructor
    head = new Node(list.head->head);
    Node* current_node = head; // target
    Node* to_copy = list.head->tail;
    // keep constructing fresh nodes
    // we want a deep copy
    while (to_copy != nullptr) {
        // keep copying the nodes
        current_node->tail = new Node(to_copy->head);
        current_node = current_node->tail;
        to_copy = to_copy->tail;
    }
    return *this;
}

// poppin'
int LinkList::pop(void) {
    if (head != nullptr) {
        // at least one node still exists
        Node* to_delete = head;
        int to_return = head->head;
        head = head->tail;
        delete to_delete;
        return to_return;
    }
    else {
        return -1;
    }
}


int main() {
    int test[] = {1,2,3,4,5};
    LinkList l1(test+1, 4), l2(test, 5);
    LinkList l3=l2, l4;
    l4=l1;
    printf("%d %d %d\n", l1.pop(), l3.pop(), l4.pop());
    return 0;
}