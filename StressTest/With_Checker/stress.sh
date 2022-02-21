set -e
dir='/mnt/Drive1/CP/Algo_Library/StressTest/With_Checker'
$dir/runChecker.sh

relative_directory='/mnt/Drive1/CP/TestCases'

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
