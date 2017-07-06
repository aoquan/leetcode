#include <iostream>
#include <vector>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

template <class K,class T>
class Node{
public:
    K key;
    T data;
    Node * prev, * next;
};

template <class K,class T>
class LRUCache{
private:
    hash_map<K,Node<K,T>* > hp;
    vector<Node<K,T>* > free_entries;
    Node<K,T> *head,*tail;
    Node<K,T> * entries;
public:
    LRUCache(int size){
        entries = new Node<K,T>[size];
        int i;
        for(i=0;i<size;i++){
            free_entries.push_back(entries+i);
        }
        head = new Node<K,T>;
        tail = new Node<K,T>;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }
    ~LRUCache(){
        delete []entries;
        delete head;
        delete tail;
    }

    void Put(K key,T data){
        Node<K,T> * node  = hp[key];
        if(node){
            detach(node);
            node->data = data;
            attach(node);
        }
        else{
            if(free_entries.empty()){
                node  = tail->prev;
                detach(node);
                hp.erase(node->key);
            }
            else{
                node  = free_entries.back();
                free_entries.pop_back();
            }
            node->key = key;
            node->data = data;
            hp[key] = node;
            attach(node);
        }
    
    }

    T Get(K key){
        Node<K,T> * node =hp[key];
        if(node){
            detach(node);
            attach(node);
            return node->data;
        }
        else{
            return T();
        }
    }
private:
    void detach(Node<K,T>* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(Node<K,T>* node){
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }
};

int main(){
    hash_map<int,int> map;
    map[9] = 999;
    cout<< map[9]<<endl;
    LRUCache<int,string> lru_cache(100);
    lru_cache.Put(1,"one");
    cout<<lru_cache.Get(1)<<endl;
    if(lru_cache.Get(2) == ""){
        lru_cache.Put(2,"two");
    }
    cout<<lru_cache.Get(2)<<endl;
    return 0;
}
