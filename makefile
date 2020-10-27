objects = mat.o mat_mem.o mat_io.o mat_op.o mat_misc.o input.o

mat : $(objects)
	cc -o mat $(objects)

.PHONY : clean
clean : 
	-rm mat $(objects)