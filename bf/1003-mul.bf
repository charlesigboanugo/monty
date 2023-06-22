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

A loop to add 48 to value in cell #2
>++++++			set cell #1 to 6 (loop counter) 
[
	> ++++++++ 	add 8 to cell #2
	< -             decrement counter (cell #1) by 1
]
>.			output result in cell #2
