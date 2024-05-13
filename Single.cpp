#include <iostream>
using namespace std;

//Single Linked List
template<typename type>
class LinkedList{
    struct node{
        type item;
        node * next;
    };

    node * head;
    node * tail;
    int length;

    public:

    LinkedList(){
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
        {head = tail = newNode; newNode -> next = NULL;}
        else{newNode -> next = head; head = newNode;}
        length++;
    }

    void insertAtTail(type element){
        node * newNode = new node;
        newNode -> item = element;

        if (length == 0)
        {head = tail = newNode; newNode -> next = NULL;}

        else{tail -> next = newNode; newNode -> next = NULL; tail = newNode;}
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
            cur -> next =newNode;
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
            prev -> next = NULL;
            tail = prev;
            length --;
        }
    }

    void removeAt(int pos){
        if (pos < 0 || pos > length)
            cout << "Out of range";
        node * temp = head;
        if (pos == 0) {
            head = head->next;
            delete temp;
        }
        else {
            for (int i = 0; i < pos - 1; ++i) {
                temp = temp->next;
            }
            node * nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
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
        node* temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;
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
    LinkedList <int> l;
    l.insertAtHead(10);
    l.insertAtTail(20);
    l.insertAt(30,1);
    l.print();
    cout << l.isItemAtEqual(5,0);
    cout << endl;
    cout << l.linkedListSize();
    cout << endl;
    l.swap(1,2);
    l.print();

return 0;
}