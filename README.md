# ECE752

leak check

Option 1: 
`valgrind --leak-check=full -v ./output`

Option 2 (enable GDB)
`valgrind -q --vgdb-error=0 ./output`
