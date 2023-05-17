import sympy
import math

primes = list(sympy.primerange(1000))

gen_to_list = lambda fun: (lambda *args, **kwargs: list(fun(*args, **kwargs)))
def as_count(fun):
    def new_fun(*args, **kwargs):
        data = fun(*args, **kwargs)
        count = {}
        for i in data:
            count[i] = count.get(i, 0)+1
        return count
    return new_fun

@as_count
@gen_to_list
def factors(n):
    j = 2
    while n > 1:
        for i in range(j, int(math.sqrt(n+0.05)) + 1):
            if n % i == 0:
                n //= i ; j = i
                yield i
                break
        else:
            if n > 1:
                yield n; break

def improvement(layout, num):
    facts = factors(num)
    for fact, count in facts.items():
        if count > 2**layout.get(fact, 0)-1:
            return fact
    return -1

def best_layout(layout: dict[int:int], size):
    space_taken = sum(layout.values())
    if space_taken == size:
        return layout

    num = 1
    while improvement(layout, num) == -1:
        num += 1
    factor = improvement(layout, num)
    layout[factor] = layout.get(factor, 0)+1

    return best_layout(layout, size)

for i in range(1, 65):
    print(best_layout({}, i))