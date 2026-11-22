
CC = gcc
CFLAGS = -Wall -Wextra -g

FILES = stud_main.c stud_add.c stud_del.c stud_show.c \
        stud_mod.c stud_save.c stud_sort.c \
        stud_reverse.c stud_delete_all.c

student: $(FILES) student.h
	$(CC) $(CFLAGS) $(FILES) -o student

clean:
	rm -f student *.o

