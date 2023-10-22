class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
  
  int leftSmall[n];
  int rightSmall[n];

  leftSmall[0] = -1; 
  rightSmall[n-1] = n;

  for(int i=1; i<n; i++) {
    int p = i-1;
    while(p >= 0 && heights[p] >= heights[i]) {
      p = leftSmall[p]; 
    }
    leftSmall[i] = p;
  }

  for(int i=n-2; i>=0; i--) {
     int p = i+1;
     while(p < n && heights[p] >= heights[i]) {
       p = rightSmall[p];
     }
     rightSmall[i] = p; 
  }

  int maxArea = 0;
  for(int i=0; i<n; i++) {
     maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] - 1)); 
  }

  return maxArea;
    }
};