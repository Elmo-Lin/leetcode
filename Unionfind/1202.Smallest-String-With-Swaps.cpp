#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int findFather(int x){
        if(Father[x]!=x){
            Father[x]=findFather(Father[x]);
        }
        return Father[x];
    }
    
    void Union(int x, int y){
        x=Father[x];
        y=Father[y];
        if(x<y){
            Father[y]=x;
        }
        else{
            Father[x]=y;
        }
    }
    
    vector<int> Father;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        Father.resize(n);
        for(int i=0; i<n; i++){
            Father[i]=i;
        }
        for(auto pair : pairs){
            int a=pair[0];
            int b=pair[1];
            if(findFather(a)!=findFather(b)){
                Union(a, b);
            }
        }
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            m[findFather(i)].push_back(i);
        }
        for(auto x : m){
            string temp;
            for(auto idx : x.second){
                temp.push_back(s[idx]);
            }
            sort(temp.begin(), temp.end());
            
            int k=0;
            for(auto idx : x.second){
                s[idx]=temp[k];
                k++;
            }
        }
        return s;
    }
};

