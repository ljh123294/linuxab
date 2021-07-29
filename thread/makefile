src=$(wildcard *.c)
obj=$(patsubst %.c, %, $(src))

myArgs= -Wall -g -lpthread

ALL:$(obj)

%:%.c
	gcc $< -o $@ $(myArgs)

clean:
	-rm -rf $(obj)

.PHONY:clean ALL
