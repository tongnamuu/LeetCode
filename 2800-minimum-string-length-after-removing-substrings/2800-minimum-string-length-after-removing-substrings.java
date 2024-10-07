class Solution {
    
    public int minLength(String s) {
        Deque<Character> stack = new LinkedList<>();
        for(int i=0;i<s.length();i++) {
            Character c = s.charAt(i);
            if (stack.size() > 0 && ((c=='B' && stack.peekLast() == 'A') || (c=='D' && stack.peekLast() == 'C'))) {
                stack.pollLast();
            } else {
                stack.add(c);
            }
        }
        int ans = stack.size();
        return ans;
    }
}