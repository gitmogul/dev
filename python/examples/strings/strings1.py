import sys;


'''
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
'''
def PrintChars( myString ):
    for char in myString:
        print( char, end='' );
    # print an end line of line after all chars are printed
    print( end = '\n' )
    return;


'''
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
'''
def PrintCharsByIndex( myString ):
    for index in range( 0, len(myString) ):
        print( myString[index], end='' );
    # print an end line of line after all chars are printed
    print( end = '\n' )
    return;


def main():
    myString = "Hello"
    myString += " World"

    PrintChars( myString );
    PrintCharsByIndex( myString );
    return;

main();
