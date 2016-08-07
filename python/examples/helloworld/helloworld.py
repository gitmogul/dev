#!/usr/bin/python

import sys

'''
Lets go with C style main ....
'''
def main( cmd_line_args_list ):
    if( len( cmd_line_args_list ) > 1 ):
        print( cmd_line_args_list[1] )
    else:
        print( "Hello World......." );
    return;

'''
The function where life begins...
'''
main(sys.argv);
