/*
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
using namespace std;
struct node{
    int data=0;
    node *prior;
    node *next;
};
int main() {
    cout<<"Welcome to this linked list, the following operations are available:"<<endl;
    cout<<"1: Add a node to the end of the linked list"<<endl;
    cout<<"2: Print the value of a node"<<endl;
    cout<<"3: Assign a number to a node"<<endl;
    cout<<"4: Insert a node into the linked list"<<endl;
    cout<<"5: Delete a node from the linked list"<<endl;
    cout<<"6: Print out the all the nodes linked list (not implemented yet)"<<endl;
    cout<<"7: Exit"<<endl;
    cout<<"8: Help"<<endl;
    //init
    int op,val,val2;
    node *head=new node;
    node *p=head,*rp=nullptr,*insn=nullptr;//p is the location of the end of the linked list, rp is used to get the address of a specific node
    node *q=nullptr;//q is used to allocate space
    p->prior=nullptr;
    p->next=nullptr;
    int arrcap=1;//the number of nodes in the linked list
    while (true) {
        if(arrcap==1){
            cout<<"Currently the linked list contains "<<arrcap<<" node."<<endl<<"What do you want to do? (type 8 for help)"<<endl;
        }else{
            cout<<"Currently the linked list contains "<<arrcap<<" nodes."<<endl<<"What do you want to do? (type 8 for help)"<<endl;
        }
        cin>>op;
        switch (op) {
            case 1:
                cout<<"Please enter the value that wil be stored this node:"<<endl;
                cin>>val;
                q=new node;//request space
                p->next=q;
                q->prior=p;
                q->next=nullptr;
                arrcap++;
                q->data=val;
                p=q;//update end location
                q=nullptr;
                cout<<"A node with the index "<<arrcap<<" has been added to the end of the linked list."<<endl;
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
                    cout<<"The value of node "<<val<<" has been changed from "<<rp->data<<" to ";
                    rp->data=val2;
                    cout<<rp->data<<"."<<endl;
                    rp=head;
                }
                break;
            case 4:
                cout<<"Please enter the index of the node that will be to the left of the new node (for example, if you want to insert a new node between nodes 3 and 4, enter 3):"<<endl;
                cin>>val;
                if (val>arrcap) {
                    cout<<"That node does not exist!"<<endl;
                }else{
                    rp=head;
                    for (int i=1; i<=val; i++) {
                        rp=rp->next;
                    }
                    cout<<"Please enter the value that will be stroed in this new node:"<<endl;
                    cin>>val2;
                    if (val==arrcap) {
                        q=new node;//request space
                        p->next=q;
                        q->prior=p;
                        q->next=nullptr;
                        arrcap++;
                        q->data=val2;
                        p=q;//update end location
                        q=nullptr;
                        rp=head;
                        cout<<"A node with the index "<<arrcap<<" has been added to the end of the linked list."<<endl;
                    }else if (val==1){
                        insn=new node;
                        insn->data=val2;
                        insn->prior=nullptr;
                        insn->next=rp;
                        rp->prior=insn;
                        arrcap++;
                        cout<<"Successfully inserted a new node between node at the start of the linked list"<<endl;
                        rp=head;
                    }
                    insn=new node;
                    insn->data=val2;
                    insn->prior=rp->prior;
                    rp->prior->next=insn;
                    insn->next=rp;
                    rp->prior=insn;
                    arrcap++;
                    cout<<"Successfully inserted a new node between node "<<val<<" and node "<<val+1<<"."<<endl;
                    rp=head;
                }
                
                break;
            case 5:
                cout<<"Please enter the index of the node that will be deleted:"<<endl;
                cin>>val;
                if (val>arrcap) {
                    cout<<"That node does not exist!"<<endl;
                }else{
                    rp=head;
                    for (int i=1; i<val; i++) {
                        rp=rp->next;
                    }
                    if (val==1&&arrcap==1) {//Prevent EXC_BAD_ACCESS
                        cout<<"Error: That node is the only node in the linked list and can't be deleted!"<<endl;//EXC_BAD_ACCESS will occur at operation one if this is deleted
                    }else if (val==1) {
                        rp->next->prior=nullptr;
                        head=rp->next;//move head location
                        delete rp;
                        arrcap--;
                        cout<<"Successfully deleted that node."<<endl;
                    }else if (val==arrcap){
                        rp->prior->next=nullptr;
                        p=rp->prior;//move end location
                        delete rp;
                        arrcap--;
                        cout<<"Successfully deleted that node."<<endl;
                    }else{
                        rp->prior->next=rp->next;
                        rp->next->prior=rp->prior;
                        delete rp;
                        arrcap--;
                        cout<<"Successfully deleted that node."<<endl;
                    }
                    rp=head;
                }
                break;
            case 6:
                cout<<"Operation not implemented!(yet)"<<endl;
                break;
            case 7:
                return 0;
                break;
            case 8:
                cout<<"The following operations are available:"<<endl;
                cout<<"1: Add a node to the end of the linked list"<<endl;
                cout<<"2: Print the value of a node"<<endl;
                cout<<"3: Assign a number to a node"<<endl;
                cout<<"4: Insert a node into the linked list"<<endl;
                cout<<"5: Delete a node from the linked list"<<endl;
                cout<<"6: Print out the all the nodes linked list (not implemented yet)"<<endl;
                cout<<"7: Exit"<<endl;
                cout<<"8: Help"<<endl;
                break;
            default:
                cout<<"Invalid operation!"<<endl;
                break;
        }
    }
    return 0;
}
