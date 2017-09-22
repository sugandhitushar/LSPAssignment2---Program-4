objects = program.o
forknWait: $(objects)
	gcc -o forknWait $(objects)
$(objects): program.c program.h
	gcc -c program.c
.PHONY: clean run
clean:
	rm forknWait $(objects) 
run:
	./forknWait
usage:
	@echo make
	@echo make run
