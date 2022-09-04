RES='./check'
EMPTY=""

if [[ -z $RES ]]
then
	echo -e "\033[32msuccess"
else
	echo -e "\033[31mfail"
fi