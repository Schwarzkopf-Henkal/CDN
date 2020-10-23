#include<bits/stdc++.h>
using namespace std;
struct treap{
    static const int N=1e5+5;
    int val[N],rnk[N],ls[N],rs[N],siz[N],tot,root;
    pair<int,int>split(int u,int key){//左子树是小于的，右子树是大于等于的
        if(u==0)
            return make_pair(0,0);
        if(key<=siz[ls[u]]){
            pair<int,int>o=split(ls[u],key);
            ls[u]=o.second;
            siz[u]=siz[ls[u]]+siz[rs[u]]+1;
            return make_pair(o.first,u);
        }else{
            pair<int,int>o=split(rs[u],key-siz[ls[u]]-1);
            rs[u]=o.first;
            siz[u]=siz[ls[u]]+siz[rs[u]]+1;
            return make_pair(u,o.second);
        }
    }
    int merge(int u,int v){
        if(u==0)
            return v;
        if(v==0)
            return u;
        if(rnk[u]>rnk[v]){
            rs[u]=merge(rs[u],v);
            siz[u]=siz[ls[u]]+siz[rs[u]]+1;
            return u;
        }else {
            ls[v]=merge(u,ls[v]);
            siz[v]=siz[ls[v]]+siz[rs[v]]+1;
            return v;
        }
    }
    int Node(int key){
        val[++tot]=key;
        rnk[tot]=rand();
        siz[tot]=1;
        return tot;
    }
};