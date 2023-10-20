int sz=height.size();
int mxleft=height[0];
int mxright=height[sz-1];
int left=1,right=sz-2;
int ans=0;
while(left<=right){
if(mxleft<mxright){       // water must store according to left height
if(height[left]>mxleft){
mxleft=height[left];
}
else {
ans += (mxleft-height[left]);
}
left++;
}
else{                    // water must store according to right height
if(height[right]>mxright){
mxright=height[right];
}
else{
ans += (mxright-height[right]);
}
right--;
}
}
return ans;