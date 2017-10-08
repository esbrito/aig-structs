all: ponteiros.c inteiros.c
	gcc  ponteiros.c -o ponteiros
	gcc inteiros.c  -o inteiros


clean:
	rm *.o  ponteiros inteiros
