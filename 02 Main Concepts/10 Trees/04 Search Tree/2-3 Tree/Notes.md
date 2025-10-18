# 2-3 Tree

Definition:
A 2-3 tree is a balanced search tree where every internal node has either 2 or 3 children (and 1 or 2 keys). All leaves are at the same depth.

Properties:
- Each internal node can be either a 2-node (one key, two children) or a 3-node (two keys, three children).
- All leaves are at the same level (perfectly balanced).
- Search, insertion, and deletion take O(log n) time.

Insertion (high level):
- Insert as you would in a leaf by adding the key to a leaf node.
- If a node overflows (becomes a 4-node), split it into two nodes and push the middle key up to the parent.
- If the parent also overflows, continue splitting up to the root; splitting the root increases tree height by one.

Deletion (high level):
- Delete at leaf or internal node (replace with predecessor/successor then delete at leaf).
- If deletion causes underflow (node with 0 keys), try to borrow from sibling (rotation/redistribution).
- If borrowing is not possible, merge with a sibling and pull down a key from the parent; this may cascade.

Advantages:
- Maintains perfect balance, guaranteeing O(log n) operations.
- Simpler conceptually than some balanced trees.

Use cases and notes:
- 2-3 trees are historically important and help explain B-trees and 2-3-4 trees.
- They are not commonly used directly in production; B-trees and red-black trees are preferred.

Examples:
- Insert sequence and splits: Start with empty, insert 10, 20, 30 -> causes split into two nodes with new root.
