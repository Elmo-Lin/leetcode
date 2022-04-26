#include<vector>
#include<array>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int Father[1000];

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
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1){
            return 0;
        }
        //初始Father
        for(int i=0; i<n; i++){
            Father[i]=i;
        }
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push({dis, i, j});
            }
        }
        int result=0;
        int count=0;
        while(1){       
            auto edge=edges.top();
            edges.pop();
            int dis=edge[0];
            int a=edge[1];
            int b=edge[2];
            if (findFather(a)!=findFather(b)){
                Union(a,b);
                count++;
                result+=dis;
                if(count==n-1){
                    break;
                }
            }
        }
        return result;        
    }
};