#include <bits/stdc++.h>
using namespace std;

#define root 0
#define N 10010
#define LN 14

#define ll long long int
#define pb push_back

vector <ll> adj[N], costs[N];
ll baseArray[N], ptr;
ll chainNo, chainInd[N], chainHead[N], posInBase[N];
ll depth[N], pa[LN][N], subsize[N];
ll st[N*6];

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(ll cur, ll s, ll e) {
	if(s == e-1) {
		st[cur] = baseArray[s];
		return;
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = max(st[c1],st[c2]);
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(ll cur, ll s, ll e, ll x, ll val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	//st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	st[cur] = max(st[c1],st[c2]);
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
ll query_tree(ll cur, ll s, ll e, ll S, ll E) {
	if(s >= E || e <= S) {
		return -1ll;
	}
	if(s >= S && e <= E) {

		return st[cur];
	}
	ll c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	return max(query_tree(c1, s, m, S, E),query_tree(c2, m, e, S, E));
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

ll query_up(ll u, ll v) {
	if(u == v) return 0; // Trivial
	ll uchain, vchain = chainInd[v], ans = -1ll;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v) break;
			ans=max(ans,query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1));
			break;
		}
		ans= max(ans,query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1));

		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
 ll f_par(ll u,ll l)
{
    ll j=0;
   while(1)
   {
       ll v=pa[j][u];
       if(depth[v]==l) return v;
       else if(depth[v]>l) j++;
       else
       {
           u=pa[j-1][u];
           if(depth[u]==l) return u;
           j=0;
       }
   }
}

ll LCA(ll u, ll v) {
	if(depth[u] < depth[v]) swap(u,v);
	ll diff = depth[u] - depth[v];
	for(ll i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(ll i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

ll query(ll u, ll v) {
	ll lca = LCA(u, v);
	ll ans = query_up(u, lca); // One part of path
	ll temp = query_up(v, lca); // another part of path

	return max(ans,temp);
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(ll i, ll j, ll val) {

	ll u = depth[i]>depth[j]? i:j;
	update_tree(1, 0, ptr, posInBase[u], val);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(ll curNode, ll cost, ll prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	ll sc = -1, ncost;
	// Loop to find special child
	for(ll i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(ll i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(ll cur, ll prev, ll _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(ll i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}


vector< pair<ll,ll> > id;

int main() {
	ll t,a,b,c, n,q;

    scanf("%lld",&t);

    while(t--)
    {
		ptr = 0;

		scanf("%lld", &n);

		// Cleaning step, new test case
		id.clear();
		for(ll i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			chainHead[i] = -1;
			for(ll j=0; j<LN; j++) pa[j][i] = -1;
		}
		for(ll i=1; i<n; i++)
        {
			ll u, v, c;
			scanf("%lld %lld %lld", &u, &v, &c);
			u--; v--;
			id.pb(make_pair(u,v));

			adj[u].pb(v);
			costs[u].pb(c);
			adj[v].pb(u);
			costs[v].pb(c);
		}

		chainNo = 0;
		dfs(root, -1); // We set up subsize, depth and parent for each node
		HLD(root, -1, -1); // We decomposed the tree and created baseArray
		make_tree(1, 0, ptr); // We use baseArray and construct the needed segment tree


		for(ll i=1; i<LN; i++)
			for(ll j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

        char str[20];
        while(1) {
            scanf(" %s",&str);

            if(str[0]=='D')
                break ;
            scanf("%lld %lld",&b,&c);
            if(str[0]=='C')
            {
				change(id[b-1].first,id[b-1].second,c);
			}
			else
            {
                printf("%lld\n",query(b-1, c-1));
            }
		}
    }
	return 0;
}
