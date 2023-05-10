class Solution:
    def __init__(self):
        self.conditions: set[Condition] = set()
        self.chemicals:  set[Chemical]  = set()
    
    def update(self):
        for chem in self.chemicals:
            chem.update(self.chemicals, self.conditions)



class Condition:
    def __init__(self, name, value):
        self.name = name
        self.value = value
    
    def __repr__(self):
        return f"<{self.name}: {self.value}>"



class Chemical:
    def __init__(self, name, amount):
        self.name = name
        self.amount = amount
    
    def update(self, chems, conds):
        pass

    def __repr__(self):
        return f"<{self.name}: {self.amount}>"