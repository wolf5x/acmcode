#!/bin/bash

SEED_BEGIN=10
SEED_END=20

echo > cake.out
for((i=$SEED_BEGIN;i<$SEED_END;i++))
do
	echo "Seed $i" >> cake.out
	java -jar Tester.jar -seed $i -exec ./cake >> cake.out 
done
