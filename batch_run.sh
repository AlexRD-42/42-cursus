#!/usr/bin/env bash
make fclean > /dev/null
make all > /dev/null
echo Make finished
for i in {1..4}; do
	for i in {1..25}; do
		./build/philo 3 181 60 30 500 | grep 'died' &
	done
	wait
	echo ----
done
echo done
