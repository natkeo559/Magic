import numpy as np
import itertools as it

a = it.permutations((range(1, 10)))
b = np.fromiter(it.chain(*a), dtype=np.uint8).reshape(-1,3,3)

ma = np.array([15,15,15])

rs = np.all(np.sum(b.reshape(-1,3), axis=1).reshape(-1,3) == ma, axis=1)    #check row sums
cs = np.all(np.sum(b, axis=1) == ma, axis=1)                                #check col sums
ds = (np.trace(b, axis1=2, axis2=1) == 15)                                  #check diag sums
dr = (np.trace(np.flip(b,axis=1), axis1=2) == 15)                           #check flipped diag sums

i = rs & cs & ds & dr
r = b[i]

print(r)
print(np.where(i))