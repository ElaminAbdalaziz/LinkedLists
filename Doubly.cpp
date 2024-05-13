#include <iostream>
using namespace std;

//Doubly Linked List
template<typename type>
class duoblyLinkedList{
    struct node{
        type item;
        node * next;
        node * prev;
    };

    node * head;
    node * tail;
    int length;

public:

    duoblyLinkedList(){
        head = NULL;
        tail = NULL;
        length = 0;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void insertAtHead(type element){
        node * newNode = new node;
        newNode -> item = element;
        if (length == 0)
        {head = tail = newNode; newNode -> next = newNode -> prev = NULL;}
        else{
            newNode -> next = head;
            newNode -> prev = NULL;
            head -> prev = newNode;
            head = newNode;
        }
        length++;
    }

    void insertAtTail(type element){
        node * newNode = new node;
        newNode -> item = element;

        if (length == 0)
        {head = tail = newNode; newNode -> next = newNode -> prev = NULL;}

        else{
            newNode -> next = NULL;
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
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
            newNode -> prev = cur;
            cur -> next -> prev = newNode;
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
            head -> prev = NULL;
            delete cur;
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
            node * cur = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            delete cur;
            length --;
        }
    }

    void removeAt(int index){
        if (index < 0 || index > length) {
            cout << "Empty list can't be removed";
            return;
        }

        node * temp = head;

        if (index == 0) {
            head = head -> next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
        } else {
            for (int i = 0; temp != NULL && i < index; i++) {
                temp = temp->next;
            }
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
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
        node * cur = head;
        while (cur != nullptr) {
            if (cur -> item == element)
                return true;
            cur = cur -> next;
        }
        return false;
    }

    bool isItemAtEqual(type element, int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range";

        node * cur = head;
        for (int i = 0; i == pos; i++) {
            if (cur -> item == element )
                return true;
            cur = cur ->next;
        }
        return false;
    }

    void swap(int first, int sec) {
        if (first == sec)
            return;

        node *cur1 = head, *prev1 = nullptr, *cur2 = head, *prev2 = nullptr;

        if (head == nullptr || head->next == nullptr) {
            cout << "Empty list or list has only one node.";
            return;
        }

        int i = 0;
        while (cur1 != nullptr && i < first) {
            prev1 = cur1;
            cur1 = cur1->next;
            i++;
        }

        int j = 0;
        while (cur2 != nullptr && j < sec) {
            prev2 = cur2;
            cur2 = cur2->next;
            j++;
        }

        if (i != first || j != sec || cur1 == nullptr || cur2 == nullptr) {
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
        if (cur1->next != nullptr)
            cur1->next->prev = cur2;

        if (cur2->next != nullptr)
            cur2->next->prev = cur1;

        node* temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;

        temp = cur2->prev;
        cur2->prev = cur1->prev;
        cur1->prev = temp;
    }


    int linkedListSize(){
        node * cur = head;
        int i;
        for (i = 0; cur != NULL ; i++) {
            cur = cur -> next;
        }
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
        while (cur != NULL){
            cout << cur -> item << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
};
int main() {
    duoblyLinkedList<int> d;
    d.insertAtHead(10);
    d.insertAtTail(10);
    d.insertAt(5,0);
    d.print();
    cout << d.isItemAtEqual(5,0);
    cout << endl;
    cout << d.linkedListSize();
    cout << endl;
    d.swap(1,2);
    d.print();
    d.clear();
    d.print();
    return 0;
}
