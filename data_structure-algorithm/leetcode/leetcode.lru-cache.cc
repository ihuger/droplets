#include<map>
#include<list>
#include<iostream>
using namespace std;
class LRUCache{
    private:
        int capacity ;
        map<int,int> lmap;
        list<int> lruList;
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }
        
        int get(int key) {
            if(lmap.count(key)>0){
                updateLRU(key);
                return lmap[key];
            }
            return -1;
        }
        
        void set(int key, int value) {
            if(lmap.count(key)>0){
                lmap[key]=value;
                updateLRU(key);
            }else if (lruList.length()<capacity){
                lruList.push_back(key);
                lmap[key]=value;
            }else{
                int first = lruList.front();
                lruList.pop_front();
                lmap.erase(first);
                lmap[key]=value;
                lruList.push_back(key);
            }
            printCache();
        }
        void updateLRU(int key){
            lruList.erase(key);
            lruList.push_back(key);
        }
        void printCache(){
            for(map<int,int>::iterator it = lmap.begin();
                it != lmap.end(); ++it){
                cout<<it->first<<" => "<< it->second<<endl;
            }

            cout<<endl;
            for(list<int>::iterator it = lruList.begin();
                it != lruList.end(); ++it){
                cout<<*it<<endl;
            }
            cout<<endl;

        }
};


int main(){
    LRUCache cache(2);
    cache.set(0,0);
    cache.set(1,1);
    cache.set(2,2);
    cache.set(3,3);
    cout<<cache.get(0)<<endl;
    cout<<cache.get(2)<<endl;
    cache.printCache();

    return 0;
}
