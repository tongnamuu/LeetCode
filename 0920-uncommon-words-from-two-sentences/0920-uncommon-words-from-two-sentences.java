class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] first = s1.split(" ");
        String[] second = s2.split(" ");
        Map<String, Integer> a  = new HashMap<>();
        Map<String, Integer> b  = new HashMap<>();
        for(String s : first) {
            if(a.containsKey(s)) {
                a.put(s, a.get(s)+1);
            } else {
                a.put(s, 1);
            }
        }
        for(String s : second) {
            if(b.containsKey(s)) {
                b.put(s, b.get(s)+1);
            } else {
                b.put(s, 1);
            }
        }
        List<String> ans = new ArrayList<>();
        a.forEach((k,v) -> {
            if (v == 1 && !b.containsKey(k)) {
                ans.add(k);
            }
        });
        b.forEach((k,v) -> {
            if (v == 1 && !a.containsKey(k)) {
                ans.add(k);
            }
        });
        return ans.toArray(new String[0]);
    }
}