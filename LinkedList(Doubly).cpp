#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* bk;
public:
    Node(int data1){
        data = data1;
        next = nullptr;
        bk = nullptr;
    }
public:
    Node(int data1,Node* next1, Node* bk1){
        data = data1;
        next  = next1;
        bk = bk1;
    }
};

//Convert Array to DLL:O(n)
Node* Arr2DLL(int n, int a[])
{
    Node* head = new Node(a[0]);
    Node* pre = head;
    for(int i=1; i<n; i++)
    {
        Node* temp = new Node(a[i],nullptr,pre);
        pre->next=temp;
        pre=temp;
    }
    return head;
}

//printing
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//delete head:
Node* removeHead(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* pre=head;
    head=head->next;
    head->bk=nullptr;
    pre->next=nullptr;
    delete pre;
    return head;
}

//delete Tail:
Node* removeTail(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node* pre=NULL;
    Node* mover = head;
    while(mover->next!=NULL)
    {
        mover=mover->next;
    }
    pre = mover->bk;
    pre->next=nullptr;
    mover->bk=nullptr;
    delete mover;
    return head;
}

//delete kth item:
Node* removeK(Node* head, int k)
{
    if(head==NULL) return NULL;
    int cnt =0;
    Node* mover=head;
    while(mover!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        mover=mover->next;
    }
    Node* pre=mover->bk;
    Node* af=mover->next;
    if(pre==NULL && af==NULL) return NULL;
    else if(pre==NULL) return removeHead(head);
    else if(af==NULL) return removeTail(head);
    else
    {
        pre->next = af;
        af->bk=pre;
        mover->bk=nullptr;
        mover->next=nullptr;
        delete mover;
        return head;
    }
}
//delete a node
void deleteNode(Node* node)
{
    Node* pre=node->bk;
    Node* af = node->next;
    if(af==NULL)
    {
        pre->next=NULL;
        node->bk=NULL;
        delete node;
    }
    pre->next=af;
    af->bk=pre;
    node->bk=NULL;
    node->next=NULL;
    delete node;
}

//add before head:
Node* insertBeforeHead(Node* head, int val)
{
    Node* temp=new Node(val,head,nullptr);
    head->bk=temp;
    return temp;
}
//add before Tail:
Node* insertBeforeTail(Node* head, int val)
{
    if(head->next==NULL) return insertBeforeHead(head, val);
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* pre=tail->bk;
    Node* newNode = new Node(val,tail,pre);
    pre->next=newNode;
    tail->bk=newNode;
    return head;
}

//add kth item:
Node* insertBeforeK(Node* head, int k, int val)
{
    if(k==1) return insertBeforeHead(head,val);
    int cnt=0;
    Node* mover=head;
    while(mover!=NULL)
    {
        cnt++;
        if(cnt==k) break;
        mover=mover->next;
    }
    Node* pre=mover->bk;
    Node* newNode = new Node(val,mover,pre);
    pre->next=newNode;
    mover->bk=newNode;
    return head;
}
//add before node
void insertBeforeNode(Node* node, int val)
{
    Node* pre=node->bk;
    Node* newNode = new Node(val,node,pre);
    pre->next=newNode;
    node->bk=newNode;
}
void Solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    Node* head = Arr2DLL(n,a);
    print(head);

    head = removeHead(head);
    print(head);

    head = removeTail(head);
    print(head);

    head = removeK(head,2);
    print(head);

    deleteNode(head->next);
    print(head);

    head = insertBeforeHead(head,22);
    print(head);

    head = insertBeforeTail(head,21);
    print(head);

    head = insertBeforeK(head,2,99);
    print(head);

    insertBeforeNode(head->next->next,100);
    print(head);
}

int main()
{
    int T=1;
   // cin>>T;
    while(T--)
        Solve();
    return 0;
}
