filename=$1
flex $filename".l"
bison $filename".y" -d
g++ -o parser lex.yy.c $filename".tab.c" 