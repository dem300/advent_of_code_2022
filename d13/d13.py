import json

def cmp(a, b):
    if isinstance(a, int) and isinstance(b, int):
        return b - a
    if isinstance(a, int) and isinstance(b, list):
        return cmp([a], b)
    if isinstance(a, list) and isinstance(b, int):
        return cmp(a, [b])
    if isinstance(a, list) and isinstance(b, list):
        for aa, bb in zip(a, b):
                r = cmp(aa, bb)
                if r != 0:
                    return r
        return len(b) - len(a)
    
    assert False

p1 = 0
num_smaller = [0, 0]
for i, pair in enumerate(open("input.txt").read().strip().split("\n\n")):
    a, b = [json.loads(s.strip()) for s in pair.split("\n")]
    if cmp(a, b) > 0:
        p1 += i + 1
    for o in (a, b):        
        num_smaller[0] += 1 if cmp(o, [[2]]) > 0 else 0
        num_smaller[1] += 1 if cmp(o, [[6]]) > 0 else 0

print(p1)
print((num_smaller[0] + 1) * (num_smaller[1] + 2))