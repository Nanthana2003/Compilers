%{
#include <stdio.h>
int singleQuote, doubleQuote;
char brackets[1000];
int i, isComment;
%}

ending [\n]
delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
keyword (if|else|for|while|else\ if|return|break|continue|int|
float|double|void|long\ long|ll|string|cin|cout|main|char|endl)
punctuators (\(|\)|:|;|\[|\]|\{|\}|\.|\,|>>|<<)
char (\'[A-Za-z0-9]?\')
string (\"({digit}|{id})?\")
comment (/\*({digit}|{letter}|{ws}|{punctuators})\*/)

%%
"/*" {isComment = 1;}
"*/" {isComment = 0; printf("comment \n");}
"'"  {if(!isComment){if(!isDouble()) {if(isSingle()){setSingle0(); printf("character\n");} else{setSingle();}}else{printf("Error: Unterminated string or character\n"); setDouble0(); setSingle0();}}}
"\"" {if(!isComment){if(!isSingle()){if(isDouble()){setDouble0(); printf("string\n");} else{setDouble();}}else{printf("Error: Unterminated string or character\n"); setDouble0(); setSingle0();}}}
{ending} {if(!isComment){ if(isSingle() || isDouble()){printf("Error: Unterminated string or character\n"); setDouble0(); setSingle0();}}}
{keyword}  {if(!isComment){if(!isSingle() && !isDouble()){ printf("keyword %s \n", yytext); }}}
{id}    { if(!isComment){if(!isSingle() && !isDouble()){checkid();}}  }
{ws} {}
"+" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"-" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"*" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"/" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"%" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"^" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"||" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"&&" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"&" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"|" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"++" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"+=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"-=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"*=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"/=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"%=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"--" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
">" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"<" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
">=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"<=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"==" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"!=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"=" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"!" {if(!isComment){if(!isSingle() && !isDouble()){printf("operator %s\n", yytext);}}}
"{" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); brackets[i] = '{'; i++;}}}
"}" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); if(!i || brackets[i-1]!='{'){printf("Error: Unclosed brackets\n");} else{i--; brackets[i] = '\0';}}}}
"(" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); brackets[i] = '('; i++;}}}
")" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); if(!i || brackets[i-1]!='('){printf("Error: Unclosed brackets\n");} else{i--; brackets[i] = '\0';}}}}
"[" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); brackets[i] = '['; i++;}}}
"]" {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext); if(!i || brackets[i-1]!='['){printf("Error: Unclosed brackets\n");} else{i--; brackets[i] = '\0';}}}}
{punctuators} {if(!isComment){if(!isSingle() && !isDouble()){printf("punctuator %s\n", yytext);}}}
{number} {if(!isComment){if(!isSingle() && !isDouble()){printf("number %s\n", yytext);}}}
.       {if(!isComment){{if(!isSingle() && !isDouble()){printf("Error: Invalid tokens\n");}} }}
%%

int yywrap(){
        if(i>0){
            printf("Error: Unclosed brackets\n");
        }
        return 1;
}

void checkid(){
    if(yyleng>32){
        printf("Error: identifier exceeds maximum length\n");
        return;
    }
    printf("identifier %s\n", yytext);
    return;
    
    
}

int isSingle(){
    return singleQuote;

}

int isDouble(){
    return doubleQuote;

}

void setSingle(){
    singleQuote = 1;
}

void setSingle0(){
    singleQuote = 0;
}

void setDouble0(){
    doubleQuote = 0;
}

void setDouble(){
    doubleQuote = 1;
}

void initialise(){
    singleQuote = 0;
    doubleQuote = 0;
    i = 0;
    isComment = 0;
}

int main() {
    initialise();
    yylex();
    // display();
    return 0;
}