#!/bin/bash

ME=./players/filler_test.filler
ABANLIN=./players/abanlin.filler
CARLI=./players/carli.filler
CHAMPELY=./players/champely.filler
GRATI=./players/grati.filler
HCAO=./players/hcao.filler
SUPJEAN=./players/superjeannot.filler

MAP0=./maps/map00
MAP1=./maps/map01
MAP2=./maps/map02

make test -C ./rendu

for m in $MAP0 $MAP1 $MAP2;
do
	for a in $ABANLIN $CARLI $CHAMPELY $GRATI $HCAO $SUPJEAN;
	do
		echo $a $m
		for i in 1 2 3 4 5;
		do
			./filler_vm -f $m -p1 $ME -p2 $a | grep fin | cut -d ":" -f 2 | ./me_p1
		done
		printf "\n\n"
	done
done

for m in $MAP0 $MAP1 $MAP2;
do
	for a in $ABANLIN $CARLI $CHAMPELY $GRATI $HCAO $SUPJEAN;
	do
		echo $a $m
		for i in 1 2 3 4 5;
		do
			./filler_vm -f $m -p1 $a -p2 $ME | grep fin | cut -d ":" -f 2 | ./me_p2
		done
		printf "\n\n"
	done
done
