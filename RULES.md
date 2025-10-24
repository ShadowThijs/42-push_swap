# Rules

## Stacks
You have 2 stacks **a** and **b**
Stack **a** contains random unique integers (+/-)
Stack **b** contains nothing

## Instruction set
**sa** (swap a): Swap first 2 elements at top of stack **a**
**sb** (swap b): Swap first 2 elements at top of stack **b**
**ss**: Both **sa** and **sb** at the same time
**pa** (push a): Take element at the top of stack **b** and place it at the top of stack **a**
**pb** (push b): Take element at the top of stack **a** and place it at the top of stack **b**
**ra** (rotate a): Shift all elements of stack **a** up by 1
**rb** (rotate b): Shift all elements of stack **b** up by 1
**rr**: **ra** and **rb** at the same time
**rra** (reverse rotate a): Shift all elements of stack **a** down by 1
**rrb** (reverse rotate b): Shift all elements of stack **b** down by 1
**rrr**: **rra** and **rrb** at the same time

