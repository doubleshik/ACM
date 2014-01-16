#!/usr/bin/python3

import os
import sys
import time


'''快速建立一个文件夹并且新建A-I的题目模板'''

name = input("DIR name")
os.mkdir("./"+name)
os.chdir("./"+name+'/')
num = ['A','B','C','D','E','F','G','H','I','J']

for name in num:
    with open(name+".cpp","w") as after:
        after.writelines("//"+str(time.ctime())+"\n")
        after.writelines("//Author:Minshik\n")
        with open("../template.cpp","r") as before:
            for each in before:
                after.writelines(each)





    
    
