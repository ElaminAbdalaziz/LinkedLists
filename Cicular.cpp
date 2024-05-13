#include <iostream>
using namespace std;
//Circular Linked List
template <typename type>
class circularLinkedList{
    struct node{
        type item;
        node * next;
    };

    node * head;
    node * tail;
    int length;

public:

    circularLinkedList(){
        head = tail = NULL;
        length = 0;
    }

    bool isEmpty(){
        return length == 0;
    }

    void insertAtHead(type element){
        node * newNode = new node;
        newNode -> item = element;
        if (length == 0)
        {
            head = tail = newNode;
            newNode -> next = newNode;
        }

        else{
            newNode -> next = head;
            head = newNode;
            tail -> next = head;
        }
        length++;
    }

    void insertAtTail(type element){
        node * newNode = new node;
        newNode -> item = element;

        if (length == 0)
        {head = tail = newNode; newNode -> next = newNode;}

        else{tail -> next = newNode; newNode -> next = head; tail = newNode;}
        length++;
    }

    void insertAt(type element, int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range" << endl;
        node * newNode = new node;
        newNode -> item = element;

        if(pos == 0)
            insertAtHead(element);

        else if(pos == length)
            insertAtTail(element);

        else{
            node * cur = head;
            for (int i = 1; i < pos; i++) {
                cur = cur -> next;
            }
            newNode -> next = cur -> next;
            cur -> next = newNode;
            length++;
        }
    }

    void removeAtHead(){
        if (length == 0)
            cout << "Empty list can't be removed";

        else if (length == 1){
            delete head;
            tail = head = NULL;
            length --;
        }

        else{
            node * cur = head;
            head = head -> next;
            delete cur;
            tail -> next = head;
            length --;
        }
    }

    void removeAtTail(){
        if (length == 0)
            cout << "Empty list can't be removed";

        else if (length == 1){
            delete head;
            tail = head = NULL;
            length --;
        }

        else{
            node * cur = head -> next;
            node * prev = head;

            while (cur != tail){
                prev = cur;
                cur = cur -> next;
            }

            delete cur;
            prev -> next = head;
            tail = prev;
            length --;
        }
    }

    void removeAt(int index){
        if (index < 0 || index > length) {
            cout << "Invalid index";
        }
        node * temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
            tail -> next = head;
        }
        else {
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            node * nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            if(index == length -1)
                tail = temp;
        }
        length--;
    }

    type retrieveAt(int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range";

        node * cur = head;
        for (int i = 0; i < pos; i++) {
            cur = cur -> next;
        }
        return cur -> item;
    }

    type replaceAt(type element, int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range";

        node * cur = head;
        for (int i = 0; i < pos; i++) {
            cur = cur -> next;
        }
        cur -> item = element;
    }

    bool isExist(type element){
        if (head == NULL)
            return false;

        node * cur = head;
        do{
            if (cur -> item == element)
                return true;

            cur = cur -> next;
        }while(cur != head);

        return false;
    }

    bool isItemAtEqual(type element, int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range";

        node * cur = head;
        for (int i = 0; i == pos; i++) {
            if (cur -> item == element)
                return true;
            cur = cur -> next;
        }
        return false;

    }

    void swap(int first, int sec) {
        if (first == sec)
            return;

        node *cur1 = head, *prev1 = nullptr, *cur2 = head, *prev2 = nullptr;

        if (head == NULL || head->next == head) {
            cout << "Empty list or list has only one node.";
            return;
        }

        if (first < 0 || first >= length || sec < 0 || sec >= length) {
            cout << "Out of range";
            return;
        }

        int i=0;
        do {
            prev1 = cur1;
            cur1 = cur1->next;
            i++;
        } while (i < first && cur1->next != head);

        int j = 0;
        do {
            prev2 = cur2;
            cur2 = cur2->next;
            j++;
        } while (j < sec && cur2->next != head);

        if (i != first || j != sec) {
            cout << "One or both elements not found in the list." << endl;
            return;
        }

        // If first node is not head of linked list
        if (prev1 != nullptr)
            prev1->next = cur2;
        else // make y the new head
            head = cur2;

        // If second node is not head of linked list
        if (prev2 != nullptr)
            prev2->next = cur1;
        else // make x the new head
            head = cur1;

        // Swap next pointers
        node* temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;
    }


    int linkedListSize(){
        node * cur = head;
        int i = 0;

        do {
            i++;
            cur = cur -> next;
        } while (cur != head);

        return i;
    }

    void clear(){
        node * temp = head;
        while (temp != NULL) {
            node * next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    void print(){
        node * cur = head;
        do{
            cout << cur -> item << " ";
            cur = cur -> next;
        }while (cur != head && cur != NULL);
        cout << endl;
    }
};
int main() {
    circularLinkedList <int> c;
    c.insertAtHead(10);
    c.insertAtTail(20);
    c.insertAt(30,1);
    c.insertAtTail(40);
    c.print();
    c.swap(0,1);
    c.print();


    return 0;
}
