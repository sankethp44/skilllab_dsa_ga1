# Median in a BST (O(1) Space) - Approach

##  Problem Statement
Find the median of all nodes in a **Binary Search Tree (BST)** using **O(1) extra space**.

---

## **Approach to Solve the Problem**

### **1. Median in BST**
- The **median** is:
  - If `n` (total nodes) is **odd**, return the middle element.
  - If `n` is **even**, return the average of the two middle elements.
- **Inorder traversal** of a BST gives the elements in **sorted order**.

### **2. Morris Traversal**
- **Normal Inorder Traversal** requires `O(n)` extra space to store nodes.
- **Morris Traversal** allows **O(1) space traversal** by modifying links within the tree.
- It avoids recursion and stack usage, making it space-efficient.

---

## ** Morris Traversal **
Morris Traversal is an **inorder traversal technique** that temporarily modifies the tree to avoid using extra space.

### **Steps to Perform Morris Traversal:**
1. Start from the **root node**.
2. If the **left child is null**, print the current node and move to the **right child**.
3. If the **left child exists**:
   - Find the **inorder predecessor** (rightmost node in the left subtree).
   - If the predecessor’s **right pointer is null**, set it to the **current node** and move left.
   - If the predecessor’s **right pointer already points to the current node**, restore it to `null`, print the node, and move right.

### 
- The **inorder predecessor helps in backtracking** without using a stack.
- The tree structure is **temporarily modified** but restored after traversal.
- Each node is visited **twice** but only requires `O(1)` extra space.

---

## **3. Two Steps to Find the Median**
### **Step 1: Count Total Nodes (`n`)**
- Use **Morris Traversal** to count the total number of nodes in the BST.
- This helps in determining which element(s) form the median.

### **Step 2: Find the Median Using Morris Traversal**
- Perform **Morris Traversal again** to find the **middle element** (for odd `n`) or **two middle elements** (for even `n`).
- Stop at the required position(s) and return the median.

---

## 
- **Median in BST is found using sorted order (Inorder Traversal).**
- **Morris Traversal helps achieve O(1) space complexity.**
- **Requires two passes:**
  1. **First pass** to count nodes.
  2. **Second pass** to find the median efficiently.

---
