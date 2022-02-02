import itertools

N = list(map(int, open('input.in').read().strip().split('\n')))

tot = 0

for i in range(len(N) + 1):
    for c in itertools.combinations(N, i):
        if sum(c) == 150 and len(c) == 4:
            print(c)
            tot+=1

print(tot)