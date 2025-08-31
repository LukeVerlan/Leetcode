// 1 MS runtime 


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numeral_map;
        numeral_map.insert({'I',1});
        numeral_map.insert({'V',5});
        numeral_map.insert({'X', 10});
        numeral_map.insert({'L', 50});
        numeral_map.insert({'C', 100});
        numeral_map.insert({'D', 500});
        numeral_map.insert({'M', 1000});

        int total = 0; 
        for(int i = 0; i < s.length(); i++) {
            char rom_num = s[i];
            int num = numeral_map[rom_num];

            if(i == s.length() - 1) {
                total += num;
            } else {
                int next_num = numeral_map[s[i+1]];
                if(num >= next_num) {
                    total += num; 
                } else {
                    total -= num;
                }
            }
        }

        return total; 
    }


};