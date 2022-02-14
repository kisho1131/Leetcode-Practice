class UnionFind {
private:
    int* root;
    int* rank;
    int _root; // Purpose to get top root of the "graph that contains all people who know the secret"
public:
    UnionFind(int size) {
        root = new int[size];
        rank = new int[size];
        _root = 0;
        
        for(int i = 0; i < size; i++) {
            *(root + i) = i;
            *(rank + i) = 1;
        }
    }
    
    int find(int x) {
        if(*(root + x) == x) return x;
        return *(root + x) = find(*(root + x));
    }
    
    void setUnion(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY) {
            if(*(rank + rootX) > *(rank + rootY)) {
                if(_root == rootY) _root = rootX;
                *(root + rootY) = rootX;
            }
            else if(*(rank + rootX) < *(rank + rootY)) {
                if(_root == rootX) _root = rootY;
                *(root + rootX) = rootY;
            }
            else {
                if(_root == rootY) _root = rootX;
                *(root + rootY) = rootX;
                *(rank + rootX) += 1;
            }
        }
    }
    
    void setDefault(int x) {
        *(root + x) = x;
        *(rank + 1) = 1;
    }
    
    bool isKnowSecret(int x) {
        return find(x) == getTopRoot();
    }
    
    int getTopRoot() {
        return _root;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& m1, vector<int>& m2) -> bool {return m1[2] < m2[2];});
        
        UnionFind uf(n);
        uf.setUnion(0, firstPerson);
        
        int curtime = 0;
        unordered_set<int> s;
        for(int i = 0; i < meetings.size(); i++) {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int time = meetings[i][2];
            
            // Graph all the meetings that have a same time, if not, check if all people attending those meetings know the secret
            if(time > curtime) {
                for(decltype(s)::iterator it = s.begin(); it != s.end(); it++) {
                    int person = *it;
                    if(uf.find(person) != uf.getTopRoot()) uf.setDefault(person);
                }
                
                curtime = time;
                s.clear();
            }
            
            uf.setUnion(person1, person2);
            s.insert(person1);
            s.insert(person2);
        }
        
        vector<int> res;
        for(int person = 0; person < n; person++) 
            if(uf.isKnowSecret(person)) res.push_back(person);
        
        return res;
    }
};