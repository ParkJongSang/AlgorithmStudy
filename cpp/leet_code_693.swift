class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = "";
        bool ret = true;
        int num = n;
        
        while(num > 0) {
            char bit = (num%2) + '0';
            binary = bit + binary;
            num /= 2;
        }
        
        for(int i = 0; i < binary.size()-1; i++) {
            if(binary[i] == binary[i+1]) {
                ret = false;
                break;
            }
        }
        
        return ret;
    }
};
