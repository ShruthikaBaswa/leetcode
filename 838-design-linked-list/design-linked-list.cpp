struct Node{
public:
    int v;
    Node* next;
    Node(int v){
        this->v=v;
        next=NULL;
    }
};

class MyLinkedList {
public:
    Node* h;
    int s;

    MyLinkedList() {
        h=NULL;
        s=0;
    }
    
    int get(int index) {
        if(index>=s || index<0){
            return -1;
        }
        Node* t=h;
        for(int i=0;i<index;i++){
            t=t->next;
        }
        return t->v;
    }
    
    void addAtHead(int v) {
        Node* nn=new Node(v);
        nn->next=h;
        h=nn;
        s++;
    }
    
    void addAtTail(int v) {
        Node* nn=new Node(v);
        if (!h) {
            h=nn;
        } 
        else {
            Node* t=h;
            while (t->next) t=t->next;
            t->next = nn;
        }
        s++;
    }
    
    void addAtIndex(int index, int v) {
        if (index<0 || index>s) return;
        if (index==0) {
            addAtHead(v);
            return;
        }
        if (index==s) {
            addAtTail(v);
            return;
        }
        Node* nn=new Node(v);
        Node* t=h;
        for(int i=0;i<index-1;i++){
            t=t->next;
        }
        nn->next=t->next;
        t->next=nn;
        s++;
    }
    void deleteAtHead() {
        if (!h) return;
        Node* t=h;
        h=h->next;
        delete t;
        s--;
    }

    void deleteAtTail() {
        if (!h) return;
        if (!h->next) {
            delete h;
            h=NULL;
        } else {
            Node* curr = h;
            while (curr->next->next) curr = curr->next;
            delete curr->next;
            curr->next =NULL;
        }
        s--;
    }
    
    void deleteAtIndex(int index) {
        if (index<0 || index>=s) return;
        if (index==0) {
            deleteAtHead();
        } else {
            Node* curr = h;
            for (int i=0;i<index-1;i++){ 
                curr = curr->next;
            }
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            s--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */