from heapq import heappush ,heappop

n,m,k = map(int,raw_input().split())

edges = {}
for i in range(n):
    edges[i+1] = {}

#ui to vi weight xi
for i in range(m):
    u,v,x = map(int,raw_input().split())
    if not edges[u].has_key(v) or edges[u][v] > x:
        edges[u][v] = x
        if u != 1:
            edges[v][u] = x

ans = 0
trains = set()
#1 to s weight y
for i in range(k):
    s,y = map(int,raw_input().split())
    if not edges[1].has_key(s) or edges[1][s] > y:
        edges[1][s] = y
        trains.add(s)

ans += k - len(trains)

if ans != k:
    frontier = [(0,1)]
    cost_so_far = {}
    for i in range(n):
        cost_so_far[i+1] = float('inf')
    cost_so_far[1] = 0

    visit ={}
    for i in range(n):
        visit[i+1] = 0
    count = 0

    while frontier:
        #print cost_so_far
        #print frontier
        current = heappop(frontier)[1]
        if visit[current] == 1:
            continue
        visit[current] = 1
        count += 1
        if current in trains :
            trains.remove(current)

        if(len(trains) == 0) or count == n:
            break
        for nextn in edges[current].keys():
            if visit[nextn] == 1:
                continue
            new_cost = cost_so_far[current] + edges[current][nextn]
            if new_cost <= cost_so_far[nextn]:
                if cost_so_far[nextn]!=float('inf') and nextn in trains:
                    ans += 1
                    trains.remove(nextn)
                cost_so_far[nextn] = new_cost
                heappush(frontier,(new_cost,nextn))
print ans

