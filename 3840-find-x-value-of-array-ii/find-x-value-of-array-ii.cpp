class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod=1;
            for(int i=0;i<5;i++) cnt[i]=0;
        }
    };

    int k;
    vector<Node> seg;

    Node merge(Node a,Node b) {
        Node res;

        res.prod=(a.prod*b.prod)%k;

        for(int r=0;r<k;r++)
            res.cnt[r]=a.cnt[r];

        for(int r=0;r<k;r++) {
            int nr=(a.prod*r)%k;
            res.cnt[nr]+=b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums,int idx,int l,int r) {
        if(l==r) {
            int rem=nums[l]%k;
            seg[idx].prod=rem;
            seg[idx].cnt[rem]=1;
            return;
        }

        int mid=(l+r)/2;

        build(nums,idx*2,l,mid);
        build(nums,idx*2+1,mid+1,r);

        seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
    }

    void update(int idx,int l,int r,int pos,int val) {
        if(l==r) {
            for(int i=0;i<5;i++)
                seg[idx].cnt[i]=0;

            int rem=val%k;
            seg[idx].prod=rem;
            seg[idx].cnt[rem]=1;
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid)
            update(idx*2,l,mid,pos,val);
        else
            update(idx*2+1,mid+1,r,pos,val);

        seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
    }

    Node query(int idx,int l,int r,int ql) {
        if(ql<=l)
            return seg[idx];

        int mid=(l+r)/2;

        if(ql>mid)
            return query(idx*2+1,mid+1,r,ql);

        Node left=query(idx*2,l,mid,ql);
        Node right=seg[idx*2+1];

        return merge(left,right);
    }

    vector<int> resultArray(vector<int>& nums,int k,vector<vector<int>>& queries) {
        this->k=k;

        int n=nums.size();
        seg.resize(4*n+5);

        build(nums,1,0,n-1);

        vector<int> ans;

        for(auto &q:queries) {
            int index=q[0];
            int value=q[1];
            int start=q[2];
            int x=q[3];

            update(1,0,n-1,index,value);

            Node res=query(1,0,n-1,start);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};