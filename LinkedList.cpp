#pragma once
#include<iostream>

using namespace std;

//General Linked List Implementation
class linkedlist
{
    int data;
    linkedlist *head;
    linkedlist *next;

    public:
    linkedlist()
    {
        head = NULL;
        next = NULL;
    }

    int getcount()
    {
        linkedlist *p = head;
        int c = 0;

        while(p!=NULL)
        {
            ++c;
            p=p->next;
        }
        return c;
    }

    void search(int n);
    void display();

    void append();

    void insertafter(int n);
    void delnode(int n);

}A;

void linkedlist::search(int n)
{
        
        linkedlist *p = head;
        int f = 0, c=0;

        while(p != NULL)
            {
                ++c;
                if(p->data == n)
                {
                    f=1;
                    cout<<n<<" FOUND at: "<<c<<" position\n";
                    break;
                }
                
                p = p->next;
            }

            if(!f)
                cout<<"NOT FOUND!\n";

}

 void linkedlist::display()
    {
        if(head == NULL)
            cout<<"List is empty!";

        else
        {
            linkedlist *p ;
            p = head;
            while(p != NULL)
            {
                cout<<p->data<<"\t";
                p = p->next;
            }
            delete p;
        }

        cout<<endl;
        
    }

void linkedlist::append()
    {
        if(head == NULL)
        {
            linkedlist *t = new linkedlist;
            cout<<"Enter new data for linked list: "; cin>>t->data;
            t->next = NULL;

            head = t;
            
            //deleting node
            t = NULL;
            delete t;
        }
        else
        {
            linkedlist *t = new linkedlist, *p;
            cout<<"Enter new data for linked list: "; cin>>t->data;
            t->next = NULL;

            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }

            p->next = t;

            //deleting node
            t=NULL;
            delete t;            
        }
    }

void linkedlist::insertafter(int n)
    {
        if(head == NULL)
        {
            cout<<"linked list is empty!,\n appending;\n";
            append();

        }
        
        else
        {
            linkedlist *p = head, *t;
            int f = 0;
            while(p != NULL)
            {
                if(p->data == n)
                {
                    t = new linkedlist;
                    cout<<"Enter new data for linked list: "; cin>>t->data;
                    t->next = p->next;
                    p->next = t;
                    f = 1;

                    
                    break;
                }

                p = p->next;

            }

            if(!f)
                cout<<"element not found!! ";cout<<"RETRY"<<endl;

            p = NULL;
            t = NULL;
            delete p,t; 
        }
    }

void linkedlist::delnode(int n)
{
    linkedlist *p = head;

    if(head == NULL)
    {
        cout<<"LL already EMPTY!!\n";
        p = NULL;
        delete p;

    }
    
    else if(head->data == n)
    {
        cout<<n<<" is deleted!\n";
        head = p->next;
        delete p;
    }

    else
    {
        linkedlist *t = head;
        p = p->next;
        int f = 0;

        while(p != NULL)
        {
            if(p->data == n)
            {
                cout<<n<<" is deleted!\n";
                f = 1;
                t->next = p->next;

                delete p;
                t = NULL;
                delete t;

                break;
            }

            p = p->next;
            t = t->next;
        }

        if(f == 0)
            cout<<"Element not found!\n";    
    }
}

//Stack Implementation !!
//Separate Stack class
class Slistnode
{
    int data;
    Slistnode* next;

    public:
    Slistnode()
    {
        data = 0;
        next = NULL;
    }
    void disp()
    {
        if(next == NULL)
            cout<<"stack is EMPTY!!\n";

        else
        {
            cout<<"Stack elements are:\n";
            Slistnode *p = next;
            while(p != NULL)
            {
                cout<<p->data<<" ";
                p = p->next;
            }
        }
        cout<<endl;
    }

    void pushNode(int num)
    {
        Slistnode *newnode = new Slistnode;
        newnode->data = num;

        newnode->next = next;
        next = newnode;

        cout<<newnode->data<<" is inserted!\n";
    }

    void popNode()
    {
        if(next == NULL)
            cout<<"Stack is already empty!\n";

        else
        {
            Slistnode *p = next;
            next = p->next;

            cout<<"DELETED DATA: "<<p->data<<endl;
            delete p;
        }        
    }    
}L;

//Queue Implementation
//separate queue class
class QlistNode
{
    int data;
    QlistNode *head;
    QlistNode *tail;
    QlistNode *next;
    
    public:
    QlistNode()
    {
        head = NULL;
        tail = NULL;
        next = NULL;
    }

    void display()
    {
        //using tail as traversing pointer
        tail = head;
        while(tail != NULL)
        {
            cout<<tail->data<<" ";
            tail = tail->next;

        }
        cout<<endl;
    }

    void enqueue(int n)
    {
        QlistNode *newnode = new QlistNode;
        newnode->data = n;
        newnode->next = head;
        head = newnode;

        newnode = NULL;
        delete newnode;
    }

    void dequeue()
    {
        if(head == NULL)
            cout<<"Queue is already empty!\n";

        else if(head->next == NULL)
        {
            // uing tail as extra pointer
            tail = head;
            head = tail->next;
            delete tail;
        }

        else
        {
            tail = head;
            QlistNode *p = head;
            p = p->next;

            
            while(p->next != NULL)
            {
                p = p->next;
                tail = tail->next;
            }

            cout<<"deleted number: "<<p->data<<endl;

            tail->next = p->next;
            delete p;
        }   
    }
}Q;

int main()
{
    //MASTER MENU DRIVEN
    do
    {
        cout<<"Enter CHARACTER for LL OPERATIONS\n";
        cout<<"'a' for Appending\n'c' for returning number of nodes in the LL\n'p' for Displaying LL\n'i' for Inserting\n's' for Searching\n'd' for deleting\n";
        cout<<"\nStack Using LL\n'x' to insert into stack(PUSH)\n'y' to Delete from stack(POP)\n'z' to Display Stack\n";
        cout<<"\nQueue Using LL\n'm' to enqueue.\n'n' to dequeue.\n'o' to display queue.\n";
        char ch;cin>>ch;

        switch(ch)
        {
            int x;
            case ('a'): A.append();break;

            case ('c'): cout<<"Number of nodes: "<<A.getcount()<<endl;break;

            case ('p'): A.display();break;

            case ('i'): cout<<"enter number after which to insert new element\n";
                        cin>>x;
                        A.insertafter(x);break;

            case ('d'): cout<<"enter num to be deleted: ";
                        cin>>x;
                        A.delnode(x);break;

            case ('s'): cout<<"enter number to be searched: ";
                        cin>>x;
                        A.search(x);break;

            case ('x'): cout<<"STACK OPR: Enter Ele to Insert\n";
                        cin>>x;
                        L.pushNode(x);break;
            
            case ('y'): cout<<"STACK OPR: Delete from stack\n";
                        L.popNode();break;

            case ('z'): L.disp();break;

            case ('m'): cout<<"QUEUE OPR:Enqueuing:\n";
                        cin>>x;
                        Q.enqueue(x);break;

            case ('n'): cout<<"QUEUE OPR:Dequeuing:\n";
                        Q.dequeue();break;

            case ('o'): cout<<"Displaying Queue:\n";
                        Q.display();break;
                                   

            default:cout<<"Invalid!!\nEXITING\n";exit(0);
        }

    }while(true);

}