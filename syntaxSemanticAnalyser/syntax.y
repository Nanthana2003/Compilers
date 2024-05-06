%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<signal.h>
// #define YYDEBUG 1
#include "syntax.tab.h"
// #include "lex.yy.c"

void insert_type();
void add(char);
int search(char *, char *);
void check_declaration(char *, char *);
int check_types(char *, char *);
char *get_type(char *, char *);
void check_returnval(char *, char *);
void check_returnval_void();

char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
extern int yylineno;
extern char typeval[32];
int count = 0;
int q;
char type[10], functype[10];
int sem_errors=0;
char scopedetail[20] = {'m', 'a', 'i', 'n'};
char mainval[20] = {'m', 'a', 'i', 'n'};
char buff[100];
char errors[10][100];
int label=0;
int is_for=0;
int ic_idx=0;
int temp_var = 0;
char icg[50][100];

 struct dataType {
        char * id_name;
        char * data_type;
        char * type;
		char * scope;
        int line_no;
	} symbol_table[40];



struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);
    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
%}

%union { 
	struct var_name { 
    char type[5];
	char name[100]; 
	struct node* nd;
	char if_body[5];
	char else_body[5];
	} nd_obj; 
}

%token <nd_obj> NUM ADD DIV MUL SUB ID OTHER EQL EOL DATA WHILE FOR IF ELSE ELSEIF NEWLINE COMMA DELIM LPAREN RPAREN LBRACE RBRACE GT LT GTE LTE EE NE SPC RETURN
%type <nd_obj> entry start exp compexp ifelsestatement elseclause elseifclause whilestatement expression factor declaration varlist term single ifclause elseifstatement statement singledec newvar identifier datatype functionstatement returnstatement funcdec declist nextdec



%%

entry: 
  start SPC {head = ($1).nd; ($$).nd = ($1).nd; printeverything(); }
  ;


start: 
 statement start  {($$).nd = mknode(($1).nd, ($2).nd, "start");}
 | {($$).nd = NULL;}
 ;

statement:
 expression {($$).nd = ($1).nd;}
 | declaration {($$).nd = ($1).nd;}
 | whilestatement {($$).nd = ($1).nd;}
 | ifelsestatement {($$).nd = ($1).nd;}
 | functionstatement {($$).nd = ($1).nd;}

functionstatement:
 datatype identifier {add('F'); strcpy(scopedetail, ($2).name); strcpy(($2).type, type); strcpy(functype, ($1).name); } LPAREN funcdec RPAREN LBRACE start returnstatement RBRACE {($$).nd = mknode(mknode(($1).nd, ($5).nd, "func-dec"), mknode(($8).nd, ($9).nd, "statements"), ($2).name); strcpy(scopedetail, mainval); }
 ;

returnstatement: {check_returnval_void(); ($$).nd = mknode(NULL, NULL, "void");}
 | RETURN identifier EOL {check_returnval(($2).type, ($2).name); ($$).nd = mknode(NULL, NULL, ($2).name); }
 ;

funcdec: {($$).nd = mknode(NULL, NULL, "empty-dec");}
 | declist {($$).nd = ($1).nd; }
 ;

declist:
 datatype identifier {add('V'); strcpy(($2).type, type); } nextdec {($$).nd = mknode(mknode(($1).nd, ($2).nd, "dec"), ($4).nd, ",");}
 ;

nextdec: {($$).nd = mknode(NULL, NULL, "end"); }
 | COMMA declist {($$).nd = ($2).nd; }
 ;

ifelsestatement:
 ifclause elseifstatement {($$).nd = mknode(($1).nd, ($2).nd, "if-else-elseif");}
 ;

ifclause:
 IF {add('K');} LPAREN compexp RPAREN LBRACE start RBRACE {($$).nd = mknode(($4).nd, ($7).nd, "if");}
 ;


elseifstatement:
 elseclause {($$).nd = ($1).nd;}
 | elseifclause elseifstatement {($$).nd = mknode(($1).nd, ($2).nd, "else-if-statement");}
 ;

elseifclause:
 ELSEIF {add('K');} LPAREN compexp RPAREN LBRACE start RBRACE {($$).nd = mknode(($4).nd, ($7).nd, "else-if");}
 ;

