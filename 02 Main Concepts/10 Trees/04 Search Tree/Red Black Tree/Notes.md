# Red-Black Tree

Definition:
A red-black tree is a binary search tree with an extra bit of storage per node: its color, which can be either red or black. The tree satisfies specific properties that ensure it remains approximately balanced.

Properties (Red-Black rules):
1. Each node is either red or black.
2. The root is black.
3. All NIL (leaf) nodes are considered black.
4. If a node is red, then both its children are black (no two red nodes in a row).
5. Every path from a node to its descendant NIL nodes has the same number of black nodes (black-height).

Consequences:
- The longest path is no more than twice the length of the shortest path, ensuring O(log n) height.

Insertion (high level):
- Insert the new node as red (BST insert).
- Fix violations of red-black properties using recoloring and rotations. Typical cases are handled based on the color of uncle node and structure.

Deletion (high level):
- Delete as in BST (replace with successor if needed).
- Fix double-black violations using rotations and recoloring; deletion cases are more complex than insertion.

Relation to 2-3-4 trees:
- Each node in a 2-3-4 tree can be represented by one or more nodes in a red-black tree (red links represent combining keys). Red-black trees are a binary-tree representation of 2-3-4 trees.

Advantages:
- Simpler to implement in many languages compared to B-trees for in-memory balanced search trees.
- Widely used in library data structures (e.g., C++ std::map, Java TreeMap).

Applications:
- Balanced associative containers, ordered maps, sets.

Notes:
- Insert and delete implementations rely on pattern matching of cases (uncle red/black, rotations, recoloring).
- For learning, step through insertion cases with diagrams or use an online visualizer.
