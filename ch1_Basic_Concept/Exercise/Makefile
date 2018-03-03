CC = g++
Path=./out/

1.3.1_Multiply_Test: 1.3.1_Multiply_Test.o
	mkdir -p out
	${CC} 1.3.1_Multiply_Test.o -o ${Path}1.3.1_Multiply_Test
1.3.1_Multiply_Test.o: 1.3.1_Multiply_Test.cpp
	${CC} 1.3.1_Multiply_Test.cpp -c

clean:
	rm -rf *.o ${Path}*
