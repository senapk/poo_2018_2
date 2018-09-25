CPPFLAGS = -Wall -std=c++14 -Werror
FILE = segredos.md

all: testes segredos
	./segredos < fin.txt > fuser.txt
	diff fsol.txt fuser.txt

testes:
	@ cat $(FILE) | sed -n '/\__begin__/,/\<\__end__/p' | sed '/^\s*$$/d; /^\#/d' > fsol.txt
	@ cat fsol.txt | sed -n -e '/^\$$/p' | sed 's/^.//' > fin.txt
