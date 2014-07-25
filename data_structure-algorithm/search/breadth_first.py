#!/usr/bin/env python
#coding:utf-8
from graph import Graph
from Queue import Queue
from sets import Set

def run(graph,start,goal):
    frontier = Queue()
    frontier.put(start)
    came_from = {}
    came_from[start] = None

    while not frontier.empty():
       current = frontier.get()

       #early exit
       if current == goal:
           break

       for next in graph.neighbors(current):
          if next not in came_from:
             frontier.put(next)
             came_from[next] = current

    #for x in came_from:
    #    print (x,came_from[x],),
    print len(came_from)

    current = goal
    path = [current]
    while current != start:
        current = came_from[current]
        path.append(current)
    print path


if __name__ == "__main__":
    graph = Graph(10,10)
    start = (3,3)
    goal = (6,6)
    run(graph,start,goal)


