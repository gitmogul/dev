import sys
import os

'''
Will read the contents of the file and prints it our
if the file does not exist then it errors out
Note: exceptions are not handled"
'''
def print_file(file_name):
    my_file = open(file_name, "r")
    file_contents = my_file.read()

    file_contents = file_contents.split("\n")
    for line in file_contents:
        print(line)
    
    my_file.close()
    return

'''
Funtion will write <index>: 0123456789" 10 times to the file
if file already exists then it is trucated else a new file is 
created.
'''
def write_file(file_name):
    my_file = open(file_name, "w")

    for index in range(0,10):
        my_file.write(str(index) + ": 0123456789\n")

    my_file.close()
    return


def main():
    file_name = "demo.log"
    write_file(file_name)
    print_file(file_name)
    os.remove(file_name)
    return

main()
