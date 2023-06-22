[  This script multiplies first two digit provided by user
   result can be 2 digit
   this script outputs nothing if one of the operand is 0 ]

,				store the first char from stdin in cell #0
A loop to subtract 48 from cell #0
>++++++				set cell #1 to 6 (loop counter) 
[
	< -------- 		subtract 8 from cell #0
	> -           		decrement counter (cell #1) by 1
]

,				store the second char from stdin in cell #1
A loop to subtract 48 from cell #1
>++++++				set cell #2 to 6 (loop counter) 
[
	< -------- 		subtract 8 from cell #1
	> -             	decrement counter (cell #2) by 1
]
<				move to #1
[>>+<<-]			store value in cell #1 in cell #3
<                               move to cell #0

A loop to multiply the value of char in cell #0 and cell #1 and store in cell #2
[
	>>>			move data pointer to cell #3
	[<<+ >>>+ <-]		store value in cell #3 in #1 and #4
	<< 			move data pointer to cell #1
	[
		> + 		add 1 to cell #2
		< -             decrement inner counter (cell #1) by 1
	]
	>>>			move to #4
	[<+>-]			store value in cell #4 to #3
	<<<<-
]
>>				move to cell #2
[<+ >-]				copy cell 2 to cell #1
>[-]				set value in cell #3 to zero
>[-]				set value in cell #4 to zero
<<< 				move to cell #1

[
	>>>>>[-]                set cell #6 to zero (used to check if result is 
				multiple of 10)
	<			move to cell #5
	[<<<<<+>>>>>-]		copy cell #5 to #0 if cell #5 is not zero 
	++++++++++		set cell #5 to 10
	<<<<<+			increment cell #0 by 1
	[---------- >>] 	subtract 10 from cell #0 and exit loop(cell #2 = 0)
	<<[>>-<<[>>>+ <<<+]]	skips if the result of subtraction is zero else 
				stores the positive of cell #0 in cell #3
	>>+[>>+ >[-] >+ <<<<-]	if zero add 1 to cell #4 (stores tens)
	>[>>- <<-]		if result of the previous subtraction is not 0
				it stores the units in cell #5
	<<-			decrement cell #1
]

>>>[<++++++[>++++++++<-]>.[-]] 		if tens in cell #4 not 0 add 48 to the
					to convert to ascii code and output

>[<++++++[>++++++++<-]>.[-]]   		if units in cell #5 not 0 add 48 to the
					to convert to ascii code and output

>[-<++++++[>++++++++<-]>.[-]]   	if value in cell #6 not 0 then value is
					multiple of 10 (outputs  ascii code)
