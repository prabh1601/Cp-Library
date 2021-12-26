set -e
g++ -std=c++20 test__Generator.cpp -o /mnt/3E86036E860325CD/CP/TestCases/gen || { echo -e "\n\e[1;31mCompilation Error : \e[0mGenerator\n"; exit 1; }
g++ -std=c++20 test.cpp -o /mnt/3E86036E860325CD/CP/TestCases/test || { echo -e "\n\e[1;31mCompilation Error : \e[0mTestFile\n"; exit 1; }
g++ -std=c++20 test__Good.cpp -o /mnt/3E86036E860325CD/CP/TestCases/good || { echo -e "\n\e[1;31mCompilation Error : \e[0mGoodFile\n"; exit 1; }

echo -e -n "\n\e[1;36mCompilation Successful\e[0m\n"

for((i = 1; ; ++i)); do
    /mnt/3E86036E860325CD/CP/TestCases/gen $i > /mnt/3E86036E860325CD/CP/TestCases/input_file
    /mnt/3E86036E860325CD/CP/TestCases/test < /mnt/3E86036E860325CD/CP/TestCases/input_file > /mnt/3E86036E860325CD/CP/TestCases/myAnswer
    /mnt/3E86036E860325CD/CP/TestCases/good < /mnt/3E86036E860325CD/CP/TestCases/input_file > /mnt/3E86036E860325CD/CP/TestCases/correctAnswer
    diff -Z /mnt/3E86036E860325CD/CP/TestCases/myAnswer /mnt/3E86036E860325CD/CP/TestCases/correctAnswer > /dev/null || break
    echo -e -n "\033[1;32m\rRunning Test : \033[0m" $i
done

printf "\n\n\e[1;33mCounter Test\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/myAnswer 
printf "\n\n"