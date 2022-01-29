set -e
$bash ./runChecker.sh

relative_directory='/mnt/3E86036E860325CD/CP/TestCases'

#printing out the results
printf "\n\e[1;33mCounter Test\e[0m\n"
cat $relative_directory/input_file
printf "\n\e[1;33mCorrect Answer\e[0m\n"
cat $relative_directory/correctAnswer 
printf "\n\e[1;33mYour Answer\e[0m\n"
cat $relative_directory/myAnswer 
printf "\n\e[1;33mChecker's Verdict\e[0m\n"
cat $relative_directory/checker_log 
printf "\n"
