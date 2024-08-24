#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
     Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};
//O(n)
Node* convertArr2LL(int n, int a[])
{
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<n; i++)
    {
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}
//Traversal in LL:O(n)
void print(Node* head)
{
    Node* mover = head;
    while(mover!=nullptr)
    {
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<endl;
}
//LL length:O(n)
int lengthofLL(Node* head)
{
    int cnt=0;
    Node* mover = head;
    while(mover!=nullptr)
    {
        mover=mover->next;
        cnt++;
    }
    return cnt;
}
//Searching: O(n)
bool searchinLL(Node* head, int item)
{
    Node* mover = head;
    while(mover!=nullptr)
    {
        if(mover->data == item) return true;
        mover = mover->next;
    }
    return false;
}
//deletehead:O(1)
Node* removeHead(Node* head)
{
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
//deleteLast:O(n);
Node* removeTail(Node* head)
{
    Node* mover=head;
    if(mover == NULL || mover->next == NULL) return NULL;
    while(mover->next->next != nullptr)
    {
        mover=mover->next;
    }
    delete mover->next;
    mover->next = nullptr;
    return head;
}
//delete kth position:
Node* removeK(Node* head, int k)
{
    if(head==NULL) return head;
    if(k==1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* mover = head;
    Node* pre=NULL;
    while(mover!=NULL)
    {
        cnt++;
        if(cnt==k)
        {
            pre->next = pre->next->next;
            delete mover;
            break;
        }
        pre=mover;
        mover = mover->next;
    }
    return head;
}
//add Head:
Node* insertHead(Node* head, int val)
{
    Node* temp = new Node(val,head);
    return temp;
}
//add Tail:
Node* insertTail(Node* head, int val)
{
    if(head == NULL)
        return new Node(val);
    Node* mover = head;
    while(mover->next!=NULL)  {
            mover= mover->next;
    }
    Node* temp = new Node(val);
    mover->next = temp;

    return head;
}
//add kth item
Node* insertK(Node* head, int k, int val)
{
    if(head==NULL)
    {
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1)
    {
        return new Node(val,head);
    }
    int cnt=0;
    Node* mover = head;
    while(mover!=NULL)
    {
        cnt++;
        if(cnt==k-1)
        {
            Node* temp = new Node(val,mover->next);
            mover->next = temp;
            break;
        }
        mover = mover->next;
    }
    return head;
}
void Solve()
{
    //Node* y=new Node(9);
    //cout<<y->data<<endl;

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    Node* head = convertArr2LL(n,a);
    cout<<head->data<<endl;

    print(head);

    cout<<lengthofLL(head)<<endl;

    cout<<searchinLL(head,7)<<endl;

   head = removeHead(head);
   cout<<head->data<<endl;

    removeTail(head);
    print(head);

    removeK(head,2);
    print(head);

    head = insertHead(head,22);
    print(head);

    head = insertTail(head,0);
    print(head);

    head = insertK(head,3,99);
    print(head);
}

int main()
{
    int T=1;
    //cin>>T;
    while(T--)
    {
        Solve();
    }
    return 0;
}
