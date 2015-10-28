exec:
	gcc -pthread -o shell shell.c -Wall

clean:
	rm -rf shell

run:
	./shell		