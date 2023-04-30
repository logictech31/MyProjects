# -*- coding: utf-8 -*-
"""
Created on Wed Mar 22 12:37:40 2023

@author: Hrush
"""

import numpy as np
import math

lst = [1, 2]
v = np.array(lst)

def rotate2Dim(v):
    theta = input("By how many degrees do you want to rotate?")
    TransformMatrix = np.array([[int(math.cos(theta)), int(math.sin(theta))],
                               [-1 * int(math.sin(theta)), int(math.cos(theta))]])
    result = np.cross(TransformMatrix, v)
    print(result)

rotate2Dim(v)