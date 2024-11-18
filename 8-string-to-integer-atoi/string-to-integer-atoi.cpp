class Solution {
public:
    int myAtoi(string s) {
        // int n = s.size();  // Get the size of the input string
        // int res = 0;       // Variable to store the resulting integer
        // bool negNum = false; // Flag to indicate if the number is negative

        // int i = 0;

        // // Skip leading whitespaces
        // while (s[i] == ' ') {
        //     i++;
        // }

        // // Check the first non-space character
        // int firstChar = s[i];

        // // If the first character is '-', set negNum to true (negative number)
        // if (firstChar == '-') {
        //     negNum = true;
        // } 
        // // If the first character is '+', just continue (positive number)
        // else if (firstChar == '+') {
        //     negNum = false;
        // } 
        // // If the first character is not a digit or sign, return 0 (invalid input)
        // else if (firstChar - '0' < 0 || firstChar - '0' > 9) {
        //     return 0;
        // } 
        // // If the first character is a valid digit, initialize the result with it
        // else if (firstChar - '0' >= 0 && firstChar - '0' < 10) {
        //     res = firstChar - '0';
        // }

        // // Process the remaining characters
        // for (i = i + 1; i < n; i++) {
        //     int digit = s[i] - '0'; // Convert current character to an integer digit

        //     // If the character is not a valid digit, stop processing
        //     if (digit < 0 || digit > 9) {
        //         break;
        //     }

        //     // If the number is negative
        //     if (negNum) {
        //         // Check for overflow when subtracting the digit
        //         if (res < (INT_MIN + digit) / 10) {
        //             res = INT_MIN; // Set to INT_MIN if overflow occurs
        //             break;
        //         } else {
        //             res = res * 10 - digit; // Build the negative number
        //         }
        //     } 
        //     // If the number is positive
        //     else {
        //         // Check for overflow when adding the digit
        //         if (res > (INT_MAX - digit) / 10) {
        //             res = INT_MAX; // Set to INT_MAX if overflow occurs
        //             break;
        //         } else {
        //             res = res * 10 + digit; // Build the positive number
        //         }
        //     }
        // }

        // // Return the result after processing all valid digits
        // return res;

        // Initialize necessary variables
int n = s.size();      // The length of the input string 's'
int i = 0;             // Pointer 'i' to traverse the string
int res = 0;           // Variable to store the final integer result
bool negNum = false;   // Flag to track whether the number is negative

// Step 1: Skip leading whitespaces
// We loop through the string and move 'i' forward until we encounter a non-space character.
while (i < n && s[i] == ' ') {
    i++;  // Increment 'i' to skip spaces
}

// Step 2: Handle sign (if any)
// Check if the current character is a '-' or '+', which would indicate the sign of the number.
if (i < n && (s[i] == '-' || s[i] == '+')) {
    negNum = (s[i] == '-');  // If '-' is found, set 'negNum' to true, else it remains false for positive
    i++;  // Increment 'i' to move past the sign character
}

// Step 3: Process the digits
// We process each character while it is a digit (i.e., '0' to '9').
// The loop terminates once we encounter a non-digit character.
while (i < n && isdigit(s[i])) {
    int digit = s[i] - '0';  // Convert the current character (digit) to its integer value
    
    // Overflow check for negative numbers
    if (negNum) {
        // If the result will overflow when multiplied by 10 and subtracting the digit, return INT_MIN
        if (res < (INT_MIN + digit) / 10) {
            return INT_MIN;  // Underflow condition, return the minimum 32-bit integer value
        }
        res = res * 10 - digit;  // Update result for negative number (multiply by 10 and subtract digit)
    } else {
        // Overflow check for positive numbers
        if (res > (INT_MAX - digit) / 10) {
            return INT_MAX;  // Overflow condition, return the maximum 32-bit integer value
        }
        res = res * 10 + digit;  // Update result for positive number (multiply by 10 and add digit)
    }
    i++;  // Move to the next character in the string
}

// Step 4: Return the final result
// The result is stored in 'res' which has been updated through the process of accumulating the digits
return res;

    }
};
