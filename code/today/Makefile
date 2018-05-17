

#nimabi:left.c right.c top.c bottom.c main.c
#	gcc left.c right.c top.c bottom.c main.c -o app

#app:left.o right.o top.o bottom.o main.o
#	@gcc left.o right.o top.o bottom.o main.o -o app

#obj=left.o right.o top.o bottom.o main.o
#app:$(obj)
#	@gcc $(obj) -o app

#main.o:main.c
#	@gcc -c main.c

#bottom.o:bottom.c
#	@gcc -c bottom.c

#top.o:top.c
#	@gcc -c top.c

#right.o:right.c
#	@gcc -c right.c

#left.o:left.c
#	@gcc -c left.c

#src=$(wildcard *.c)
#showFile:$(src)
#	@echo $(src)

CC=gcc
CPPFLAGS=-Iinclude

src=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(src))
#obj=$(src)
target=app
$(target):$(obj)
	@$(CC) $^ -o $@



.PHONY:clean
clean:
	@-rm -f *.o
	@-rm -f app
	@-rm -f a.out

#version:
#	@echo "1.8.0"
	





