import numpy as np
import itertools as it

a = it.permutations((range(1, 10)))
b = np.fromiter(it.chain(*a), dtype=np.uint8).reshape(-1,3,3)

ma = np.array([15,15,15])

rs = np.sum(b.reshape(-1,3), axis=1).reshape(-1,3) #row sums
cs = np.sum(b, axis=1) #col sums
ds = np.trace(b, axis1=2, axis2=1) #diag sums
dr = np.trace(np.flip(b,axis=1), axis1=2) #diag flipped sums

i = np.all(rs == ma, axis=1) & np.all(cs == ma, axis=1) & (ds == 15) & (dr == 15)
r = b[i]

print(r)
print(np.where(i))