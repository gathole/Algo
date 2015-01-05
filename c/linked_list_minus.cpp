#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdlib>

using namespace std;

// strucyture for linkedlist node
struct linkedlist
{
    int value;
    struct linkedlist * next;
}*head=NULL;

// function that manipulate node values and invoked by helper function

void doDesired(struct linkedlist ** root, struct linkedlist* root1, int *n)
{
    if(root1->next!=NULL)
    {
        *n= (*n)+1;
        doDesired(root, root1->next,n);
    }
    if(*n>1)
    {
        (*root)->value-=root1->value;
        *root= ((*root)->next);
        *n=*n-2;
    }
}

// helper function
void yourIntention(struct linkedlist ** root)
{
    int i=1;
    doDesired(root,*root,&i); 
}

// driver
int main()
{
    int length,enter,slength;
    cout<<"it is worthless asking it in linkedlist but for simlicity :)"<<endl;
    cout<<"how many elements are there?"<<endl;
    cin>>length;
    slength=length;
    linkedlist * p=head;
    p=(linkedlist *)malloc(length*sizeof(linkedlist));
    head =p;
    cout<<"enter the elements"<<endl;
    while(length--)
    {
        cin>>enter;
        p->value=enter;
        if(length==0)
        {
            p->next=NULL;
        }
        else
        {
            p->next=p+1;
            ++p;
        }
    }

    linkedlist * temp=head;
    yourIntention(&head);

    // print the modified  list 
    cout<<endl;
    cout<<"Modified Linked List"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->next;
    }
    return 0;
}
