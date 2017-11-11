#!/usr/bin/env python
# -*- coding:utf8 -*-

import math

def cos(a):
    return math.cos(a*math.pi/180.)

def sin(a):
    return math.sin(a*math.pi/180)

def cot(a):
    return cos(a)/sin(a)

def acot(a):
    return math.atan(1.0/a) / math.pi * 180

def main():
    v = sin(80)*sin(40)/sin(60)/sin(30)
    v = v/sin(10)-cot(10)
    v = 1.0/v
    print math.atan(v) / math.pi * 180

print acot(cot(10) * (4/math.sqrt(3)*sin(40)-1))

print sin(80)*sin(40)/(sin(60)*sin(30)*sin(10)) - cot(10) - cot(20)

