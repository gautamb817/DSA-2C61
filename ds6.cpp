#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int data){
        value=data;
        next=nullptr;
        prev=nullptr;
    }
};
class DoublyLinkedList{
    Node* head;
    Node *tail;
    public:
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertatbegin(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            head=newnode;
            tail=newnode;
            head->next=tail;
            tail->next=head;
            head->prev=tail;
            tail->prev=head;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            head->prev=newnode;
            head=newnode;
            // head->prev=tail;
            tail->next=head;
        }
    }
    void insertatend(int n){
        Node* newnode= new Node(n);
        if(head==tail && head==nullptr){
            head=newnode;
            tail=newnode;
            head->next=tail;
            tail->next=head;
            head->prev=tail;
            tail->prev=head;
        }
        else{
            newnode->next=head;
            newnode->prev=tail;
            tail->next=newnode;
            head->prev=newnode;
            tail=newnode;
        }
    }
    void insertatspecefic(int n,int x){
        Node *newnode= new Node(n);
        Node * temp= head;
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        while(temp->next!=head && temp->value!=x){
            temp=temp->next;
        }
        if(temp->next==head){
            if(tail->value==x){
                insertatend(n);
            }
        }
        else{
            newnode->next=temp->next;
            newnode->prev=temp;
            newnode->next->prev=newnode;
            temp->next=newnode;

        }
    }
    void deletenode(int x){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        Node *temp=head;
        if(head->value==x){
            tail->next=head->next;
            head->next->prev=tail;
            head=head->next;
            delete temp;
        }
        else{
            while(temp->next!=head && temp->value!=x){
                temp=temp->next;
            }
            if(temp->next==head){
                if(tail->value==x){
                    Node *yo=tail;
                    tail->prev->next=head;
                    head->prev=tail->prev;
                    tail=tail->prev;
                    delete yo;
                }
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
            }

        }
    }
    int search(int x) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return -1;
    }

    int count = 1;
    Node* temp1 = head;
    Node* temp2 = tail;
    bool found = false;

    while (temp1 != temp2 && temp1->next != temp2) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
            break;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position ";
            found = true;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
        count++;
    }

    
    if (!found) {
        if (temp1->value == x) {
            cout << "It is found at " << count << " position \n";
            found = true;
        }
        else if (temp2->value == x) {
            cout << "It is found at " << -count << " position \n";
            found = true;
        }
    }

    if (!found)
        cout << "Not found\n";

    return found ? count : -1;
}

    void display(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=head){
                cout << temp->value << " => ";
                temp=temp->next;
            }
            cout << tail->value << endl ;
        }
    }
    void displayreverse(){
        if(head==tail && head==nullptr){
            cout << "empty \n";
            return;
        }
        else{
            Node* temp=tail;
            while(temp->prev!=tail){
                cout << temp->value << " => ";
                temp=temp->prev;
            }
            cout << head->value << endl ;
        }
    }
};
int main(){
    DoublyLinkedList d1;
    d1.insertatbegin(10);
    d1.insertatbegin(20);
    d1.insertatbegin(30);
    d1.insertatbegin(40);
    d1.insertatend(5);
    // d1.insertatbegin(10);
    d1.display();
    // d1.displayreverse();
    d1.insertatspecefic(35,30);
    d1.display();
    d1.deletenode(30);
    d1.display();
    d1.search(40);
    d1.search(20);
    // while (true){
    //     int n;
    // }
}