all: my_shell break searchstring move cwd run_searchstring 

my_shell: my_shell.c
	gcc my_shell.c -o my_shell -lreadline


break: break.c
	gcc break.c -o break

searchstring: searchstring.c
	gcc searchstring.c -o searchstring

move: move.c
	gcc move.c -o move

cwd: cwd.c
	gcc cwd.c -o cwd


run_searchstring:
	gcc -o run_searchstring run_searchstring.c

clean:
	rm my_shell break searchstring move cwd run_searchstring f2 *~
