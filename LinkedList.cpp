#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class Linkedlist{
public:
    Node* Head;
    Node* Tail;
    int size;

    Linkedlist(){
        this->Head = NULL;
        this->Tail = NULL;
        this->size = 0;
    }
    void InsertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0) Head=Tail=temp;
        else {
            Tail->next = temp;
            Tail = temp;
        }
        size++;
    }
    void InsertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) Head=Tail=temp;
        else {
            temp->next = Head;
            Head = temp;
        }
        size++;
    }
    void InsertAtIndex(int val,int idx){
        if(size==0) InsertAtHead(val);
        else if(idx==size) InsertAtTail(val);
        else if(idx<0 || idx>=size) cout<<("Invalid idx");
        else {
            Node* t = new Node(val);
        Node* temp = Head;
        for(int i=1;i<=idx-1;i++){
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
        size++;
        }
    }
    void GetAtIdx(int idx){
        if(idx<0 || idx>=size) cout<<"Invalid idx";
        else if(idx==0) cout<<Head->val<<endl;
        else if(idx==size-1) cout<<Tail->val<<endl;
        else{
        Node* temp = Head;
        for(int i=1;i<=idx;i++){
            temp = temp->next;
        }
        cout<<temp->val<<endl;
      }
    }
    void DeleteAtHead(){
        if(size==0) cout<<"List is Empty"<<endl;
        else {
            Head = Head->next;
            size--;
        }
    }
    void DeleteAtTail(){
        if(size==0) cout<<"List is empty"<<endl;
        else {
            Node* temp = Head;
            while(temp->next != Tail){
                temp = temp->next;
            }
            temp->next = NULL;
            Tail = temp;
            size--;
        }
    }
    void DeleteAtIdx(int idx){
        if(idx<0 || idx>=size) cout<<"Invalid idx"<<endl;
        else if(size==0) DeleteAtHead();
        else if(idx==size-1) DeleteAtTail();
        else {
            Node* temp = Head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void display(){
        Node* temp = Head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Linkedlist ll;
    //Insert at tail
    ll.InsertAtTail(10);
    ll.display();
    ll.InsertAtTail(20);
    ll.display();
    ll.InsertAtTail(30);
    ll.display();
    ll.InsertAtTail(40);
    ll.display();
    ll.InsertAtTail(50);
    ll.display();
    ll.InsertAtTail(60);
    ll.display();

    //Insert at Head
    ll.InsertAtHead(5);
    ll.display();
    ll.InsertAtHead(15);
    ll.display();

    //InsertAt index
    ll.InsertAtIndex(45,4);
    ll.display();

    //getAtIdx
    // ll.GetAtIdx(4);

    //DeleteAtHead
    ll.DeleteAtHead();
    ll.display();

    //DeleteAtTail
    ll.DeleteAtTail();
    ll.display();

    //DeleteAtidx
    ll.DeleteAtIdx(3);
    ll.display();
}