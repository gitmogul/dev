import sys;



'''
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
'''
def FindSubString( mainString, subString ):
    index = mainString.find( subString )
    if( index >= 0 ):
        print( "Found string [", subString, "] in string [", mainString, "] at index ", index, sep='' )
    else:
        print( "Failed to find string [", subString, "] in string [", mainString, "]" )
    return index;


def main( ):
    myString = "Hello World"
    FindSubString( myString, "World")
    return;

main();
