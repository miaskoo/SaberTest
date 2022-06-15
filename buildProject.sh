#!/bin/bash
set -e

WORKINGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
HELP=false

function check_platform() {
	if [ "$PLATFORM" != "" ]; then
		echo choose only one platform
		exit
	fi

	var="$1"
	PLATFORM="${var:1}"
}

while [ "$1" != "" ]; do
	case "$1" in
		"-h")
			HELP=true
		;;
		"-help")
			HELP=true
		;;
		"-mvs22" | \
		"-mvs19" | \
		"-mac")
			check_platform $1
		;;
		*)
			echo Unknown command $1
			echo -e [-h] show help
			exit
		;;
	esac

    shift
done

function show_help() {
	echo -e '\t' [-mvs22] '\t\t' win mvs22 build
	echo -e '\t' [-mvs19] '\t\t' win mvs22 build
	echo -e '\t' [-mac] '\t\t' mac build
}

if [ $HELP == true ]; then
	show_help
	exit
fi

if [ "$PLATFORM" == "mac" ]; then
	echo -- build OS X project

	mkdir -p ./build/mac
	cd ./build/mac

	cmake ../.. -G Xcode
fi

if [ "$PLATFORM" == "mvs22" ] || [ "$PLATFORM" == "mvs19" ]; then
	echo -- building WIN32 project

	mkdir -p ./build/win32
	cd ./build/win32

	if [ "$PLATFORM" == "mvs22" ]; then
		cmake ../../ -G \
			"Visual Studio 17 2022" \
			-A \
			Win32 \
			-T \
			v143
	fi
	
	if [ "$PLATFORM" == "mvs19" ]; then
		cmake ../../ -G \
			"Visual Studio 16 2019" \
			-A \
			Win32 \
			-T \
			v142
	fi
fi
