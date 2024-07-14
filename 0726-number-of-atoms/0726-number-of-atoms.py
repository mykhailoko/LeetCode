class Solution:
    def countOfAtoms(self, formula: str) -> str:
        n = len(formula)
        stack = [Counter()]
        i = 0
        
        while i < n:
            if formula[i] == '(':
                stack.append(Counter())
                i += 1
            elif formula[i] == ')':
                cur_counter = stack.pop()
                i += 1
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                multiplier = int(formula[start:i] or 1)
                for atom in cur_counter:
                    stack[-1][atom] += cur_counter[atom] * multiplier
            else:
                start = i
                i += 1
                while i < n and formula[i].islower():
                    i += 1
                atom = formula[start:i]
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                count = int(formula[start:i] or 1)
                stack[-1][atom] += count
        
        counter = stack.pop()
        ans = ""
        for atom in sorted(counter):
            ans += atom
            if counter[atom] > 1:
                ans += str(counter[atom])
                
        return ans
