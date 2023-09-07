#!/usr/bin/env python3

import sys
import math
import os.path
import string
import numpy as np

p_blosum = None
p_verbose = 0
p_printall = 0
p_blosum_qij = None
p_beta = 0.11387
p_kmax = 30
p_kmin = 1
p_exself = 0

param = [
    ["-v", "VSWITCH", "p_verbose", "Verbose mode", "0"],
    ["-blf", "VFNAME", "p_blosum", "Blosum matrix filename", "/Users/annieborch/Documents/programs/Self_similarity/matrices/BLOSUM50"],
    ["-pa", "VSWITCH", "p_printall", "Print all against all score [default is best score only", "0"],
    ["-beta", "VFLOAT", "p_beta", "Hadamard power of blosum matrix", "0.11387"],
    ["-kmin", "VINT", "p_kmin", "Min value of k for k-mers", "1"],
    ["-kmax", "VINT", "p_kmax", "Max value of k for k-mers", "30"],
    ["-blqij", "VFNAME", "p_blosum_qij", "Blosum qij matrix filename", "/Users/annieborch/Documents/programs/Self_similarity/matrices/blosum62.qij"],
    ["-xs", "VSWITCH", "p_exself", "Exclude self", "0"]
]

# global variables
k1 = None

def fmatrix_k1(blm_qij):
    global k1
    k1 = np.zeros((20, 20))
    marg = np.zeros(20)

    # normalize matrix by marginal frequencies
    for j in range(20):
        sum = 0
        for k in range(20):
            sum += blm_qij[j][k]
        marg[j] = sum

    # calculate K1
    for j in range(20):
        for k in range(20):
            k1[j][k] = blm_qij[j][k] / (marg[j] * marg[k])
            k1[j][k] = math.pow(k1[j][k], p_beta)

    return k1

def k2_prod(s1, s2, start1, start2, k):
    k2 = 1.0
    for x in range(k):
        i1 = s1['i'][x + start1]
        i2 = s2['i'][x + start2]
        k2 *= k1[i1][i2]
    return k2

def k3_sum(s1, s2):
    k3 = 0.0
    l1 = s1['len']
    l2 = s2['len']

    for k in range(p_kmin, p_kmax + 1):
        for start1 in range(l1 - k + 1):
            for start2 in range(l2 - k + 1):
                prod = k2_prod(s1, s2, start1, start2, k)
                k3 += prod

    return k3

def read_blosummat_qij(filename):
    alphabet = [None] * 21
    mat = np.zeros((20, 20))

    with open(filename, 'r') as file:
        lines = file.readlines()

        for i, line in enumerate(lines):
            if i == 0:
                alphabet_str = line.strip().split()


                