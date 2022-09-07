#!/bin/bash -i

store_dir="/tmp/CP"
test=$1

mkdir -p $store_dir

#compiling the cpp files
alias compile_prefix="g++ -std=gnu++20 -I/mnt/Drive1/CP/Algo_Library/includes/ -DPRABH"
compile_prefix gen.cpp -o $store_dir/gen || { echo -e "\n\e[1;31mCompilation Error : \e[0mGenerator\n"; exit 1; }
compile_prefix $test.cpp -o $store_dir/test || { echo -e "\n\e[1;31mCompilation Error : \e[0mTestFile\n"; exit 1; }
compile_prefix good.cpp -o $store_dir/good || { echo -e "\n\e[1;31mCompilation Error :\e[0mGoodFile\n"; exit 1; }
compile_prefix checker.cpp -o $store_dir/checker || { echo -e "\n\e[1;31mCompilation Error : \e[0mChecker\n"; exit 1; }

echo -e -n "\n\e[1;36mCompilation Successful\e[0m\n"

#running stress
for((i = 1; ; ++i)); do
    echo -e -n "\033[1;32m\rRunning Test : \033[0m" $i
    $store_dir/gen $i > $store_dir/input_file
    $store_dir/test < $store_dir/input_file > $store_dir/myAnswer
    $store_dir/good < $store_dir/input_file > $store_dir/correctAnswer
    $store_dir/checker > $store_dir/checker_log
    if (($? != 0)); then
        break
    fi
done

#printing out the results
printf "\n\e[1;33mCounter Test\e[0m\n"
cat $store_dir/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat $store_dir/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat $store_dir/myAnswer 
printf "\n\e[1;33mChecker's Verdict\e[0m\n"
cat $store_dir/checker_log 
printf "\n"

