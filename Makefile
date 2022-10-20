all:
	git status
	git add .
	git status
	git commit -m "10.22"
push:
	git push origin master