#!/bin/bash

for file in /usr/lib/**; do
	echo $file
	./ft_nm $file > test1
	nm $file > test2
	diff test1 test2
done
