#!/bin/sh
make
gcc ft_generator.c

if [ -n "$1" ] && [ -z "$2" ]
then
	ARG=$1
elif [ -n "$1" ] && [ -n "$2" ] && [ -n "$3" ]
then
	ARG=`./a.out $1 $2 $3`;
	echo $ARG
else
	echo "./pusw_script <nb of numeros> <min> <max> [move ?]"
	exit 1
fi

if [ -n "$4" ]
then
	./push_swap -v $ARG
else
	./push_swap $ARG
fi

echo $ARG > chiffre.txt
./push_swap $ARG | ./checker_mac $ARG | grep --color -E "OK|Error"

echo -n "nb of moves : "
./push_swap $ARG | wc -l
