class CustomStack {
    private final int[] a;
    private int size;

    public CustomStack(int maxSize) {
        a = new int[maxSize];
        size = 0;    
    }
    
    public void push(int x) {
        if(a.length <= size) {
            return;
        }
        a[size] = x;
        size++;
    }
    
    public int pop() {
        if(size==0) {
            return -1;
        }
        int result = a[size-1];
        size--;
        return result;
    }
    
    public void increment(int k, int val) {
        for(int i=0;i<Math.min(size, k);i++) {
            a[i] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */