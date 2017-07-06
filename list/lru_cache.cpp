#include <iostream>
#include <vector>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

template<class K, class T>
class Node {
public:
    K key;
    T data;
    Node *prev,*next;
};

template<class K,class T>
class LRUCache{
private:
    hash_map<K,Node<K,T>* > hs_mp;
    vector<Node<K,T>* >free_empties;
    Node<K,T> * head,*tail;
    Node<K,T> * tmp;
private:
    void detach(Node<K,T>* node){
        node = tail->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(Node<K,T> * node){
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev =  node;
    }
public:
    LRUCache(int size){
        tmp  = new Node<K,T>[size];
        int i;
        for(i=0;i<size;i++){
            free_empties.push_back(tmp+i);
        }
        head = new Node<K,T>;
        tail = new Node<K,T>;
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    ~LRUCache(){
        delete head;
        delete tail;
        delete []tmp;
    }
    void Put(K key,T data){
        Node<K,T>* node = hs_mp[key];
        if(node){
            detach(node);
            node->data = data;
            attach(node);
        }
        else{
            if(free_empties.empty()){
                node = tail->prev;
                detach(node);
                hs_mp.erase(node->key);
            }
            else{
                node = free_empties.back();
                free_empties.pop_back();
            }
            node->key = key;
            node->data = data;
            hs_mp[key] = node;
            attach(node);
        }
    }
    T Get(K key){
        Node<K,T> * node = hs_mp[key];
        if(node){
            detach(node);
            attach(node);
            return node->data;
        }
        else{
            return T();
        }
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
