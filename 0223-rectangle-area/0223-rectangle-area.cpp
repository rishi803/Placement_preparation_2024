class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int rec1=(ax2-ax1)*(ay2-ay1);
        int rec2=(bx2-bx1)*(by2-by1);
      
        // not overlap
        if(ax1>=bx2 or ax2<=bx1 or by1>=ay2 or by2<=ay1 )
        return rec1+rec2;
        // if overlap
        return (rec1+rec2-((min(ax2,bx2)-max(bx1,ax1))*((min(ay2,by2))-max(ay1,by1))));
    }
};

