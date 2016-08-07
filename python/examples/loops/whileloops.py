import sys;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will print 0.....50


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def while_loop_with_break():
	index = 0;
	while( index < 100 ):
		if( index >= 50 ):
			break;
		print( index, end=' ' );
		index = index + 1;
	print( end = '\n' );
	return;


'''
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This function will print 51.....100


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
'''
def while_loop_with_continue():
	index = 0;
	while( index < 100 ):
		index = index + 1;
		if( index <= 50 ):
			continue;
		print( index, end = ' ' );
	print( end = '\n' );
	return;


while_loop_with_break();
while_loop_with_continue();


