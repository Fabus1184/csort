CC := gcc
OPTS := -Wall -Wextra
LIBS :=
INCS := -I.
SRCS := csort.c $(wildcard algo/*c)

csort: $(SRCS)
	$(CC) $(OPTS) $(LIBS) -I $(INCS) -o $@ $?

run: clean csort
	./csort

clean:
	[[ -e csort ]] && rm csort || exit 0