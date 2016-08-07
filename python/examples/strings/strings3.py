import sys;



'''
-------------------------------------------------------------------------------
Will print 'Hello' to screen when called with
PrintFromStart( 'Hello World', 5 )
-------------------------------------------------------------------------------
'''
def PrintFromStart( mainString, noChars ):
    newString = mainString[0:noChars] 
    print( newString ) 
    return;

'''
-------------------------------------------------------------------------------
Will print 'World' to screen when called with
PrintFromEnd( "Hello World", 5 )
-------------------------------------------------------------------------------
'''
def PrintFromEnd( mainString, noChars ):
    newString = mainString[-noChars:]
    print( newString )
    return;

'''
-------------------------------------------------------------------------------
Will print 'o World' to screen when called with Right( "Hello World", 4 )
-------------------------------------------------------------------------------
'''
def Right( mainString, noChars ):
    print( mainString[noChars:] )
    return;

'''
-------------------------------------------------------------------------------
Will print 'Hel' to screen when called with Left( "Hello World", 3 )
-------------------------------------------------------------------------------
'''
def Left( mainString, noChars ):
    print( mainString[0:noChars] )
    return;


def main( ):
    myString = "Hello World"
    PrintFromStart( myString, 5 )
    PrintFromEnd( myString, 5 )
    Right( myString, 4 )
    Left( myString, 3 )
    return;

main();
