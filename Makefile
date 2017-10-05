ponteiros: ponteiros.c
	gcc  ponteiros.c -o ponteiros

inteiros: inteiros.c
	gcc inteiros.c  -o inteiros


clean:
	rm *.o  ponteiros inteiros
