x = 1
while x<25:
	f = open("metronet"+str(x)+".xml","x")
	f.write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n")
	f.close()
	print("file " +str(x) +" created")
	x+=1
