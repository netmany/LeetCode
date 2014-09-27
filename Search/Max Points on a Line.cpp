/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    struct dir {
        int dx;
        int dy;
        dir(int a, int b) : dx(a), dy(b) {}
    };
    int cmp(dir a, dir b){
        return a.dx * b.dy - a.dy * b.dx;
    }
    void qsort(vector<dir> &temp, int begin, int end){
        if(end - begin < 2) return;
        int p = begin + 1;
        for(int i = begin + 1; i < end; i++){
            if(cmp(temp[i], temp[begin]) < 0){
                dir t = temp[p]; temp[p] = temp[i]; temp[i] = t;
                p++;
            }
        }
        dir t = temp[p - 1]; temp[p - 1] = temp[begin]; temp[begin] = t;
        qsort(temp, begin, p - 1);
        qsort(temp, p, end);
        
    }
    int getMaxSame(vector<dir> &temp){
        int m = 0, begin = 0, end = 0;
        while(end < temp.size()){
            while(end < temp.size() && 0 == cmp(temp[end], temp[begin])) end++;
            m = max(m, (end - begin));
            begin = end;
        }
        return m;
    }
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) return 0;
        int m = 0;
        vector<vector<dir> > d;
        for(int i = 0; i < points.size(); i++){
            vector<dir> t;
            for(int j = 0; j < points.size(); j++){
                t.push_back(dir(points[i].x - points[j].x, points[i].y - points[j].y));
            }
            d.push_back(t);
        }
        for(int i = 0; i < points.size(); i++){
            vector<dir> temp;
            int nCoin = 0;
            for(int j = 0; j < points.size(); j++){
                if(i == j) continue;
                if(d[i][j].dx == 0 && d[i][j].dy == 0) nCoin++;
                else temp.push_back(d[i][j]);
            }
            
            qsort(temp, 0, temp.size());
            m = max(m, nCoin + getMaxSame(temp));
        }
        return m + 1;
            
    }
};
