import numpy as np
import numba as nb
import itertools as it

a = it.permutations((range(1, 10)))
b = np.fromiter(it.chain(*a), dtype=np.uint8).reshape((-1, 9))

@nb.njit(fastmath=True, locals={'t':nb.b1}, nogil=True, cache=True)
def check(arr: np.ndarray) -> bool:
    t = (np.array([arr[0], arr[0], arr[0], arr[1], arr[2], arr[3]]) + 
         np.array([arr[1], arr[3], arr[4], arr[4], arr[4], arr[4]]) + 
         np.array([arr[2], arr[6], arr[8], arr[7], arr[6], arr[5]]) == 15).all()
    return t

@nb.njit(fastmath=True, locals={'d':nb.int32, 'i':nb.int32}, nogil=True)
def main() -> None:
    for i in range(len(b) // 2):
        c = b[i]
        d = 362879 - i
        if check(c):
            print(i)
            print(c.reshape(3,3), '\n')
            
            print(d)
            print(b[d].reshape(3,3), '\n')
            
main()