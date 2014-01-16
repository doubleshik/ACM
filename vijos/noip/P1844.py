try :
    file = open("in.txt")
except (IOError,OSError) as err:
    print(err)
finally:
    print("wrong")


