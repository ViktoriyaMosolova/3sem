DATE = $(date)

all:
	mydir=$(DATE)
	echo $(mydir)
push:
	git push origin master