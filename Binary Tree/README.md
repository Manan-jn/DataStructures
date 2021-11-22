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
Approach: Brute force: Store the inorder traversal of the tree and find the result using two pointers on the vector obtained
```
- [530. Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)
```
Approach: Brute force: Store the inorder traversal and then iterate over it to find the minimum absolute difference
Approach 2: Iterate over the tree in inorder fashion and keep track of the prev value and the min value encountered
            and find the minimum value in the tree
```
- [671. Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/)
```
Approach: Brute force: Store the inorder traversal of the tree inside the set stl and iterate over it to find the second min
          element in the tree
```

### Medium
- [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
```
Approach: Brute Force: Store the BFS traversal and the last most element in every level will appear in the right side view 
          so print the last most element in the bsf traversal (root->left->right)
          
Approach: Initialise a maxLevel pointer as -1 and move every level in the traversal of (root->right->left) and if we get the
          level which is greater than the maxLevel then will print that element and update maxLevel as level
```
- [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
```          
Approach -1: Set the min and max pointers for root node as INT_MIN and INT_MAX respectively and while moving to the nodes 
          update these pointers and check if the root->val is less than the maxPointer and greater than the minPointer then 
          return true otherwise false
          
Approach -2: Store the inorder traversal of the BST inside the vector and if we get the next element which is smaller than 
            or equal to the current element then return false and break the loop
            if(preorder[i]>=preorder[i+1]){
                return false and break the loop
            }
```
- [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
```
Approach: Perform BFS traversal on the tree and keep a pointer 'count' and update count after every level and if we get the
          count as even then reverse the current vector and push to the main ans otherwise just push original to the main
```



