# Binary Tree
## Leetcode
### Easy 
- [938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
```
Approach -1: Simple BST traversal of the binary tree and if we get the value between high and low will add to the
              sum and return sum
Approach -2: BFS traversal of the tree level by level and if we get the value between high and low will add to the
              sum and return sum
```
- [617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)
```
Approach: Traverse both the trees from root to bottom and when both of them are not NULL then add their values and
            if the root2 is NULL then return it
```
- [897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)
```
Approach: Store the inorder traversal of the tree in the vector and build the seperate tree from that vector and return it
```
- [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)
```
Approach: Will search in the BST according the to the current value, for value greater than root move to the right else
          move left and if found then return the root node
```
- [1022. Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
```
Approach: Will store elements in the vector everytime we move and when we reach the leaf node will calculate and add to the 
        running sum and will pop elements while moving back from the leaf node (backtracking)
```
- [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
```
Approach- Brute force: Store the inorder traversal of the tree and find the result using two pointers on the vector obtained
```



