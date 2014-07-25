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

        self.walls([2,3,4,5,6])

    def edges(self):
        pass

    def cost(self,start_node,end_node):
        if(start_node[0]>2 and start_node[0]<6
                and start_node[1]>2 and start_node[1]<6):
            return 40
        else:
            return 1
#        return self.edges(start_node,end_node)

    #greedy cost
    def gcost(self,node0,node1):
        return abs(node0[0]-node1[0]) + abs(node0[1]-node1[1])

    def neighbors(self,node):
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        result = []
        for dir in dirs:
            neighbor = (node[0] + dir[0], node[1] + dir[1])
            if neighbor in self.all_nodes:
                result.append(neighbor)
        return result

    def walls(self,indexs):
        for x in indexs:
            self.all_nodes.remove((x,4))



