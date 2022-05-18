#include <map>
#include <iostream>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
};

vector<point> vFirst;
vector<point> vSecond;
map<int, vector<point>> mMapVector;
int graph[50][50];
int visited[50][50] = {0};
int M,N;
int count = 1;

int distance(point first, point second)
{
    return (abs(first.x-second.x) + abs(first.y-second.y) - 1);
}

int processData()
{
    int result = 1000;
    for (auto i = 0;i<vFirst.size();i++)
    {
        for(auto j=0;j<vSecond.size();j++)
        {
            int tmp = distance(vFirst[i], vSecond[j]);
            result = result < tmp ? result : tmp;
        }
    }
    return result;
}

//only need find left, top point
void findNearPoint(point p)
{
    bool hasNearPoint = false;
    if (p.x == 0){ //only need find left
        if(p.y > 0) {
            if(graph[p.x][p.y-1] == 1) {
                hasNearPoint = true;
                int key = visited[p.x][p.y-1];
                visited[p.x][p.y] = key;
                mMapVector[key].push_back(p);
            }
        }
    } else {
        int key = -1;
        if(graph[p.x-1][p.y] == 1) {
            hasNearPoint = true;
            key = visited[p.x-1][p.y];
            visited[p.x][p.y] = key;
            mMapVector[key].push_back(p);
        }
        if(p.y > 0) {
            if(graph[p.x][p.y-1] == 1) {
                hasNearPoint = true;
                int otherKey = visited[p.x][p.y-1];
                if(key == -1)
                {
                    mMapVector[otherKey].push_back(p);
                    visited[p.x][p.y] = otherKey;
                }
                if( (key != -1) && (key != otherKey) )
                {
                    //need merge to paths;
                    vector<point> vTempPoint = mMapVector[otherKey];
                    for(auto i=0;i<vTempPoint.size();i++)
                    {
                        point tmpPoint = vTempPoint[i];
                        visited[tmpPoint.x][tmpPoint.y] = key;
                        mMapVector[key].push_back(tmpPoint);
                    }
                    mMapVector.erase(otherKey);
                }
            }
        }
    }
    if( hasNearPoint == false)
    {
        visited[p.x][p.y] = count;
        mMapVector[count].push_back(p);
        count ++;
    }
}

int main()
{
    cin>>N; //6
    cin>>M; //16
    for(auto r=0;r<N;r++)
    {
        for(auto c=0;c<M;c++)
        {
            cin >> graph[r][c];
            if( graph[r][c] == 1 )
            {
                point p;
                p.x = r;
                p.y = c;
                findNearPoint(p);
            }
        }
    }
    auto it =  mMapVector.begin();
    vFirst = it->second;
    it++;
    vSecond = it->second;
    cout<<processData();
    return 0;
}

