#include <iostream>
#include <string>


//  Struct for evry node that has value (integer number) and pointer on next node
struct Node
{
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {

    // We always need to have one pointer on head for moving in linked list

    private:
        Node* head;
    
    public:

        // Constructor 
        LinkedList() : head(nullptr) {}

        // Custom destructor
        ~LinkedList() {
            deleteList();
        }

        // Add element in the end of linked list
        void addNode(int value) {
            Node* newNode = new Node(value);

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // Print liked list values
        void printList() const {
            Node* temp = head;
            while (temp != nullptr)
            {
                std::cout << temp->value << " -> ";
                temp = temp->next;
            }
            
        }

        // Method for linked list clearing in destructor
        void deleteList() {
            Node* temp = head;
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr;
        }
};


int main() {

    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    list.printList();

    return 0;
}
