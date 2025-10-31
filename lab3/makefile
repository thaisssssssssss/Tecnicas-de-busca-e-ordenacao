CC=gcc
CFLAGS=-I. -Wall -g  -lm

SRC = main.c

.PHONY: all prog bubble insert select shaker clean

all: bubble

SORT = bubble_sort.c

bubble: SORT = bubble_sort.c
bubble: prog

insert: SORT = insert_sort.c
insert: prog

select: SORT = select_sort.c
select: prog

shaker: SORT = shaker_sort.c
shaker: prog


prog: $(SRC) 
	$(CC) -o prog $(SORT) $^ $(CFLAGS)

clean:
	rm -f *.o prog

#PARA UTILIZAR O MAKE DIGITE NO TERMINAL: 
#   make algoritmo_desejado
#   algoritmos = bubble | insert | select | shaker


#PARA RODAR O EXECUTAVEL COM CADA UM DOS ARQUIVOS:
# ./prog 1000 input/in/unif_rand/1Kunif_rand.txt
# ./prog 10000 input/in/unif_rand/10Kunif_rand.txt
# ./prog 100000 input/in/unif_rand/100Kunif_rand.txt

# ./prog 1000 input/in/sorted/1Ksorted.txt
# ./prog 10000 input/in/sorted/10Ksorted.txt
# ./prog 100000 input/in/sorted/100Ksorted.txt

# ./prog 1000 input/in/reverse_sorted/1Kreverse_sorted.txt
# ./prog 10000 input/in/reverse_sorted/10Kreverse_sorted.txt
# ./prog 100000 input/in/reverse_sorted/100Kreverse_sorted.txt

# ./prog 1000 input/in/nearly_sorted/1Knearly_sorted.txt
# ./prog 10000 input/in/nearly_sorted/10Knearly_sorted.txt
# ./prog 100000 input/in/nearly_sorted/100Knearly_sorted.txt
