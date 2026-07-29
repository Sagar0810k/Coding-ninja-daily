/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.

     if(head==nullptr||head->next==nullptr||k==0) return head;
     int n=1;
     Node *tail=head;
     while(tail->next !=nullptr){
          tail=tail->next;
          n++;
     }
     k=k%n;
     if(k==0) return head;
     tail->next=head;
     int steps=n-k;
     Node *newtail=head;

     for(int i=1;i<steps;i++){
          newtail=newtail->next;
     }
     Node *newhead=newtail->next;
     newtail->next=nullptr;
     return newhead;
}