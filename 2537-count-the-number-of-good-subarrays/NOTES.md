```
int head = 0, tail = 0 , n = nums.size();
unordered_map<int,int> mp;
long long int cnt = 0 , ans = 0;
for(head=0;head<nums.size();head++){
cnt += mp[nums[head]]  ;        // calculating subarrays
mp[nums[head]]++;
// ------------- if(cnt>=k go inside while loop) -----  (this right part will also be our answer since it also satisfy cnt>=k, inside while loop shift tail pointer forward to check whether it still satisfying the cnt>=k then left part is the answer but right remaining part will also contribute to the answer)
while(tail < head and cnt >= k){
ans += n - head;
mp[nums[tail]]--;
cnt -= mp[nums[tail]];          // decrementing subarrays
tail++;
}
}
return ans;
```