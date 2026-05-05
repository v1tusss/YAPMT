%{
#include <stdio.h>
%}

%%
[a-zA-Z]+	printf("%s\n", yytext); 
[0-9]+		printf("%s\n", yytext); 
%%

