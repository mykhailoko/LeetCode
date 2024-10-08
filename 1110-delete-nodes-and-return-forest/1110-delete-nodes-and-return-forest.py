class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        to_delete = set(to_delete)
        res = []
        
        def dfs(node, is_root):
            if not node:
                return None
            
            root_deleted = node.val in to_delete
            if is_root and not root_deleted:
                res.append(node)
            
            node.left = dfs(node.left, root_deleted)
            node.right = dfs(node.right, root_deleted)
            
            return None if root_deleted else node
        
        dfs(root, True)
        return res
