CODE :
DATA SEGMENT
ARRAY DW 0040H,0020H,0055H,0075H,0015H ;INITIALISE THE ARRAY
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX,DATA ;MOVE DATA VALUE TO REGISTER AX
MOV DS,AX ;MOVE DATA TO DATA SEGMENT DS
MOV AX,0000H ;INITAIALISE AX TO 0
MOV CX,0005H ;CX IS THE COUNTER VALUE
RPT: ;LOOP NAMED RPT
ADD AX, ARRAY[SI] ;ADD ARRAY ELEMENT TO AX
ADD SI, 0002H ;INCREMENTING SI VALUE
LOOP RPT
MOV BX,AX ;SUM IS STORED IN BX
MOV CX,0005H ;COUNTER VALUE INITIALISED TO 5 
DIV CX ;AVERAGE CALCULATION
HLT
CODE ENDS
END START