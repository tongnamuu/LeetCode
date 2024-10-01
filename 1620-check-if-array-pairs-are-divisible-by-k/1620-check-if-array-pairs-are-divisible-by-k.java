class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] cnt = new int[k];
        for(int i=0;i<arr.length;i++) {
            arr[i] = arr[i] % k;
            if (arr[i] < 0) arr[i] += k;
            cnt[arr[i]]++;
        }
        if(cnt[0]%2==1) {
            return false;
        }
        for(int i=1;i<k;i++) {
            if(cnt[i] != cnt[k-i]) {
                return false;
            }
        }
        return true;
    }
}