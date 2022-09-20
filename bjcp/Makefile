PP		= g++
PFLAG	= -Wall -Werror -Wextra

SRC		= $(shell ls -t *.cpp | head -1)

DATE	= $(shell date "+%y%m%d")

all	:
		$(PP) $(PFLAG) $(SRC)
		@echo "\033[32mINPUT : "
		@./a.out

file :
		@echo $(SRC)

git :
		git add *
		git commit -m $(DATE)
		git push

.PHONY: all git file