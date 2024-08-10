// class Solution {
//    public int lengthOfLongestSubstringTwoDistinct(String s) {


//        if(s.length() <= 2) {
//            return s.length();
//        }


//        Map<Character , Integer> map = new HashMap<>();
//        int ptr1 = 0;
//        int ans = 0;
//        for(int ptr2 = 0; ptr2 < s.length(); ptr2++) {


//            map.put(s.charAt(ptr2), map.getOrDefault(s.charAt(ptr2), 0) + 1);


//            if (map.size() <= 2) {
//                ans = Math.max(ans , ptr2 - ptr1 + 1);
//            } else {
//                while(map.size() != 2) {
//                    map.put(s.charAt(ptr1), map.get(s.charAt(ptr1)) - 1);


//                    if( map.get(s.charAt(ptr1)) == 0) {
//                        map.remove(s.charAt(ptr1));
//                    }
//                    ptr1++;
//                }
//            }
//        }
      
//        return ans;
//    }
// }