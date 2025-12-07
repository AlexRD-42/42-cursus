#!/usr/bin/env bash

make fclean > /dev/null
make re > /dev/null

echo "philo 5 800 200 200 30 | grep died"
_run "valgrind --tool=helgrind ./build/philo_bonus 5 800 200 200 30 | grep died" 1 1

echo "philo 4 410 200 200 30 | grep died"
_run "valgrind --tool=helgrind ./build/philo_bonus 4 410 200 200 30 | grep died" 1 1

echo "philo 4 405 200 200 30 | grep died"
_run "valgrind --tool=helgrind ./build/philo_bonus 4 405 200 200 30 | grep died" 1 1

echo "philo 3 700 200 100 30 | grep died"
_run "valgrind --tool=helgrind ./build/philo_bonus 3 700 200 100 30 | grep died" 1 1

echo "philo 3 605 200 100 30 | grep died"
_run "valgrind --tool=helgrind ./build/philo_bonus 3 605 200 100 30 | grep died" 1 1
