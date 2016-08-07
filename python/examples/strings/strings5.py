import sys;


'''
-------------------------------------------------------------------------------
Will print 'World' to screen when called with
PrintFromEnd( "Hello World", 5 )
-------------------------------------------------------------------------------
'''
def SplitSentenceIntoWords( mySentence ):
    word_list = mySentence.split( " " )
    print( "Sentence [", mySentence, "] has ", len(word_list), " words", sep="" )

    for word in word_list:
        print( word )

    return word_list


def main( ):
    myString = "This is the time for all citizens to come to the aid of the nation" 
    SplitSentenceIntoWords( myString )
    return;

main();
