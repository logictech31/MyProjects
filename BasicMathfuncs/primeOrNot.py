# -*- coding: utf-8 -*-
"""
Created on Tue Apr  4 20:04:51 2023

@author: Hrush
"""

def prime(num):
    a = 0
    n = 0
    while 1:
        if((num / 10**n) == 0):
            break
        else:
            n = n + 1
            
    while n >= 0:
        a = a + num%10**n
        n = n-1
            
    print(a)
num = int(input("Enter a number to check if it is prime or not: "))
prime(num)