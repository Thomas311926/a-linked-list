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
    cout<<"1: add a node to the end of the array"<<endl;
    cout<<"2: print the value of a node"<<endl;
    cout<<"3: assign a number to a node(not implemented yet)"<<endl;
    //cout<<""<<endl;
    //init
    int op,val;
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
                break;
            case 2:
                cout<<"Please enter the index of the node:"<<endl;
                cin>>val;
                rp=head;
                for (int i=1; i<val; i++) {
                    rp=rp->next;
                }
                cout<<rp->data<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
