class Solution {
    public boolean check(String sentence1, String sentence2) {
        String[] a1 = sentence1.split(" ");
        String[] a2 = sentence2.split(" ");
        int start1 = 0;
        int end1 = a1.length - 1;
        int start2 = 0;
        int end2 = a2.length - 1;
        while(start1 < a1.length && start2 < a2.length && a1[start1].equals(a2[start2])) {
            start1++;
            start2++;
        }
        while(end1 >=0 && end2 >=0 && a1[end1].equals(a2[end2])) {
            end1--;
            end2--;
        }
        System.out.println(start1 + " " +  start2 + " " + end1 + " " + end2);
        return start1 > end1 || start2 > end2;
        
    }
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        return check(sentence1, sentence2) || check(sentence2, sentence1);
    }
}