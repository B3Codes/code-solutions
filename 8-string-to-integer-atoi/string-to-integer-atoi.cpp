class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();  // Get the size of the input string
        int res = 0;       // Variable to store the resulting integer
        bool negNum = false; // Flag to indicate if the number is negative

        int i = 0;

        // Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // Check the first non-space character
        int firstChar = s[i];

        // If the first character is '-', set negNum to true (negative number)
        if (firstChar == '-') {
            negNum = true;
        } 
        // If the first character is '+', just continue (positive number)
        else if (firstChar == '+') {
            negNum = false;
        } 
        // If the first character is not a digit or sign, return 0 (invalid input)
        else if (firstChar - '0' < 0 || firstChar - '0' > 9) {
            return 0;
        } 
        // If the first character is a valid digit, initialize the result with it
        else if (firstChar - '0' >= 0 && firstChar - '0' < 10) {
            res = firstChar - '0';
        }

        // Process the remaining characters
        for (i = i + 1; i < n; i++) {
            int digit = s[i] - '0'; // Convert current character to an integer digit

            // If the character is not a valid digit, stop processing
            if (digit < 0 || digit > 9) {
                break;
            }

            // If the number is negative
            if (negNum) {
                // Check for overflow when subtracting the digit
                if (res < (INT_MIN + digit) / 10) {
                    res = INT_MIN; // Set to INT_MIN if overflow occurs
                    break;
                } else {
                    res = res * 10 - digit; // Build the negative number
                }
            } 
            // If the number is positive
            else {
                // Check for overflow when adding the digit
                if (res > (INT_MAX - digit) / 10) {
                    res = INT_MAX; // Set to INT_MAX if overflow occurs
                    break;
                } else {
                    res = res * 10 + digit; // Build the positive number
                }
            }
        }

        // Return the result after processing all valid digits
        return res;
    }
};
