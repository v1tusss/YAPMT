.ORIG x3000

LEA 	R0, STRING      
PUTS                

LEA	R1, NUMBERS      
LD 	R2, COUNT        

LOOP_READ

	GETC                 
	OUT                
	LD 	R3, NEG48
	ADD 	R0, R0, R3     
	STR 	R0, R1, #0      
	ADD 	R1, R1, #1      
	ADD 	R2, R2, #-1      
	BRp 	LOOP_READ  

	LEA 	R1, NUMBERS      
	LD 	R2, COUNT        
	ADD 	R2, R2, #-1     

LOOP_SORT

	LD 	R4, COUNT         
	ADD 	R4, R4, #-1
	LEA 	R3, NUMBERS      

INLOOP

	LDR 	R0, R3, #0       
	LDR 	R1, R3, #1       
	NOT 	R5, R1
	ADD 	R5, R5, #1
	ADD 	R5, R0, R5       
	BRn 	LOOP_SWAP       
	STR 	R1, R3, #0      
	STR 	R0, R3, #1

LOOP_SWAP

	ADD 	R3, R3, #1       
	ADD 	R4, R4, #-1      
	BRp 	INLOOP       

	ADD 	R2, R2, #-1      
	BRp 	LOOP_SORT      
	LD 	R0, NEWLINE
	OUT
	
	LEA 	R1, NUMBERS
	LD 	R2, COUNT

LOOP_PRINT

	LDR 	R0, R1, #0       
	LD 	R3, POS48     
	ADD 	R0, R0, R3       
	OUT                  
	ADD 	R1, R1, #1      
	ADD 	R2, R2, #-1      
	BRp 	LOOP_PRINT

HALT                

STRING	.STRINGZ "Enter 5 numbers: "
NUMBERS	.BLKW 5            
COUNT	.FILL #5      
NEG48	.FILL #-48
POS48	.FILL #48
NEWLINE	.FILL x000A    
 
.END
