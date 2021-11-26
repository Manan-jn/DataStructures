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
- [783. Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)
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
- [993. Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/)
```
Approach: Will first find the LCA of the two nodes and then we need to find the depth of each node from the node next to 
          the leaf node and if the depth of both sides are same then they are cousins otherwise not
           Bottom up approach: Found node will return its value and depth and will compare the depths from both sides
```
- [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
```
Approach: Will store the inorder traversal of the BST and will find the kth element in the vector that will be the kth 
          smallest element in the BST
```
- [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
```
Approach: Perform BST traversal on the tree and then update the next pointer of each node with the next node in the tree 
          or queue
```
- [1382. Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)
```
Approach: Will make the node of the middle value in the preorder traversal of the tree then will call on the left and right
          parts in the same manner
```
- [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
```
Approach: Will pick elements sequentially from the postorder traversal will make the node of it then will find the index 
          of that element in the inorder traversal and then will make a call on the right part with (index+1) as the 
          start and (e) as the end and with (s) and (index-1) on the left part of the root node
```
- [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
```
Approach -1: Will store the elements of the linked list sequentially and then will find the mid point of the vector and 
            will make the node out of that element and will call for the right child with start as (mid+1) and end as (e)
            and left child as the start as (s) and end as (mid-1) and then again find the middle element and make the node
            
            In this way the tree formed will be a height balanced tree
```
- [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)
```
Approach -1: Will store each node while traversing the tree in the vector and when we reach the leaf node then we will 
              calculate the number out of the number stored in the vector and then while moving backwards we will pop 
              elements out of the vector
              if the number equals the targetSum then will add that path to our answer
```
- [129. Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
```
Approach -1: Will store each node while traversing the tree in the vector and when we reach the leaf node then we will 
              calculate the number out of the number stored in the vector and then while moving backwards we will pop 
              elements out of the vector
              will maintain a running sum and add numbers into them once will reach the leaf node
```

