[    Adds first two digits given by the user
     result must be a single digit  ]

,			store the first char from stdin in cell #0
>,			store the second char from stdin in cell #1

A loop to add the integer value of char in cell #0 and cell #1
[
	< + 		add 1 to cell #0
	> -             decrement counter (cell #1) by 1
]

A loop to subtract 48 from cell #0
++++++			set cell #1 to 6 (loop counter) 
[
	< -------- 	subtract 8 from cell #0
	> -             decrement counter (cell #1) by 1
]

<.			output result in cell #0 
