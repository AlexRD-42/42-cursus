#!/usr/bin/env bash
make fclean > /dev/null
make all > /dev/null
echo Make finished
for i in {1..5}; do
	for i in {1..32}; do
		./build/philo 4 401 200 200 | grep 'died' &
	done
	wait
	echo ----
done
echo done
