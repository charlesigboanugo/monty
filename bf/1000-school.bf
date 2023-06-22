[ 
  This program prints "School" and a newline to the screen
  char code of school = (83 99 104 111 111 108)  newline = 10
]


++++++++            		  set cell #0 to 8 (out loop counter)
[
	>+++                      set cell #1 to 3 (inner loop counter)
  	[
		>+++              add 3 to cell #2
  		>++++             add 4 to cell #3
  		>++++             add 4 to cell #4
  		>++++             add 4 to cell #5
  		<<<<-             decrement the loop counter in cell #1
  	]                         Loop until Cell #1 is zero; number
		                  of iterations is 3
  	>+                        add 1 to cell #2
  	>>+                       add 1 to cell #4
  	>++                       add 2 to cell #5
  	>+                        add 1 to cell #6
  	[<]                       move back to the first zero cell found: this
				  will be cell #1
  	<-                        decrement loop counter in cell #0
]                                 Loop until Cell #0 is zero; number of 
		                  iterations is 8

The result of this is:
Cell no :   0    1    2    3    4    5   6
Contents:   0    0   80   96  104  112   8
Pointer :   ^

>>+++.				add 2 to cell #2 to get 83 which is 'S'
>+++.				add 3 to cell #3 to get 99 which is 'c'
>.      			cell #4 which is 'h'
> -..   			subtract 1 from cell #5 to get 111 which is 'o'
---.    			subtract 3 from cell #5 to get 108 which is 'l'
>++.   				add 2 to cell #6 to get 10 which is newline
