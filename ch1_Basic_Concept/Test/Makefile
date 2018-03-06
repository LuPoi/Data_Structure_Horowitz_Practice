CC=g++
CFLAGS =
Path=./out/

all: make_all.o
	mkdir -p out
	files=$$(ls -l *.cpp | wc -l) \
	number=1; while [[ $$number -le $$files ]]; do \
		out_file=$$(ls *.cpp | head -n$$number | tail -n1 | sed 's/\(.*\)\..*/\1/'); \
		in_file=$${out_file}.o; \
		echo "$$number: compile $$out_file"; \
		${CC} ${CFLAGS} $$in_file -o ${Path}$$out_file; \
		((number = number + 1)); \
	done
make_all.o: *.cpp
	${CC} *.cpp -c

clean:
	rm -rf *.o ${Path}*
