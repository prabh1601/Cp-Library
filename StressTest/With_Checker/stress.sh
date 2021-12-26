set -e
$bash ./runChecker.sh

printf "\n\e[1;33mCounter Test\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/myAnswer 
printf "\n\e[1;33mChecker's Verdict\e[0m\n"
cat /mnt/3E86036E860325CD/CP/TestCases/checker_log 
printf "\n"