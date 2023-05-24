class Thing:
    def __init__(self):
        self.name: str = ''
        self.conditions: set[Condition] = set()
        self.conditionals: set[Conditional] = set()

    def __repr__(self):
        return f"{{{type(self)}, {self.name}}}"


class Solution(Thing):
    def __init__(self):
        super().__init__()
        self.chemicals:  set[Chemical]  = set()
    
    def update(self):
        for chem in self.chemicals:
            chem.update(self.chemicals, self.conditions)


class Chemical(Thing):
    def __init__(self):
        super().__init__()
    

class Condition:
    def __init__(self, name, value):
        self.name = name
        self.value = value
    
    def __repr__(self):
        return f"<{self.name}: {self.value}>"


class Action:
    pass


class Conditional:
    pass