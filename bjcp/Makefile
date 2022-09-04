PP		= g++
PFLAG	= -Wall -Werror -Wextra

SRC		= $(shell ls -t *.cpp | head -1)

DATE	= $(shell date "+%y%m%d")

all	:
		$(PP) $(PFLAG) $(SRC)
		@echo "\033[32mcheck..."
		@bash check.sh

check :
		$(PP) $(PFLAG) check.cpp -o check
		@echo "\033[32mMAKE CHECK SUCCESS"

git :
		git add *
		git commit -m $(DATE)
		git push

.PHONY: all git check