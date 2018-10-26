'set vars to use
'-------------------------
 counter = 0
 x  = 0
 y  = 1
 z  = 0
 numberHolder = z
'-------------------------

'get series count
 seriesPosition = InputBox("How many numbers would you like to see?") - 1

'call fib calculator
 Fibonacci(seriesPosition)

MsgBox "Fibonacci sequence: " & numberHolder


'fib calculator
Sub Fibonacci(pos)
	Do Until counter = pos
  		z = x + y
  		x = y
  		y = z
  		numberHolder = numberHolder & " " & z
 		counter = counter + 1
	Loop
End Sub


