import sys;


'''
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
'''
def upper( mySentence ):
    upper_case_sentence  = mySentence.upper()
    print( "Original sentence:", mySentence )
    print( "Upper case sentence:", upper_case_sentence )
    return upper_case_sentence

'''
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
'''
def lower( mySentence ):
    lower_case_sentence  = mySentence.lower()
    print( "Original sentence:", mySentence )
    print( "Lower case sentence:", lower_case_sentence )
    return lower_case_sentence


def main( ):
    myString = "This is the time for all citizens to come to the aid of the nation" 
    myString = upper( myString )
    myString = lower( myString )
    return;

main();
