set -e

#relative location to store the files
relative_directory='/mnt/Drive1/CP/TestCases'

#compiling the cpp files
g++ -std=c++17 test_Generator.cpp -o $relative_directory/gen || { echo -e "\n\e[1;31mCompilation Error : \e[0mGenerator\n"; exit 1; }
g++ -std=c++17 test.cpp -o $relative_directory/test || { echo -e "\n\e[1;31mCompilation Error : \e[0mTestFile\n"; exit 1; }
g++ -std=c++17 test_Good.cpp -o $relative_directory/good || { echo -e "\n\e[1;31mCompilation Error :\e[0mGoodFile\n"; exit 1; }
g++ -std=c++17 test_checker.cpp -o $relative_directory/checker || { echo -e "\n\e[1;31mCompilation Error : \e[0mChecker\n"; exit 1; }

echo -e -n "\n\e[1;36mCompilation Successful\e[0m\n"

#running stress
for((i = 1; ; ++i)); do
    echo -e -n "\033[1;32m\rRunning Test : \033[0m" $i
    $relative_directory/gen $i > $relative_directory/input_file
    $relative_directory/test < $relative_directory/input_file > $relative_directory/myAnswer
    $relative_directory/good < $relative_directory/input_file > $relative_directory/correctAnswer
    $relative_directory/checker > $relative_directory/checker_log
done
    
