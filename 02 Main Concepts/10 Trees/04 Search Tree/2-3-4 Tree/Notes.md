# 2-3-4 Tree (a.k.a. B-tree of order 4)

Definition:
A 2-3-4 tree is a type of B-tree where each internal node can have 2, 3, or 4 children (and 1, 2, or 3 keys). It's height-balanced and all leaves are at the same level.

Properties:
- Nodes can contain 1, 2, or 3 keys.
- Corresponding children counts are 2, 3, or 4 respectively.
- Maintains perfect balance; search/insert/delete in O(log n).

Insertion (high level):
- Insert by finding the leaf where the key should go.
- Before descending into a node, if it is a 4-node (3 keys), split it into two 2-nodes and move the middle key up to the parent. This guarantees that when you reach the leaf, it's not full.
- Insert into a leaf node (which now has space).

Deletion (high level):
- Delete from a leaf or replace internal with predecessor/successor then delete from leaf.
- If a child node becomes a 0-key underflow, perform rotation (steal) from siblings or merge with sibling and pull down a key from the parent.
- Handle cascading merges up to the root; root may shrink in height.

Relation to red-black trees:
- 2-3-4 trees can be simulated by red-black trees (each 2-3-4 node maps to 1-3 red-black nodes).

Advantages:
- Simple splitting rules during insertion (split on the way down makes implementation easier).
- Good for on-disk B-tree variants and databases.

Examples:
- Insert sequence with splits: Insert to fill a node to 3 keys, then split when necessary.
