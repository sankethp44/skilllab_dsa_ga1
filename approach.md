# Triplet Sum in an Array - Approach

- I referred to GeekforGeeks to solve this problem

##  Problem Statement
Given an array of `n` integers and a target sum `X`, find all unique triplets `(arr[i], arr[j], arr[k])` such that: `arr[i] + arr[j] + arr[k] = X`

---

##  **Approach to Solve the Problem**

### **1. Sorting the Array (Why?)**
- Sorting helps in applying an **efficient two-pointer technique**.
- It makes it easier to skip duplicate triplets.

### **2. Fix One Element at a Time**
- Loop through the array, **fixing one element** (`arr[i]`).
- The remaining two elements should sum to `X - arr[i]`.

### **3. Use Two Pointers to Find the Remaining Two Elements**
- After fixing `arr[i]`, use:
  - **Low Pointer (`low`)** → Starts from `i + 1`.
  - **High Pointer (`high`)** → Starts from the last index.
- Check the sum:
  - If **equal to `X`**, add it as a valid triplet.
  - If **less than `X`**, increase `low` to get a higher sum.
  - If **greater than `X`**, decrease `high` to get a lower sum.

### **4. Handle Duplicate Elements**
- If `arr[i]` is the same as `arr[i-1]`, skip it to avoid duplicate triplets.
- Similarly, after finding a triplet, **move past duplicate values**.

---




