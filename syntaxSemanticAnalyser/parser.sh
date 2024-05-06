flex syntax.l
bison -d syntax.y   # -v tag is to generate syntax.output file
gcc -o parser syntax.tab.c lex.yy.c



