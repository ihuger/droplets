#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

#define N (101*1000)
#define Inf 2e16

typedef pair<long long,int> Pair;
priority_queue<Pair> heap;
long long d[N];
vector<Pair> V[N];
Pair train[N];
int n,m,k;
bool visited[N];
int ans = 0;
void dij(int v){
    fill(d,d+n,Inf);
    fill(visited,visited+n,false);
    heap.push(Pair(0,-v));
    for ( int i = 0 ; i < k ; i++){
        heap.push(Pair(-train[i].first,-(train[i].second + N)));
    }
 
    d[0]=0;

    while( heap.size() > 0 ){
        Pair curr = heap.top(); heap.pop();
        long long dis = -curr.first;
        int u = -curr.second;
        if ( u >= N ){
            u = u - N;
            if (visited[u])
                ans++;
        }
        if(visited[u]){
            continue;
        }
     
        visited[u]=true;

        for ( int i = 0 ; i < V[u].size() ; i++){
            Pair next = V[u][i];
            int w = next.second;
            if(visited[w])
                continue;
    
            long long dis = next.first + d[u];
            if(dis < d[w]){
                d[w]=dis;
                heap.push(Pair(-dis,-w));
            }   
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for ( int i = 0 ; i < m ; i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        a--;b--;
        V[a].push_back(Pair(c,b));
        V[b].push_back(Pair(c,a));
    }

    for ( int i = 0 ; i < k ; i++){
        int a;
        long long b;
        cin >> a >> b;
        a--;        
        train[i] = Pair(b,a);
    }

    dij(0);

    cout << ans << endl;
    return 0;
}
