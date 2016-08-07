import sys;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will print 0.....49


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def for_loop_with_break():
	for index in range( 0, 100 ):
		if( index >= 50 ):
			break;
		print( index, end=' ' );
	print( end = '\n' );
	return;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will print 51.....99


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def for_loop_with_continue():
	for index in range( 0, 100 ):
		if( index <= 50 ):
			continue;
		print( index, end = ' ' );
	# end for loop 
	print( end = '\n' );
	return;


for_loop_with_break();
for_loop_with_continue();


