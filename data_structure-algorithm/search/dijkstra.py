#!/usr/bin/env python
#coding:utf-8
from graph import Graph
from Queue import PriorityQueue
from sets import Set

def run(graph,start,goal):

    frontier = PriorityQueue()
    frontier.put((0,start))
    came_from = {}
    came_from[start] = None
    cost_so_far = {}
    cost_so_far[start] = 0

    while not frontier.empty():
        current = frontier.get()[1]

        if current == goal:
            break

        for nextNode in graph.neighbors(current):
            new_cost = cost_so_far[current] + graph.cost(current,nextNode)
            if nextNode not in cost_so_far or new_cost < cost_so_far[nextNode]:
                frontier.put((new_cost,nextNode))
                cost_so_far[nextNode] = new_cost;
                came_from[nextNode] = current

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


