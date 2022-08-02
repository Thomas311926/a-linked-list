#include <iostream>
using namespace std;
struct node{
    int data=0;
    int nodeIndex;
    node *prior;
    node *next;
};
int main() {
    cout<<"Welcome to this array, the following operations are available:"<<endl;
    cout<<"1: Add a node to the end of the array"<<endl;
    cout<<"2: Print the value of a node"<<endl;
    cout<<"3: Assign a number to a node"<<endl;
    cout<<"4: Insert a node into the array (not implemented yet)"<<endl;
    cout<<"5: Delete a node from the array (not implemented yet)"<<endl;
    cout<<"6: Exit"<<endl;
    //init
    int op,val,val2;
    node *head=new node;
    node *p=head,*rp=nullptr;
    node *q=nullptr;
    p->prior=nullptr;
    p->next=nullptr;
    p->nodeIndex=1;
    int arrcap=1;
    while (true) {
        if(arrcap==1){
            cout<<"Currently the array contains "<<arrcap<<" node."<<endl<<"What do you want to do?"<<endl;
        }else{
            cout<<"Currently the array contains "<<arrcap<<" nodes."<<endl<<"What do you want to do?"<<endl;
        }
        cin>>op;
        switch (op) {
            case 1:
                cout<<"Please enter the value that wil be stored this node:"<<endl;
                cin>>val;
                q=new node;
                p->next=q;
                q->prior=p;
                q->next=nullptr;
                q->nodeIndex=++arrcap;
                q->data=val;
                p=q;
                q=nullptr;
                cout<<"Operation successful."<<endl;
                break;
            case 2:
                cout<<"Please enter the index of the node:"<<endl;
                cin>>val;
                if (val>arrcap) {
                    cout<<"That node does not exist!"<<endl;
                }else{
                    rp=head;
                    for (int i=1; i<val; i++) {
                        rp=rp->next;
                    }
                    cout<<"The value of that node is "<<rp->data<<"."<<endl;
                    rp=head;
                }
                break;
            case 3:
                cout<<"Please enter the index of the node that you would like to assign to:"<<endl;
                cin>>val;
                cout<<"Pleas enter the value that you would like to assign to that node:"<<endl;
                cin>>val2;
                if (val>arrcap) {
                    cout<<"That node does not exist!"<<endl;
                }else{
                    rp=head;
                    for (int i=1; i<val; i++) {
                        rp=rp->next;
                    }
                    cout<<"The value of node "<<val<<" was changed from "<<rp->data<<" to ";
                    rp->data=val2;
                    cout<<rp->data<<"."<<endl;
                    rp=head;
                }
                break;
            case 6:
                return 0;
                break;
            default:
                cout<<"Invalid operation!"<<endl;
                break;
        }
    }
    return 0;
}
