class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        if not root:
            return 0
        self.good_pairs = 0
        self.postorder(root, distance)
        return self.good_pairs
    
    def postorder(self, node, distance):
        if not node:
            return []
        if not node.left and not node.right:
            return [1]
        l_leaf_dists = self.postorder(node.left, distance)
        r_leaf_dists = self.postorder(node.right, distance)
        
        for l_dist in l_leaf_dists:
            if l_dist >= distance:
                continue
            for r_dist in r_leaf_dists:
                self.good_pairs += 1 if l_dist + r_dist <= distance else 0
                
        return [1 + dist for dist in l_leaf_dists + r_leaf_dists]
