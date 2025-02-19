#315CA-Gilma Sebastian Mihai
# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
TARGETS=main.c load.c select.c save.c read.c crop.c rotate1.c equalizer.c apply.c histogram.c
NAME = image_editor

build: $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o $(NAME) -lm
pack:
	zip -FSr 315CA_GilmaSebastianMihai_Tema3.zip README Makefile *.c *.h
clean:
	rm -f $(NAME)
.PHONY: pack clean