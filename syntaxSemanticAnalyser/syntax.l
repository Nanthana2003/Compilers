%{
# include "syntax.tab.h"
char typeval[32];
// int yylval;
%}

delim [ \t]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
datatype (int|float|double|long\ long|string|void)
while (while)
for (for)
if (if)
else (else)
elseif (elseif)
return (return)

%%
{datatype} { strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return DATA;}
{while} { strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return WHILE;}
{if} { strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return IF;}
{else} { strcpy(yylval.nd_obj.name,(yytext)); strcpy(typeval, yytext); return ELSE;}
{elseif} { strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return ELSEIF;}
{return} {strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return RETURN;}
{id} { strcpy(yylval.nd_obj.name,(yytext));  strcpy(typeval, yytext); return ID;}
{number} { strcpy(yylval.nd_obj.name,(yytext)); strcpy(typeval, yytext); return NUM;}
"+" { strcpy(yylval.nd_obj.name,(yytext));  return ADD;}
"-" { strcpy(yylval.nd_obj.name,(yytext));  return SUB;}
"*" { strcpy(yylval.nd_obj.name,(yytext));  return MUL;}
"/" { strcpy(yylval.nd_obj.name,(yytext));  return DIV;}
"=" { strcpy(yylval.nd_obj.name,(yytext));  return EQL;}
";" { strcpy(yylval.nd_obj.name,(yytext)); yylineno++;  return EOL;}

"," { strcpy(yylval.nd_obj.name,(yytext));  return COMMA;}
"(" { strcpy(yylval.nd_obj.name,(yytext));  return LPAREN;}
")" { strcpy(yylval.nd_obj.name,(yytext));  return RPAREN;}
"{" { strcpy(yylval.nd_obj.name,(yytext));  return LBRACE;}
"}" { strcpy(yylval.nd_obj.name,(yytext));  return RBRACE;}
"<" { strcpy(yylval.nd_obj.name,(yytext));  return LT;}
">" { strcpy(yylval.nd_obj.name,(yytext));  return GT;}
"<=" { strcpy(yylval.nd_obj.name,(yytext)); return LTE;}
">=" { strcpy(yylval.nd_obj.name,(yytext)); return GTE;}
"==" { strcpy(yylval.nd_obj.name,(yytext));  return EE;}
"!=" { strcpy(yylval.nd_obj.name,(yytext)); return NE;}
"$" {return SPC;}




%%

int yywrap(){
        return 1;
}

// int main(){
//     // int tok;
//     // while(tok = yylex()){
//     //     printf("%d \n", tok);

//     // }
// }