identifier: ID {($$).nd = mknode(NULL, NULL, ($1).name);  strcpy(($$).type, get_type(($1).name, scopedetail)); }
 ;

elseclause: {($$).nd = NULL;}
 | ELSE {add('K');} LBRACE start RBRACE {($$).nd = ($4).nd;}
 ;
 
whilestatement: 
 WHILE {add('K');} LPAREN compexp RPAREN LBRACE start RBRACE {($$).nd = mknode(($4).nd, ($7).nd, "while");}
 ;

expression:
 identifier {check_declaration(typeval, scopedetail);} EQL exp EOL {($$).nd = mknode(($1).nd, ($4).nd, "=");}
 ;

declaration:
 datatype varlist EOL {($$).nd = mknode(($1).nd, ($2).nd, "declaration");}
 ;

varlist: 
 single newvar {($$).nd = mknode(($1).nd, ($2).nd, ",");}
 ;

newvar: {($$).nd = NULL;}
 | COMMA varlist {($$).nd = ($2).nd;}
 
 ;

datatype: DATA {insert_type();} {($$).nd = mknode(NULL, NULL, ($1).name);}
 ;

single:
 identifier {add('V');  strcpy(($1).type, type); } singledec {($$).nd = mknode(($1).nd, ($3).nd, "=");}
 ;

singledec: {($$).nd = NULL;}
 | EQL exp {($$).nd = ($2).nd;}
 
 ;

exp: term {($$).nd = ($1).nd;}
 | exp ADD term {
  if(!strcmp(($1).type, ($3).type)) {
		// printf("%s\n", ($1).type);
		($$).nd = mknode(($1).nd, ($3).nd, "+"); 
	}
	else {
		if(!strcmp(($1).type, "int") && !strcmp(($3).type, "float")) {
			struct node *temp = mknode(NULL, ($1).nd, "inttofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "+");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($3).nd, "inttofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "+");
		}
		else if(!strcmp(($1).type, "int") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartoint");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "+");
		}
		else if(!strcmp(($1).type, "char") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($1).nd, "chartoint");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "+");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "+");
		}
		else {
			struct node *temp = mknode(NULL, ($1).nd, "chartofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "+");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } 
 }
 | exp SUB term {if(!strcmp(($1).type, ($3).type)) {
		($$).nd = mknode(($1).nd, ($3).nd, "-"); 
	}
	else {
		if(!strcmp(($1).type, "int") && !strcmp(($3).type, "float")) {
			struct node *temp = mknode(NULL, ($1).nd, "inttofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "-");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($3).nd, "inttofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "-");
		}
		else if(!strcmp(($1).type, "int") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartoint");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "-");
		}
		else if(!strcmp(($1).type, "char") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($1).nd, "chartoint");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "-");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "-");
		}
		else {
			struct node *temp = mknode(NULL, ($1).nd, "chartofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "-");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
 ;

term: factor {($$).nd = ($1).nd;}
 | term MUL factor {if(!strcmp(($1).type, ($3).type)) {
		($$).nd = mknode(($1).nd, ($3).nd, "*"); 
	}
	else {
		if(!strcmp(($1).type, "int") && !strcmp(($3).type, "float")) {
			struct node *temp = mknode(NULL, ($1).nd, "inttofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "*");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($3).nd, "inttofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "*");
		}
		else if(!strcmp(($1).type, "int") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartoint");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "*");
		}
		else if(!strcmp(($1).type, "char") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($1).nd, "chartoint");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "*");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "*");
		}
		else {
			struct node *temp = mknode(NULL, ($1).nd, "chartofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "*");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
 | term DIV factor {if(!strcmp(($1).type, ($3).type)) {
		($$).nd = mknode(($1).nd, ($3).nd, "/"); 
	}
	else {
		if(!strcmp(($1).type, "int") && !strcmp(($3).type, "float")) {
			struct node *temp = mknode(NULL, ($1).nd, "inttofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "/");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($3).nd, "inttofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "/");
		}
		else if(!strcmp(($1).type, "int") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartoint");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "/");
		}
		else if(!strcmp(($1).type, "char") && !strcmp(($3).type, "int")) {
			struct node *temp = mknode(NULL, ($1).nd, "chartoint");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "/");
		}
		else if(!strcmp(($1).type, "float") && !strcmp(($3).type, "char")) {
			struct node *temp = mknode(NULL, ($3).nd, "chartofloat");
			sprintf(($$).type, ($1).type);
			($$).nd = mknode(($1).nd, temp, "/");
		}
		else {
			struct node *temp = mknode(NULL, ($1).nd, "chartofloat");
			sprintf(($$).type, ($3).type);
			($$).nd = mknode(temp, ($3).nd, "/");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
 ;

compexp: exp EE exp {($$).nd = mknode(($1).nd, ($3).nd, "==");}
  | exp NE exp {($$).nd = mknode(($1).nd, ($3).nd, "!=");}
  | exp GT exp {($$).nd = mknode(($1).nd, ($3).nd, ">");}
  | exp LT exp {($$).nd = mknode(($1).nd, ($3).nd, "<");}
  | exp GTE exp {($$).nd = mknode(($1).nd, ($3).nd, ">=");}
  | exp LTE exp {($$).nd = mknode(($1).nd, ($3).nd, "<=");}
  ;

factor: NUM { add('C');} {($$).nd = mknode(NULL, NULL, ($1).name);}
 | identifier {($$).nd = ($1).nd; check_declaration(typeval, scopedetail); }
 ; 





%%

int p = -1;

void sigint_handler(int sig_no)
{
  signal(SIGINT, sigint_handler);
    printf("CTRL-C pressed\n");
    // struct sigaction old_action;
    if(p!=-2) printBT(head);
    // sigaction(SIGINT, &old_action, NULL);
    kill(0, SIGINT);
}


int main(int argc, char **argv)
{
  // int p = -1;
  // yydebug = 1;
  p = yyparse();
  // struct sigaction action, old_action;
    // memset(&action, 0, sizeof(action));
    // action.sa_handler = &sigint_handler;
    // sigaction(SIGINT, &action, &old_action);
  // if(p) printf("Parsing is successful\n");
  // while(1){}
  // signal(SIGINT, sigint_handler);
  
  
  return 0;

}

yyerror(char *s)
{
  
  p = -2;
  printf("Error : %s at line number %d\n", s, yylineno);
}

void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("├──"); } 
		else { printf("└──"); }
        printf("%s",ptr->token);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);    
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void insert_type() {
  // printf("%s\n", typeval);
	strcpy(type, typeval);
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return 6;
}

char *get_type(char *var, char *scopeval){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var) && !strcmp(symbol_table[i].scope, scopeval)) {
			return symbol_table[i].data_type;
		}
	}
	return "h";
}

