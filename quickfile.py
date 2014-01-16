#!/usr/bin/python3

import os
import sys
import time

name = input("File name")

with open(name+".cpp","w") as after:
    after.writelines("//"+str(time.ctime())+"\n")
    after.writelines("//Author:Minshik\n")
    with open("template.cpp","r") as before:
        for each in before:
            after.writelines(each)





    
    
