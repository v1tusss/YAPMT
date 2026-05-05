%{
#include <stdio.h>
#include <string.h>
int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%%

program:
	program expr '\n'	{ printf("%d\n", $2); }
	|
	;

expr:
	NUMBER			{ $$ = $1; }
	| expr '+' NUMBER	{ $$ = $1 + $3; }
	| expr '-' NUMBER	{ $$ = $1 - $3; }
	;

%%

void yyerror(const char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}
