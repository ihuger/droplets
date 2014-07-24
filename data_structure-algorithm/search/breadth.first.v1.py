#!/usr/bin/env python
from Queue import Queue
from sets import Set

def run(graph,start,goal):
    frontier = Queue()
    frontier.put(start)
    came_from = {}
    came_from[start] = None

    while not frontier.empty():
       current = frontier.get()
       for next in graph.neighbors(current):
          if next not in came_from:
             frontier.put(next)
             came_from[next] = current

    for x in came_from:
        print x,came_from[x]

    current = goal
    path = [current]
    while current != start:
        current = came_from[current]
        path.append(current)
    print path


class Graph:
    def __init__(self,xlen,ylen):
        self.all_nodes = Set()
        for x in range(xlen):
            for y in range(ylen):
                self.all_nodes.add((x,y))

    def neighbors(self,node):
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        result = []
        for dir in dirs:
            neighbor = (node[0] + dir[0], node[1] + dir[1])
            if neighbor in self.all_nodes:
                result.append(neighbor)
        return result

    def obsecu(self,node):
        pass

if __name__ == "__main__":
    graph = Graph(3,3)
    start = (1,1)
    goal = (0,0)
    run(graph,start,goal)


