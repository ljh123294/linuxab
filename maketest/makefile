src=$(wildcard ./src/*.c) 
obj=$(patsubst ./src/%.c, ./obj/%.o, $(src)) 

myArgs= -Wall -g

inc_path= ./inc

ALL:a.out

a.out:$(obj)
	gcc $^ -o $@ $(myArgs)

./obj/%.o:./src/%.c
	gcc -c $< -o $@ $(myArgs) -I $(inc_path)

clean:
	-rm -rf $(obj) a.out

.PHONY:clean ALL
