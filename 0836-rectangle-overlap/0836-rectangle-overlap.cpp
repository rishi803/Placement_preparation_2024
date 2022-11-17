class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1=rec1[0];
        int ay1=rec1[1];
        int ax2=rec1[2];
        int ay2=rec1[3];
        
        int bx1=rec2[0];
        int by1=rec2[1];
        int bx2=rec2[2];
        int by2=rec2[3];
        
        if(ax1<bx2 and bx1<ax2 and ay1<by2 and ay2>by1) return true;
        return false;
    }
};
