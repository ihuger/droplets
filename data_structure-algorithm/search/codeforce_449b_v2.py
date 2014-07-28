#!/usr/bin/env python
#coding utf-8

from Queue import PriorityQueue


class Graph:
    def __init__(self):
        [n,m,k] = map(int,raw_input().split())
        self.neighbs = {}
        self.edges = {}
        #ui to vi weight xi
        for i in range(m):
            [u,v,x] = map(int,raw_input().split())
            if not (u,v) in self.edges or self.edges[(u,v)] > x:
                self.edges[(u,v)] = x
                self.edges[(v,u)] = x

            if not u in self.neighbs:
                self.neighbs[u] = set()
            self.neighbs[u].add(v)

            if not v in self.neighbs:
                self.neighbs[v] = set()
            self.neighbs[v].add(u)

        self.trains = set()
        #1 to s weight y
        for i in range(k):
            [s,y] = map(int,raw_input().split())
            if not (1,s) in self.edges or self.edges[(1,s)] > y:
                self.edges[(1,s)] = y
                self.neighbs[1].add(s)
                self.trains.add((1,s))

        self.all_nodes = set()
        for i in range(n):
            self.all_nodes.add(i+1)

        print k - self.dijkstra(1,n)

    def neighbors(self,node):
        if not node in self.neighbs:
            return set()
        return self.neighbs[node]

    def cost(self,snode,enode):
        return self.edges[(snode,enode)]

    def dijkstra(self,start,n):
        frontier = PriorityQueue()
        frontier.put((0,(start,start)))
        cost_so_far = {}
        cost_so_far[start] = 0
        visit = set()
        train_count = 0

        while not frontier.empty():
            edges = frontier.get()[1]
            current = edges[1]
            if not current in visit:
                visit.add(current)
                if edges in self.trains:
                    train_count += 1
            else:
                continue
            if(len(visit) == n):
                break
            for nextn in self.neighbors(current):
                if nextn in visit:
                    continue
                new_cost = cost_so_far[current] + self.cost(current,nextn)
                if nextn not in cost_so_far  or new_cost < cost_so_far[nextn]:
                    cost_so_far[nextn] = new_cost
                    frontier.put((new_cost,(current,nextn)))

        return train_count


graph = Graph()
