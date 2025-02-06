# AVL Tree

A **Self-Balancing AVL Tree** is a type of **Binary Search Tree (BST)** that maintains its height balanced using rotations. It follows these properties:

1. **BST Properties**:
   - Left subtree contains only nodes with values smaller than the node’s value.
   - Right subtree contains only nodes with values greater than the node’s value.
   - No duplicate values (typically).

2. **Balance Factor**:
   - The difference in height between the left and right subtrees of any node is at most **1**.
   - If the tree becomes unbalanced after an insertion or deletion, it is rebalanced using rotations:
     - **Single Right Rotation (LL case)**
     - **Single Left Rotation (RR case)**
     - **Left-Right Rotation (LR case)**
     - **Right-Left Rotation (RL case)**

## How to Compile and Run

1. In the project directory, compile the code with:
   ```sh
   gcc -o main *.c
   ```
2. Then, run:
   ```sh
   ./main
   ```

## How to Run Tests

1. With the project already compiled, run:
   ```sh
   ./main < in.test > out.test
   ```
2. To compare the expected output with the generated output, use:
   ```sh
   diff expected.test out.test
   ```
   - If no output is displayed, all tests have passed.


