# Test file for "Lab4"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n



# Add tests below

test "PINA: 0x03, 0x03 => PORTC: 0x07, State: Reset"
set State = start
setPINA 0x03
continue 2
setPINA 0x03
continue 2
expectPORTC 0x00
expect State zero
checkResult

test "PINA: 0x01, 0x01 => PORTC: 0x09, State: Add"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
expectPORTC 0x09
expect State increment
checkResult

test "PINA: 0x01 => PORTC: 0x08, State: Add"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x01
continue 2
expectPORTC 0x08
expect State increment
checkResult

test "PINA: 0x02, 0x02 => PORTC: 0x05, State: Sub"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
expectPORTC 0x05
expect State decrement
checkResult

test "PINA: 0x02 => PORTC: 0x06, State: Sub"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x02
continue 2
expectPORTC 0x06
expect State decrement
checkResult

test "PINA: 0x01, 0x02, 0x01 => PORTC: 0x08, State: Add"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x01
continue 2
setPINA 0x02
continue 2
setPINA 0x01
continue 2
expectPORTC 0x08
expect State increment
checkResult

test "PINA: 0x02, 0x01, 0x02 => PORTC: 0x06, State: Sub"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x02
continue 2
setPINA 0x01
continue 2
setPINA 0x02
continue 2
expectPORTC 0x06
expect State decrement
checkResult

test "PINA: 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 => PORTC: 0x00, State: Sub"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
setPINA 0x02
continue 2
expectPORTC 0x00
expect State decrement
checkResult

test "PINA: 0x01, 0x01, 0x01, 0x01  => PORTC: 0x09, State: Add"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
expectPORTC 0x09
expect State increment
checkResult

test "PINA: 0x01, 0x01, 0x01, 0x01, 0x02, 0x03  => PORTC: 0x07, State: Reset"
set State = start
#setPINA 0x03
#continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
setPINA 0x01
continue 2
setPINA 0x02
continue 2
setPINA 0x03
continue 2
expectPORTC 0x00
expect State zero
checkResult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
