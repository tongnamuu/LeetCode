class MapSum {
public:
    /** Initialize your data structure here. */
    struct Node {
        int children[26];
        int terminated;
        Node() {
            for(int i=0;i<26;++i) children[i] = -1;
            terminated = 0;
        }
    };
    Node nodePool[5000];
    int nodeCnt;
    int newNode() {
        return nodeCnt++;
    }
    Node* head;
    MapSum() {
        head = &nodePool[newNode()];
    }
    
    void insert(string key, int val) {
        int n = key.length();
        Node* temp = head;
        for(int i=0;i<n;++i) {
            int c  = key[i]-'a';
            int& next = temp->children[c];
            if(next== -1) {
                next = newNode();
            }
            temp = &nodePool[next];
        }
        temp->terminated = val;
    }
    int getSum(Node* node) {
        int res = node->terminated;
        for(int i=0;i<26;++i) {
            if(node->children[i]!=-1) {
                res += getSum(&nodePool[node->children[i]]);
            }
        }
        return res;
    }
    int sum(string prefix) {
        int n = prefix.length();
        Node* temp = head;
        int ans = 0;
        for(int i=0;i<n;++i) {
            int c= prefix[i]-'a';
            int next = temp->children[c];
            if(next==-1) return 0;
            temp = &nodePool[next];
        }
        return getSum(temp);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
