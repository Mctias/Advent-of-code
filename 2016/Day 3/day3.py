import numpy as np

data = np.loadtxt('input.in')

def solve(arr):
    arr.sort(axis = 1)
    print(sum(np.sum(arr[:, :2], axis = 1) > arr[:, 2]))

   

if __name__ == '__main__':
    solve(data.copy())
    solve(data.T.reshape(-1, 3))