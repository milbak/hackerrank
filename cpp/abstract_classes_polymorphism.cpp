// Abstract classes - polymorphism
typedef std::map<int,Node*>::iterator IterLRU;
class LRUCache : public Cache{
    public:
        LRUCache(int);
        void set(int, int);
        int get(int);
        Node* popNode(int);
        void headRefresh(Node*);
        void printMap();
        void printList();
};

LRUCache::LRUCache(int capacity){
    cp = capacity;
    head = nullptr;
    tail = nullptr;
}

Node* LRUCache::popNode(int k){
    Node* node = mp[k];
    Node* p = node->prev;
    Node* n = node->next;
    
    if(p != nullptr){
        mp[p->key]->next = n;
        if(n == nullptr)
            tail = mp[p->key];
    }
    if(n != nullptr){
        mp[n->key]->prev = p;
        if(p == nullptr)
            head = mp[n->key];
    }
    //std::cout<<"pop!\n";
    return node;
}

void LRUCache::headRefresh(Node* newNode){
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else if (head != newNode){
        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    }
}

void LRUCache::printList(){
    std::cout <<"Begin list loop:\n";
    Node* curr = head;
    std::cout<<"\thead -> ";
    while(curr != nullptr){
        std::cout << "(" << curr->key << "," << curr->value << ") "<< "-> ";
        curr = curr->next;
    }
    std::cout<<"tail\n";
}

void LRUCache::printMap(){
    std::cout <<"Begin map loop:\n";
    for(IterLRU it = mp.begin(); it != mp.end(); ++it){
        std::string p = "nullptr";
        std::string n = "nullptr";
        if(it->second->prev != nullptr)
            p = std::to_string(it->second->prev->key);
        if(it->second->next != nullptr)
            n = std::to_string(it->second->next->key);
        std::cout << "\t" << p << "->" << it->first << "->" << n <<std::endl;
    }
    std::cout<<std::endl;    
}

void LRUCache::set(int k, int v){
     Node* newNode;
    //check if node exists in cache
    if(mp.find(k) == mp.end()){
        //std::cout<<"setting node...\n";
        newNode = new Node(nullptr, nullptr, k,v);
        mp.insert(std::pair<int,Node*>(k,newNode));
    } else {
        //std::cout<<"moving node...\n";
        newNode = popNode(k);
        newNode->value = v;
    }
    
    headRefresh(newNode);
    
    //check size v. capacity
    if(mp.size()>cp){
        tail = tail->prev;
        mp.erase(tail->next->key);
        tail->next = nullptr;
    }
    //printList();
    //printMap();
}

int LRUCache::get(int k){
    int v = -1;
    //std::cout<<"getting node...\n";
    if(mp.find(k)!=mp.end()){  
        Node* n = popNode(k);
        headRefresh(n);
        v = n->value;
    }
    
    return v;
}