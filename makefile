var:= $(patsubst %.c, %.o, $(wildcard *.c))
cal.exe: $(var)
		gcc -o $@ $^
clean:
		rm *.o *.exe

