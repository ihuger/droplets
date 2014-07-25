#!/usr/bin/env python
#coding:utf-8
from sets import Set

#grid graph
class Graph:
    def __init__(self,xlen,ylen):
        self.all_nodes = Set()
        for x in range(xlen):
            for y in range(ylen):
                self.all_nodes.add((x,y))

    def edges(self):
        pass

    def neighbors(self,node):
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        result = []
        for dir in dirs:
            neighbor = (node[0] + dir[0], node[1] + dir[1])
            if neighbor in self.all_nodes:
                result.append(neighbor)
        return result

    def walls(self,node):
        pass


