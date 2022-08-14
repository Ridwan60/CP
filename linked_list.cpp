#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
};

node *root = NULL;

void append(int val){
    if(root == NULL){
        root = new node();
        root -> val = val;
        root -> next = NULL;
    }
    else{
        node *current_node = root;

        while(current_node -> next != NULL){
            current_node = current_node-> next ;
        }

        node *newNode = new node();
        newNode -> val = val;
        newNode -> next = NULL;
        current_node -> next = newNode;
    }
}





void del(int n){
    node *currentNode = root;
    if(currentNode->val == n){
        root = root -> next;
        return ;
    }
    while(currentNode->next != NULL){
            if(currentNode->next->val==n){
                currentNode->next=currentNode->next->next;
            }
            else{
                currentNode=currentNode->next;
            }
   }
}


//printing LinkList
void print(){
    node *current_node = root;

    while(current_node != NULL){
        cout << current_node -> val << ' ';
        current_node = current_node -> next;
    }
}


int main(){
    append(1);
    append(2);
    append(3);
    append(4);
    print();
    cout << endl;
    del(2);
    print();
    cout << endl;
}
