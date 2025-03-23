# Approach for Generating All Valid IP Addresses

## Introduction
The given JavaScript function `GetAllValidIpAddress` generates all possible valid IP addresses from a given string of digits. It uses recursion and backtracking to form different combinations of valid IP addresses while ensuring that each segment adheres to the rules of an IP address.

## Algorithm Explanation

### 1. **Base Case (Stopping Condition)**
   - If we have reached the end of the `givenString` and formed exactly **4 segments** (`count == 4`), we remove the trailing dot and store the valid IP address in `result`.
   - If the `index` exceeds the string length before forming 4 segments, we return early.

### 2. **Recursive Case (Generating IP Segments)**
   - The function tries to create an IP address by selecting **1-digit, 2-digit, and 3-digit** segments sequentially.
   - It ensures that:
     - The segment does not start with '0' unless it is a single '0'.
     - The segment value does not exceed `255`.
   - After choosing a segment, the function recursively calls itself with an updated index and count.
   - The `ipAddress` string is updated by adding the new segment followed by a dot (`.`).
   
### 3. **Backtracking**
   - After each recursive call, we remove the last segment added (including the dot) to explore other possible valid IP addresses.
   
## Implementation Details

### **Function Signature**
```js
function GetAllValidIpAddress(result, givenString, index, count, ipAddress)
```
**Parameters:**
- `result`: Stores all valid IP addresses.
- `givenString`: The input string containing digits.
- `index`: The current position in the string.
- `count`: The number of segments formed so far.
- `ipAddress`: The current IP address being formed.

### **Steps in the Function:**
1. **Check if the IP address is complete:**
   - If `count == 4` and `index == givenString.length`, store the IP address (after removing the trailing dot).
   
2. **Generate segments:**
   - Try forming **1-digit, 2-digit, and 3-digit** segments.
   - Ensure segments do not start with `0` (unless they are exactly `0`).
   - Ensure 3-digit segments do not exceed `255`.
   
3. **Recursively call the function for the next segment:**
   - Append the selected segment to `ipAddress` and call `GetAllValidIpAddress` with updated `index` and `count`.
   
4. **Backtrack by removing the last added segment** before trying the next possible segment.

## Code Implementation
```js
function GetAllValidIpAddress(result, givenString, index, count, ipAddress) {
    if (givenString.length == index && count == 4) {
        ipAddress = ipAddress.substring(0, ipAddress.length - 1);
        result.push(ipAddress);
        return;
    }
    if (givenString.length < index + 1) return;
    
    ipAddress = ipAddress + givenString.substring(index, index + 1) + '.';
    GetAllValidIpAddress(result, givenString, index + 1, count + 1, ipAddress);
    ipAddress = ipAddress.substring(0, ipAddress.length - 2);
    
    if (givenString.length < index + 2 || givenString[index] == '0') return;
    ipAddress = ipAddress + givenString.substring(index, index + 2) + '.';
    GetAllValidIpAddress(result, givenString, index + 2, count + 1, ipAddress);
    ipAddress = ipAddress.substring(0, ipAddress.length - 3);
    
    if (givenString.length < index + 3 || parseInt(givenString.substring(index, index + 3)) > 255) return;
    ipAddress += givenString.substring(index, index + 3) + '.';
    GetAllValidIpAddress(result, givenString, index + 3, count + 1, ipAddress);
    ipAddress = ipAddress.substring(0, ipAddress.length - 4);
}

let givenString = "25525511135";
let result = [];
GetAllValidIpAddress(result, givenString, 0, 0, "");
for (let i = 0; i < result.length; i++) {
    console.log(result[i]);
}
```

## Example Execution
### **Input:**
```plaintext
"25525511135"
```
### **Valid Output:**
```plaintext
255.255.11.135
255.255.111.35
```

## Complexity Analysis
- Since we explore different segment combinations, the time complexity is approximately **O(3^4) = O(81)** because at each segment, we make up to 3 recursive calls and need exactly 4 segments.
- The space complexity is **O(4) = O(1)** for the recursion depth, plus **O(N)** for storing results.

## Conclusion
- This approach effectively generates all valid IP addresses using recursion and backtracking.
- The function ensures segment validity at each step, eliminating invalid possibilities early.
- Backtracking helps explore different segment combinations efficiently.

This method is useful in scenarios where we need to generate and validate structured formats from unstructured input.
