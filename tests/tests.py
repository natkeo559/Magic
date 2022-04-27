import pstats

'''
In this dir:
python3 -m cProfile -o ../tests/bench.data ../src/Vectorized_JIT_v1.py 

Then run this file.
'''

with open("profile.txt", "w") as f:
    p = pstats.Stats('bench.data', stream=f).strip_dirs()
    p.sort_stats('cumulative')
    p.print_stats()