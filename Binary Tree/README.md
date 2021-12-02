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
- [117. Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)
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
- [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/)
```
Approach -1: Will do the BFS traversal on the tree and when we get the next level or NULL in the queue it means the 
            previous level is over and first element in the queue at this point will be the bottom left element...
```
- [1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
```
Approach -1: Will do the BFS traversal and with each level will maintain its sum, maxSum and the level with the maxSum
             Return the level after the traversal is over...
```
- [1339. Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)
```
Approach -1: Will first store the total sum of the tree and then will do the DFS traversal on the tree, at every node 
            will do the max of three posibilities, will split the tree in 3 parts by that current node. 
            3 cases:
            Case 1: If we take the upper part and below as one
            Case 2: If we take left and other part
            Case 3: If we take right and the other part
            Will do the max of these cases at every node while moving from the bottom (BOTTOM UP TRAVERSAL)
            Will keep returning the sum of the subtrees from the bottom nodes
```
- [1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
```
Approach -1: Will do the BFS traversal on the complete tree and will calculate the sum everytime after the current 
            level has ended (NULL) and will maintain a pointer to keep a track of the current level and will update it if 
            we find some level which is having greater sum of values than the previous level
```
- [1038. Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)
```
Approach -1: Will store the inorder traversal of the tree along with their nodes inside a vector of pair and then we have
              to replace every current node with the sum of the nodes following them
```
- [331. Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)
```
Approach -1: Will maintain a stack and will push -1 as indicator of NULL everytime we encounter a positive value and will pop
            once when we encounter '#' and incase of poping the stack is empty then it means this preorder cannot be possible 
            and the count of '#' should be less than the stack size at the end of the complete traversal
```
- [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)
```
Approach -1: Will return the sum everytime from the leaf node and will store that sum inside the map, will maintain the count
              of every sum and then at last will return the sum with max counts.
```
- [515. Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)
```
Approach -1: Will do the level order traversal BFS on the tree and store every level inside the vector and when the current 
              level is over we will check for the maximum value and will store that value inside our answer and at the end
              return the ans
```
- [1305. All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)
```
Approach -1: Brute Force: Will store the inorder traversal of both the trees and merge them into a single vector and then sort the result 
              vector and return
```
- [1302. Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)
```
Approach -1: Will do the level order traversal BFS of the tree and will maintain the sum pointer which will store the sum of the current
            level and at the last level our sum will store the sum of the last level so will return it in the end
```
- [1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)
```
Approach -1: Will do the preorder traversal of both the trees and once we get both trees same value of the node will return the address
             of the cloned tree in the answer
```
- [1315. Sum of Nodes with Even-Valued Grandparent](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)
```
Approach -1: Will do the preorder traversal of the tree and when our root value is even then will use the same technique we use to print
            kth level in the binary tree and will use this approach to store the sum of all the nodes at that level
```
- [1104. Path In Zigzag Labelled Binary Tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)
```
Approach -1: First will calculate the height of that tree based on the 'label' provided to us and then we need to calculate the difference
            of the 'label' node from the first node in every level and will move up in every level by reducing the diff by half (diff/2)
            Will use different formulas based on whether the height is even or odd
```
- [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
```
Approach -1: Will do the traversal starting from the left and right node in the tree 
             Will move left in the tree corresponding to the leftNode and will be moving right corresponding to the rightNode in the tree
             Will move right in the tree corresponding to the leftNode and will be moving left corresponding to the rightNode in the tree
             And at any point we found that both traversals value is not equal then will return false and break
```
- [1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)
```
Approach -1: Will store every root to leaf path and will then traverse by finding the greatest difference between nodes (O(N^2) approach)
             and will keep a variable which will maintain the maxiumum difference encountered so far
             return that variable in the end
```


## Geeks for Geeks
### Medium

- [Top View of a tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
```
Approach -1: Store the position of the nodes along with the node just like in the we do in the BFS
              traversal and will iterate over the min position in the left and max position in the 
              right to get the desired output
              
          If the tree is like this then 
              1
             / \  
            2   3           (1,0) (2,-1),(3,1) (4,-2),(5,0),(6,0),(7,2) will be the BFS traversal
           /\  /\
          4  5 6 7
```
- [Bottom View of Binary Tree](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)
```
Approach -1: Will do the BFS Traversal of the binary tree and will assign levels to each node with
              respect to the root node, elements moving in the right will having levels increasing
              and levels moving left will have decreasing levels
              Will do the BFS traversal of the tree from left to right
              Create a map of a key and a vector of the elements and will store the elements in that
              
                      20
                    /    \              If we have tree like this 
                  8        22           (20,0) (8,-1),(22,1) (5,-2)(3,0)(4,0)(25,2) (10,-1) (14,1)
                /   \     /   \         Store them in the map and print out the last element of each 
              5      3   4     25       key
                     /    \             
                   10      14

```
- [Check for Balanced Tree](https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#)
```
Approach -1:  If we do compare heights of the left and right subtree at every level then it will take
              O(N^2) time complexity which is very bad
              
Approach -2:  We can do bottom up approach also, in the previous case computing the height at every node
            was taking extra "N" time complexity we can minimise by returning a pair of height and balance
            from every node from bottom, if we get the height difference as less than 1 will make balance
            true and return
            This will take complexity of O(N) 

```


