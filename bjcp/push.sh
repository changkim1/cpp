DATE=$(date "+%y%m%d%h%s")

echo ${DATE}
git add *
git commit -m "$DATE"