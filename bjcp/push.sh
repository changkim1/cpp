DATE=$(date "+%y%m%d")

echo ${DATE}
git add *
git commit -m "$DATE"
git push