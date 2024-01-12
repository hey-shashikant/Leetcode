class Solution {
    public boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch
          == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
    public boolean halvesAreAlike(String s) {
        int cnt = 0;
        int i = 0, j = s.length()-1;
        while(i < j) {
            if(isVowel(s.charAt(i)))
                cnt += 1;
            if(isVowel(s.charAt(j))) 
                cnt -= 1;
            i += 1;
            j -= 1;
        }
        if(cnt == 0) 
            return true;
        return false;
    }
}