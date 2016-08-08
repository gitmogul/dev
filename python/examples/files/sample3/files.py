import sys
import os
import time

'''
Will read the contents of the file and prints it out
Note: exceptions are not handled"
'''
def print_file(file_name):
    my_file = open(file_name, "rb")

    by = my_file.read(8096)
    while(len(by) > 0):
        for byte in by:
            print("%02x" % byte, " ", end="")
        by = my_file.read(8096)
    print("\n")
    my_file.close()
    return

'''
Funtion will <index>: 0123456789" 10 times to the binary file
if file already exists then it is truncated else a new file is 
created.
'''
def write_file(file_name):
    my_file = open(file_name, "wb")

    by = bytearray(256)
    for digit in range(0,len(by)):
        by[digit] = digit
    my_file.write(by)
    
    my_file.close()
    return


def main():
    file_name = "output.log"
    write_file(file_name)
    print_file(file_name)
    os.remove(file_name)
    return

main()
