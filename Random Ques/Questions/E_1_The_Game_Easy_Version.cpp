#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<ll>> &adj, ll node, ll parent, ll &curTime, vector<ll> &inTime, vector<ll> &outTime){
    inTime[node] = curTime++;
    //traverse all the childs
    for(ll child : adj[node]){
        if(child != parent){
            dfs(adj, child, node, curTime, inTime, outTime);
        }
    }

    outTime[node] = curTime++;
}

void solve(){
    ll totalNodes; cin>>totalNodes;
    map<ll,vector<ll>> freq;
    for(int node = 0; node < totalNodes; node++){
        ll weight; cin>>weight;
        freq[weight].push_back(node);
    }

    vector<pair<ll,vector<ll>>> vec;
    for(auto x : freq){
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    vector<vector<ll>> adj(totalNodes);
    for(int i = 0; i<totalNodes-1; i++){
        ll u,v; cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(vec.size() == 1){
        cout<<0<<endl;
        return;
    }

    vector<ll> inTime(totalNodes, -1);
    vector<ll> outTime(totalNodes, -1);
    ll curTime = 0;
    dfs(adj, 0, -1, curTime, inTime, outTime);
    

    // for(auto x : outTime) cout<<x<<" ";
    // cout<<"\n";

    for(ll i = 1; i<vec.size(); i++){
        for(ll node : vec[i].second){
            ll intime = inTime[node];
            ll outtime = outTime[node];
            for(ll preNode : vec[i-1].second){
                ll inn = inTime[preNode];
                ll outt = outTime[preNode];
                if(inn < intime || outt > outtime){
                    cout<<node+1<<"\n";
                    return;
                }
            }
        }
    }

    cout<<0<<'\n';
}

int main(){
    int t; cin>>t;
    int temp = t;
    while(t--){
        // cout<<"TEST - "<<temp-t<<endl;
        solve();
    }
    return 0;
}