void add(char c) {
  // printf("here\n");
	if(c == 'V'){
		for(int i=0; i<10; i++){
      // printf("%s\n", typeval);
      // printf("here\n");
			if(!strcmp(reserved[i], strdup(typeval))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", yylineno+1, typeval);
				sem_errors++;
				return;
			}
		}
	}
//   printf("here\n");
    q=search(typeval, scopedetail);
    // printf("here\n");
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Variable");
			symbol_table[count].scope = strdup(scopedetail);
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Function");
			symbol_table[count].scope = strdup(scopedetail);
			count++;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", yylineno+1, typeval);
		sem_errors++;
    }
}

int search(char *type, char *scopeval) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0 && symbol_table[i].scope && strcmp(symbol_table[i].scope, scopeval) == 0) {
			return -1;
			break;
		}
	}
	return 0;
}

void printeverything(){
  printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].scope);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printBT(head);
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
  if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
}

void check_declaration(char *c, char* s) {
    q = search(c, s);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", yylineno+1, c);
		sem_errors++;
    }
}

void check_returnval(char *c, char* n){
	if(strcmp(c, functype) == 0){
		return ;
	}
	else{
		sprintf(errors[sem_errors], "Line %d: Variable \"%s\" wrong return type!\n", yylineno+1, n);
		sem_errors++;

		return ;
	}

}

void check_returnval_void(){
	if(strcmp("void", functype)!=0){
		sprintf(errors[sem_errors], "Line %d: It is not a void function!\n", yylineno+1);
		sem_errors++;

	}
}