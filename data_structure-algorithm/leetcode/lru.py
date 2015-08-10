class Dnode(object):
    def __init__(self,key,value):
        self._key = key
        self._value = value
        self._pre = None
        self._next = None

class DoubleLinkedList(object):
    def __init__(self):
        self._head = None
        self._tail = None

    def pop(self):
        if self._head is None:
            return None
        else:
            dnode = self._head
            self._head = self._head._next
            dnode._next = None
            if self._head is not None:
                self._head._pre = None
            else: #empty
                self._tail = None
            return dnode

    def push(self,dnode):
        if self._tail is None: #empty list
            self._head = self._tail = dnode
        else:
            self._tail._next = dnode
            dnode._pre = self._tail
            self._tail = dnode

    def update(self,dnode):
        if dnode._next is None:#tail
            return
        elif dnode._pre is None:#head(next not empty)
            self._head = dnode._next
            self._head._pre = None
        else:
            dnode._pre._next = dnode._next
            dnode._next._pre = dnode._pre
        dnode._next = None
        self.push(dnode)

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.tunk = {}
        self.dlink = DoubleLinkedList()

    # @return an integer
    def get(self, key):
        if key in self.tunk:
            self.dlink.update(self.tunk[key])
            return self.tunk[key]._value
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.tunk:
            self.tunk[key]._value = value
            self.dlink.update(self.tunk[key])
        else:
            if len(self.tunk) >= self.capacity:
                dnode = self.dlink.pop()
                del self.tunk[dnode._key]
                del dnode
            self.tunk[key] = Dnode(key,value)
            self.dlink.push(self.tunk[key])

if __name__ == '__main__':
    lru = LRUCache(2)
    lru.set(1,1)
    print lru.tunk.keys()
    lru.set(2,2)
    print lru.tunk.keys()
    lru.set(3,3)
    print lru.tunk.keys()
    lru.set(4,4)
    print lru.tunk.keys()
