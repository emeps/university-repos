import numpy as np

A = np.array([
    [4., -1., 0., 0., 0., -1., 0., 0., 0., 0.],
    [-1., 4., -1., 0., 0., 0., -1., 0., 0., 0.],
    [0., -1., 4., -1., 0., 0., 0., -1., 0., 0.],
    [0., 0., -1., 4., -1., 0., 0., 0., -1., 0.],
    [0., 0., 0., -1., 4., -1., 0., 0., 0., -1.],
    [-1., 0., 0., 0., 0., 4., -1., 0., 0., 0.],
    [0., -1., 0., 0., 0., -1., 4., -1., 0., 0.],
    [0., 0., -1., 0., 0., 0., -1., 4., -1., 0.],
    [0., 0., 0., -1., 0., 0., 0., -1., 4., -1.],
    [0., 0., 0., 0., -1., 0., 0., 0., -1., 4.]
])

b = np.array([0., 0., 0., 0., 0., 1., 1., 1., 1., 1.])


def gaussseidel(mat_coeff, mat_ind):
    # vec_sol = np.random.rand(10)
    vec_sol = [0,0,0,0,0,0,0,0,0,0]

    err = np.inf
    while err >= 1e-15:
        xk = np.array(vec_sol[:])

        for i in np.arange(mat_ind.size):
            vec_sol[i] = (- np.dot(mat_coeff[i, :i], vec_sol[:i])
                          - np.dot(mat_coeff[i, i+1:], xk[i+1:]) + mat_ind[i])/mat_coeff[i, i]

        err = np.linalg.norm(vec_sol - xk, np.inf)/np.linalg.norm(vec_sol, np.inf)

    return vec_sol


x = gaussseidel(A, b)
for i in x:
        print('------------------')
        print(i)
print('------------------') 

