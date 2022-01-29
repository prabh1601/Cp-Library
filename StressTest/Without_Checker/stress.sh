set -e

# relative location to store the (build and data) files
relative_directory='/mnt/3E86036E860325CD/CP/TestCases'

#compiling the cpp files
g++ -std=c++20 test__Generator.cpp -o $relative_directory/gen || { echo -e "\n\e[1;31mCompilation Error : \e[0mGenerator\n"; exit 1; }
g++ -std=c++20 test.cpp -o $relative_directory/test || { echo -e "\n\e[1;31mCompilation Error : \e[0mTestFile\n"; exit 1; }
g++ -std=c++20 test__Good.cpp -o $relative_directory/good || { echo -e "\n\e[1;31mCompilation Error : \e[0mGoodFile\n"; exit 1; }

echo -e -n "\n\e[1;36mCompilation Successful\e[0m\n"

#running stress
for((i = 1; ; ++i)); do
    echo -e -n "\033[1;32m\rRunning Test : \033[0m" $i
    $relative_directory/gen $i > $relative_directory/input_file
    $relative_directory/test < $relative_directory/input_file > $relative_directory/myAnswer
    $relative_directory/good < $relative_directory/input_file > $relative_directory/correctAnswer
    diff -Z $relative_directory/myAnswer $relative_directory/correctAnswer > /dev/null || break
done

#printing out the results
printf "\n\n\e[1;33mCounter Test\e[0m\n"
cat $relative_directory/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat $relative_directory/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat $relative_directory/myAnswer 
printf "\n\n"
