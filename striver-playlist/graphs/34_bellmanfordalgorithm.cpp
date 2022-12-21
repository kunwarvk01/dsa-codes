#include <bits/stdc++.h>
using namespace std;
// negetive for negetive cycles
// Directed Graph

// relax all the edges n-1 times sequentially
// relaxation= if(dis[u]+wt < dis[v]) dist[v]=dis[u]+wt;
