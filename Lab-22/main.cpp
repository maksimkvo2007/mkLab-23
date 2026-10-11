#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { 
        head = nullptr; 
        tail = nullptr; 
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
            
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
            
        temp->next = newNode;
    }

    void pop_front(){
        if (!head) return; //checking if list is empty

        Node* temp = head; 
        head = head->next; 
        
        if (head) {
            head->prev = nullptr; 
        } else {
            tail = nullptr; 
        }
        delete temp; 
    }
    
    void pop_back() {
        if (!tail) return; 
        
        Node* temp = tail;
        tail = tail->prev;
        
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        delete temp; 
    }

    void delete_pos(int pos) {
        if (!head || pos < 1) return; 

        if (pos == 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        int currentPos = 1;

        while (temp && currentPos < pos) {
            temp = temp->next;
            currentPos++;
        }
        if (!temp) {
            cout << "Position " << pos << " is out of bounds.\n";
            return;
        }

        if (!temp->next) { 
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

    }

    void delete_val(int value) {
        if (!head) return; // Empty list
        
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
            
        if (!temp) return; // Value not found
        
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }
        
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }
        
        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    
    // Seed the random number generator (optional but recommended if using rand)
    srand(time(0)); 
    
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
    
    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
        
    cout << "List forward: ";
    list.print();
    
    cout << "List backward: ";
    list.print_reverse();
    
    cout << "Deleting list, then trying to print.\n";
    // Explicitly calling the destructor is generally bad practice in C++, 
    // but preserving it here as it was in the original demo code.
    list.~DoublyLinkedList(); 
    
    cout << "List forward: ";
    list.print();
    
    return 0;
}