# Test file for "Lab2"


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

test "Total 0"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x04
checkResult

test "Total 140, balanced"
setPINA 0x28
setPINB 0x3C
setPINC 0x28
continue 5
expectPORTD 0x04
checkResult

test "Total 100, negatively unbalanced"
setPINA 0x01
setPINB 0x0F
setPINC 0x54
continue 5
expectPORTD 0x06
checkResult

test "Total 100, positively unbalanced"
setPINA 0x54
setPINB 0x0F
setPINC 0x01
continue 5
expectPORTD 0x06
checkResult

test "Total 150, balanced"
setPINA 0x32
setPINB 0x32
setPINC 0x31
continue 5
expectPORTD 0x05
checkResult

test "Total 300, balanced"
setPINA 0x64
setPINB 0x64
setPINC 0x64
continue 5
expectPORTD 0x09
checkResult

test "Total 200, negatively unbalanced"
setPINA 0x01
setPINB 0x75
setPINC 0x52
continue 5
expectPORTD 0x0B
checkResult

test "Total 200, positively unbalanced"
setPINA 0x52
setPINB 0x75
setPINC 0x01
continue 5
expectPORTD 0x0B
checkResult

test "Total 450, balanced"
setPINA 0xC8
setPINB 0x82
setPINC 0x78
continue 5
expectPORTD 0x11
checkResult

test "Total 400, negatively unbalanced"
setPINA 0x00
setPINB 0xC8
setPINC 0xC8
continue 5
expectPORTD 0x13
checkResult

test "Total 400, positively unbalanced"
setPINA 0xC8
setPINB 0xC8
setPINC 0x00
continue 5
expectPORTD 0x13
checkResult

test "Total 600, balanced"
setPINA 0xC8
setPINB 0xC8
setPINC 0xC8
continue 5
expectPORTD 0x21
checkResult

test "Total 500, negatively unbalanced"
setPINA 0x96
setPINB 0x64
setPINC 0xFA
continue 5
expectPORTD 0x23
checkResult

test "Total 500, positively unbalanced"
setPINA 0xFA
setPINB 0x64
setPINC 0x96
continue 5
expectPORTD 0x23
checkResult

test "Total 750, balanced"
setPINA 0xFA
setPINB 0xFA
setPINC 0xFA
continue 5
expectPORTD 0x41
checkResult

test "Total 650, negatively unbalanced"
setPINA 0xA9
setPINB 0xCC
setPINC 0xFA
continue 5
expectPORTD 0x43
checkResult

test "Total 650, positively unbalanced"
setPINA 0xFA
setPINB 0xCC
setPINC 0xA9
continue 5
expectPORTD 0x43
checkResult

test "Total 765"
setPINA 0xFF
setPINB 0xFF
setPINC 0xFF
continue 5
expectPORTD 0x81
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
