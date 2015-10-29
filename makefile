 cc = gcc
exec:
	${cc} -pthread -o shell shell.c -Wall

clean:
	rm -rf shell

run:
	./shell		