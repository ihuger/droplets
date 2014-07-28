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

typedef pair<long long,int> Pair;
priority_queue<Pair> heap;
long long d[N];
vector<Pair> V[N];
Pair train[N];
int n,m,k;
bool mark[N];
int ans = 0;
void dij(int v){
    fill(d,d+n,-1);
    heap.push(Pair(0,-v));
    for ( int i = 0 ; i < k ; i++){
        heap.push(Pair(-train[i].first,-(train[i].second + N)));
    }
    
    int cc = 0; 

    while( heap.size() > 0 ){
        Pair curr = heap.top(); heap.pop();
        int u = -curr.second;
        long long dis = -curr.first;

        if ( u >= N ){
            u = u - N;
            if ( mark[u])
                ans++;
        }
        
        if ( mark[u] )
            continue;

        d[u] = dis;
        mark[u] = true;     

        for ( int i = 0 ; i < V[u].size() ; i++){
            Pair next = V[u][i];
            
            int w = next.second;

            long long dis = next.first;
            
            heap.push(Pair(-(d[u]+dis),-w));
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
