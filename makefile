CC = g++

readFile: readFile
		$(CC) readFile.cpp -o readFile

clean:
		rm readFile