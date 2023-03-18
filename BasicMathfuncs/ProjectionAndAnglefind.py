import numpy as np
import math
#import pandas as pd

lst1 = [2, 2]
lst2 = [1, 3]

v1 = np.array(lst1)
v2 = np.array(lst2)

def VectorMod(a):
    res = 0
    for x in a:
        res = res + x**2
    res = math.sqrt(res)
    return res

# Projection is from a on b
def ScalarProjection(a, b):
    '''
    Formula for scalar projection is
    a.b
    ---
    |b|
    '''
    
    res = 0
    dotAB = np.dot(a, b)
    modB = VectorMod(b)
    res = dotAB/modB
    return res

def VectorProjection(a, b):
    modBSquar = 0
    '''
    # Formula for projection of A on B is 
    a.b
    --- . b
    |b|^2
    '''
    # we now calculate |b|^2
    for x in b:
        modBSquar = modBSquar + x**2
    # here we calculate a.b
    aDotB = np.dot(a, b)
    # here we calc a.b/|b|**2
    res = aDotB/modBSquar 
    # here we calc result above dotted with b
    res = np.dot(res, b)
    
    return res
    
def angleBetweenAB(a, b):
    try:
        dotProd = np.dot(a,b)
        print(dotProd)
        modA = VectorMod(a)
        print(modA)
        modB = VectorMod(b)
        print(modB)
        finMod = modA * modB
        theta = math.acos(dotProd/finMod)
        print("The Angle is: cos(", end='')
        print(theta, end='')
        print(") degrees")
    except ZeroDivisionError:
        print("Divide by zero error has occured!")
        return 1
    return 0

print(np.dot(v1, v2))
print(ScalarProjection(v1, v2))
print(VectorProjection(v1, v2))