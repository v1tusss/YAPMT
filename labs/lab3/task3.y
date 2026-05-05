%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

input:
	/* empty */
	| input expr '\n' { printf("\n"); }
	| input expr      { printf("\n"); }
	;

expr:
	term
	| expr '+' term { printf("+"); }
	| expr '-' term { printf("-"); }
	;

term:
	factor
	| term '*' factor { printf("*"); }
	| term '/' factor { printf("/"); }
	;

factor:
	NUMBER { printf("%d", $1); }
	| '(' expr ')'
	;

%%

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
}

int main(void)
{
	yyparse();
	return 0;
}
