# AVL Tree Notes

**Definition:**  
An AVL (Adelson-Velsky and Landis) tree is a self-balancing binary search tree (BST) where the difference in heights of left and right subtrees (the balance factor) of any node is at most 1.

**Properties:**
- Each node has a balance factor:  
  ```
  Balance Factor = Height of Left Subtree - Height of Right Subtree
  ```
- For every node, balance factor ∈ {–1, 0, 1}
- Height of AVL tree with n nodes: $O(\log n)$

**Rotations (to maintain balance):**
1. **LL Rotation** (Left-Left)
2. **RR Rotation** (Right-Right)
3. **LR Rotation** (Left-Right)
4. **RL Rotation** (Right-Left)

**Insertion:**
- Insert as in BST.
- Update heights and balance factors.
- If unbalanced, perform appropriate rotation.

**Deletion:**
- Delete as in BST.
- Update heights and balance factors.
- If unbalanced, perform appropriate rotation.

**Advantages:**
- Guarantees `O(log n)` time for search, insert, and delete.
- More balanced than a regular BST.

**Disadvantages:**
- Slightly more complex to implement due to rotations.

**Applications:**
- Databases and file systems where fast lookups, inserts, and deletes are required.
