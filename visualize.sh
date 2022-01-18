#!/bin/bash
RED='\033[0;31m'
GREEN='\033[32m'
NC='\033[0m' # No Color
PUSH_SWAP_PATH="../"
SRC_PATH="src/"

function gitignore_check {
	path="${PUSH_SWAP_PATH}.gitignore"
	echo -n "" >> $path
	if ! grep "42_pushswap_visualiser/" $path ; then
		echo "42_pushswap_visualiser/" >> $path
	fi
	printf "${GREEN}.gitignore of your project is ignoring visualizer${NC}\n"
}

function push_swap_prepearing {
	if ! test -f "$PUSH_SWAP_PATH/Makefile"; then
		printf "${RED}Can't find Makefile${NC}\n\n"
		echo ""
		exit 0
	else
		make -C $PUSH_SWAP_PATH > /dev/null
		if ! test -f "$PUSH_SWAP_PATH/push_swap"; then
			printf "${RED}Can't find push_swap executable${NC}\n\n"
			exit 0
		fi
	fi
	make -C $PUSH_SWAP_PATH clean > /dev/null
	printf "${GREEN}Make file and push_swap detected${NC}\n"
}

function check_args() {
	if (($1 < 2)); then
		printf "${RED}No parameters found.${NC}\n\n"
		exit 0
	fi
}

function visualizer_prepearing {
	if ! test -f "${SRC_PATH}Makefile"; then
		printf "${RED}Can't find Makefile${NC}\n\n"
		echo ""
		exit 0
	else
		make -C ${SRC_PATH} > /dev/null
		if ! test -f "${SRC_PATH}/visual"; then
			printf "${RED}Can't find visual executable${NC}\n\n"
			exit 0
		fi
	fi
	make -C ${SRC_PATH} clean > /dev/null
	printf "${GREEN}VISUALISER detected${NC}\n"
}

echo ""
git pull
check_args $#
gitignore_check
push_swap_prepearing
./${PUSH_SWAP_PATH}push_swap $@ > operations.log
visualizer_prepearing
./${SRC_PATH}visual $@

#gcc -o src/push_swap_visual.c src/visual
#./src/visual

#echo ""
