import numpy as np
import cupy as cp

x_gpu = cp.asarray([[0, 1, 2],[3,4,5],[6,7,8]])
y_gpu = cp.asarray([[1, 1, 1],[1,1,1],[1,1,1]])

z_gpu = x_gpu + y_gpu

print(z_gpu)