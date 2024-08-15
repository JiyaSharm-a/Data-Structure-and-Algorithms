class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;  // Counters for $5 and $10 bills
        
        for(int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                // Customer pays with a $5 bill, no change needed
                five++;
            } 
            else if (bills[i] == 10) {
                // Customer pays with a $10 bill, we need to give $5 as change
                if (five > 0) {
                    five--;  // Give $5 as change
                    ten++;   // Keep the $10 bill
                } else {
                    return false;  // Not enough $5 bills to give change
                }
            } 
            else if (bills[i] == 20) {
                // Customer pays with a $20 bill, we need to give $15 as change
                if (ten > 0 && five > 0) {
                    ten--;  // Give $10 as part of the change
                    five--; // Give $5 as the remaining part of the change
                } 
                else if (five >= 3) {
                    five -= 3;  // Give three $5 bills as change
                } 
                else {
                    return false;  // Not enough bills to give change
                }
            }
        }
        
        return true;  // Successfully provided change for all customers
    }
};
