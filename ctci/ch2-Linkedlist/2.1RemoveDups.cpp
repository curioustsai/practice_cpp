/*
 * Cracking the coding interview edition 6
 * Problem 2-1 : Remove duplicates from an unsorted linked list.
 * Approach 1 : Naive approach of iterating and remove all further duplicates of
 * current node. Space complexity O(1) & time complexity O(n^2)
 * Approach 2: Use a hash table, space complexity O(n), time complexity O(n)
 */

#include <iostream>
#include <unordered_map>

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() = default;
    ~LinkedList() = default;
    LinkedList(Node* node) : head(node) {}
    Node* GetHeadNode() { return head; }

    void append(int data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }

        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new Node(data);
    };

    void printNodes() {
        if (head == nullptr) return;

        Node* ptr = head;
        while (ptr != nullptr) {
            std::cout << ptr->data << " --> ";
            ptr = ptr->next;
        }
        std::cout << "end" << std::endl;
    };

    // Method 1
    // space complexity O(1)
    // time complexity O(n^2)
    /**
     * [removeDuplicates Remove duplicates without using extra space]
     * @param head [head of list]
     */
    void removeDuplicates() {
        Node* curr = head;
        while (curr) {
            Node* runner = curr;
            while (runner->next != nullptr) {
                if (runner->next->data == curr->data) {
                    Node* t = runner->next;
                    runner->next = runner->next->next;
                    delete t;
                } else {
                    runner = runner->next;
                }
            }
            curr = curr->next;
        }
    };

    // Method 2
    // space complexity - O(n)
    // time complexity - O(n)
    /**
     * [removeDuplicates1 - Remove duplicates from the list using hash table]
     * @param head [head of list]
     */
    void removeDuplicatesHash() {
        std::unordered_map<int, int> map;
        Node* curr = head;
        map[curr->data] = 1;
        while (curr->next != nullptr) {
            if (map.find(curr->next->data) != map.end()) {
                Node* t = curr->next;
                curr->next = curr->next->next;
                delete t;
            } else {
                map[curr->next->data] = 1;
                curr = curr->next;
            }
        }
    }

    Node* kthLastNode(int k) {
        Node *p, *q;
        p = head;
        q = head;

        int count = 0;
        while (count < k) {
            // end of linkedlist
            if (q->next == nullptr) {
                std::cerr << "over large k" << std::endl;
                return nullptr;
            }
            q = q->next;
            count++;
        }

        while (q != nullptr) {
            q = q->next;
            p = p->next;
        }

        std::cout << p->data << std::endl;

        return p;
    }

    void deleteMiddleNode(int value) {
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->data == value) {
                Node* t = curr->next;
                curr->next = curr->next->next;
                delete t;
            } else {
                curr = curr->next;
            }
        }
    }

    void deleteList() {
        Node* node = head;
        while (node) {
            Node* nextNode = node->next;
            delete node;
            node = nextNode;
        }
        head = nullptr;
    }

    /**
     *  Cracking the coding interview edition 6
     *  Problem 2.4 Partition:
     *  Write code to partition linked list around a value x, such that
     *  nodes less than x come before all the nodes greater than or equal to x.
     *  If x is in the list, the values of x only need to be after the elements
     * less than x. Example 3-->5-->8-->5-->10-->2-->1 (x = 5)
     *  3-->1-->2-->10-->5-->5-->8
     *
     *  Approach:
     *  Start with first node, and add every thing bigger or equal to x at tail
     *  and smaller values at head.
     */

    Node* PartitionInsert(Node* listHead, int value) {
        if (listHead == nullptr) return nullptr;
        Node *headInitial = nullptr, *tailInitial = nullptr;
        Node *head = nullptr, *tail = nullptr;
        Node* curr = listHead;

        while (curr != nullptr) {
            if (curr->data < value) {
                if (head == nullptr) {
                    headInitial = head = curr;
                } else {
                    head->next = curr;
                    head = curr;
                }
            } else {
                if (tail == nullptr) {
                    tailInitial = tail = curr;
                } else {
                    tail->next = curr;
                    tail = curr;
                }
            }
            curr = curr->next;
        }

        head->next = tailInitial;
        tail->next = nullptr;

        return headInitial;
    }

private:
    Node* head = nullptr;
};

int main() {
    LinkedList ll;

    ll.append(5);
    ll.append(4);
    ll.append(4);
    ll.append(4);
    ll.append(4);
    ll.append(3);
    ll.append(4);
    ll.append(4);
    ll.append(2);
    ll.append(4);
    ll.append(4);
    ll.append(1);

    ll.printNodes();
    // ll.removeDuplicates();
    ll.removeDuplicatesHash();
    ll.printNodes();

    ll.kthLastNode(4);
    ll.deleteList();

    LinkedList list;
    // Example 3-->5-->8-->5-->10-->2-->1 (x = 5)
    list.append(3);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(10);
    list.append(2);
    list.append(1);

    list.printNodes();
    Node* partition = ll.PartitionInsert(list.GetHeadNode(), 5);
    LinkedList newList(partition);
    newList.printNodes();

    return 0;
}
