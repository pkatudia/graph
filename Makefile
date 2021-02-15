all:
	gcc -g graphTest.c -o graphTest.o
clean:
	rm -rf *.o
cleanall:
	rm -rf *.o
	rm -rf core.*
