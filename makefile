OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))

cal.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o *.exe


