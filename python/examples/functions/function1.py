import sys;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will add two numbers and return the sum
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def Add( arg1, arg2 ):
	total = arg1 + arg2;
	return total;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will capitalize a string
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def Capitalize( myString ):
	tempString = myString;
	myString = myString.upper();
	print( "Capitalize before[", tempString, "] after[", myString, "]", end='\n', sep = '' );
	return myString;



'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will remove duplicates from a list
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def RemoveDuplicates( myList ):
	tempString = myString;
	myString = myString.upper();
	print( "Capitalize before[", tempString, "] after[", myString, "]", end='\n', sep = '' );
	return myString;




def main():
	total = Add( 10, 20 );
	print( "Sum of two numbers 10 and 20 is ....", total, end='\n' );


	myString = Add( "Hello ", "World" );
	print( "Sum of two strings \'Hello \' and \'World!!!\' is ", myString, end='\n' );


    #Proves pass by reference
	Capitalize( myString );

	print( "myString in main has changed to ... ", myString, end='\n' );
	return;


main();



