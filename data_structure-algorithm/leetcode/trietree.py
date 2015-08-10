#!/usr/bin/env python

class TrieTree(object):

    def __init__(self):
        self.header = {}

    def find(self,string):
        tmp = self.header
        idx = 0
        while tmp is not None and  idx < len(string):
            if string[idx] not in tmp:
                return -1
            tmp = tmp[string[idx]]
            idx += 1
        #if idx

    def insert(self,string):
        tmp = self.header
        idx = 0
        while idx < len(string):
            if string[idx] not in tmp:
                tmp[string[idx]] = {}
            tmp = tmp[string[idx]]
            idx += 1

        #store additional information
        #if idx != 0:
        #    if None not in tmp:
        #        tmp[None] = [v]
        #    tmp[None] =[v]

    def tostring(self):
        return self.header


if __name__ == "__main__":

    dt = TrieTree()
    dt.insert("abcd")
    dt.insert("abcd")
    dt.insert("bcd")
    dt.insert("dkfjksdlfj")
    dt.insert("2394823948")
    dt.insert("skdckjdkj")
    print dt.tostring()
