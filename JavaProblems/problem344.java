// 1 ms runtime 49.59 Mb

class Solution {
    public void reverseString(char[] s) {
        reverseString(s.length - 1, 0, s);
    }

    private void reverseString(int last, int first, char[] s){
        if(first < last){
            char temp = s[first]; 
            s[first] = s[last];
            s[last] = temp;
            reverseString(last - 1, first + 1, s);
        }
    }
}