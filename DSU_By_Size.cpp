#include <bits/stdc++.h>
class DisjointSet {
    vector<int> rank, parent, size;
    
public : 
    DisjointSet(int n) {
        
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1);
        
        for(int i=0; i<=n ;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); 
    }
        
        void unionBySize(int u, int v) {
        
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        
        // if size of u is less than size of v, then we attach
        // u to v and change ult par of u to ult par of v.
        
        // Inc size of v by size of u as u is now attached to v; this is similar to height and wayy diff from rank, so whenever new component is attached we inc the rank.
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[upl_v];
        }
    }
    
};

