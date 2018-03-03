CC=g++
Path=./out/

1.1_Output_in_C: make_all.o
	mkdir -p out
	${CC} 1.1_Output_in_C++.o -o ${Path}1.1_Output_in_C++
	${CC} 1.2_Input_in_C++.o -o ${Path}1.2_Input_in_C++
	${CC} 1.3_File_IO_in_C++.o -o ${Path}1.3_File_IO_in_C++
	${CC} 1.4_example_of_function.o -o ${Path}1.4_example_of_function
make_all.o: *.cpp
	${CC} *.cpp -c

clean:
	rm -rf *.o ${Path}*
