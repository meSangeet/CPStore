#include <bits/stdc++.h>
using namespace std;

#define ll long long

class DSU {
private:
    vector<ll> parent; // Stores the parent of each element
    vector<ll> rank;   // Stores the rank of each set (for union by rank)
    vector<ll> size;   // Stores the size of each set (optional, but useful)

public:
    // Constructor to initialize DSU with 'n' elements
    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 1); // Initially, rank of each set is 1
        size.resize(n, 1); // Initially, size of each set is 1
        for (ll i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find the root of the set containing 'x' (with path compression)
    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union of two sets containing 'x' and 'y' (with union by rank)
    void unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; // Update size
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX]; // Update size
            } else {
                parent[rootY] = rootX;
                rank[rootX]++; // Increase rank if ranks are equal
                size[rootX] += size[rootY]; // Update size
            }
        }
    }

    // Check if 'x' and 'y' are in the same set
    bool sameSet(ll x, ll y) {
        return find(x) == find(y);
    }

    // Get the size of the set containing 'x'
    ll getSize(ll x) {
        ll root = find(x);
        return size[root];
    }

    // Get the number of disjoint sets (optional)
    ll countSets() {
        ll count = 0;
        for (ll i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Example usage
    ll n = 10;
    DSU dsu(n);

    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(4, 5);
    dsu.unite(6, 7);
    dsu.unite(8, 9);

    cout << "Is 0 and 1 in the same set? " << dsu.sameSet(0, 1) << endl; // Output: 1 (true)
    cout << "Is 0 and 2 in the same set? " << dsu.sameSet(0, 2) << endl; // Output: 0 (false)

    dsu.unite(1, 2);
    cout << "Is 0 and 2 in the same set now? " << dsu.sameSet(0, 2) << endl; // Output: 1 (true)

    cout << "Size of the set containing 0: " << dsu.getSize(0) << endl; // Output: 4
    cout << "Total number of disjoint sets: " << dsu.countSets() << endl; // Output: 6

    return 0;
}
