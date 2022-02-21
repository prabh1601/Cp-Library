set -e

# relative location to store the (build and data) files
store_dir='/mnt/Drive1/CP/TestCases'
cur_dir=$(dirname "$0")

#compiling the cpp files
g++ -std=c++20 $cur_dir/test_Generator.cpp -o $store_dir/gen || { echo -e "\n\e[1;31mCompilation Error : \e[0mGenerator\n"; exit 1; }
g++ -std=c++20 $cur_dir/test.cpp -o $store_dir/test || { echo -e "\n\e[1;31mCompilation Error : \e[0mTestFile\n"; exit 1; }
g++ -std=c++20 $cur_dir/test_Good.cpp -o $store_dir/good || { echo -e "\n\e[1;31mCompilation Error : \e[0mGoodFile\n"; exit 1; }

echo -e -n "\n\e[1;36mCompilation Successful\e[0m\n"

#running stress
for((i = 1; ; ++i)); do
    echo -e -n "\033[1;32m\rRunning Test : \033[0m" $i
    $store_dir/gen $i > $store_dir/input_file
    $store_dir/test < $store_dir/input_file > $store_dir/myAnswer
    $store_dir/good < $store_dir/input_file > $store_dir/correctAnswer
    diff -Z $store_dir/myAnswer $store_dir/correctAnswer > /dev/null || break
done

#printing out the results
printf "\n\n\e[1;33mCounter Test\e[0m\n"
cat $store_dir/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat $store_dir/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat $store_dir/myAnswer 
printf "\n\n"
