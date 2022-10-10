#!/bin/bash

function test_sifl {
	local file=$1
	local replace=$2
	local replace_with=$3
	local expected=$4

	printf "\x1b[36;3m"
	"$SIFL" "$file" "$replace" "$replace_with"
	local output=$?
	printf "\x1b[0m"

	if [ $output -eq 0 ]; then
		if [ $expected -eq 0 ]; then
			printf "\x1b[32mCorrectly\x1b[0m ran"
			local thing=$(diff "$file.replace" <(sed "s/$replace/$replace_with/g" < "$file"))
			if [[ $thing == "" ]]; then
				printf " and \x1b[32mcorrectly\x1b[0m replaced"
			else
				printf ", but \x1b[31mincorrectly\x1b[0m replaced"
			fi
			printf " at line $BASH_LINENO\n"
			if [[ $thing != "" ]]; then
				printf "%s\n" "$thing"
			fi
		else
			printf "\x1b[31mIncorrectly\x1b[0m ran at line $BASH_LINENO\n" >&2
		fi
	else
		if [ $expected -eq 0 ]; then
			printf "\x1b[31mIncorrectly\x1b[0m aborted at line $BASH_LINENO\n" >&2
		else
			printf "\x1b[32mCorrectly\x1b[0m aborted at line $BASH_LINENO\n"
		fi
	fi

	return $output
}

function run_tests {
	EXPECT_ERROR=1
	EXPECT_SUCCESS=0

	touch empty_file
	echo "Hello World" > hello_world
	echo "Hello Hello HolleHello" > hello_world2
	touch file_wrong_permissions
	chmod 000 file_wrong_permissions
	touch test

	test_sifl empty_file "" "test" $EXPECT_ERROR
	test_sifl nonexistant_file "Hello" "Hi" $EXPECT_ERROR
	test_sifl file_wrong_permissions "Hello" "Hi" $EXPECT_ERROR

	test_sifl test "Hello" "Hi" $EXPECT_SUCCESS
	test_sifl test "Hello" "Hi" $EXPECT_SUCCESS
	chmod 000 test.replace
	test_sifl test "Hello" "Hi" $EXPECT_ERROR

	test_sifl empty_file "a" "test" $EXPECT_SUCCESS
	test_sifl hello_world "Hello" "Hi" $EXPECT_SUCCESS
	test_sifl hello_world2 "Hello" "Hi" $EXPECT_SUCCESS
}

INITIAL_DIR=$( pwd )
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SIFL="$SCRIPT_DIR/sed-is-for-losers"
TEST_DIR="$SCRIPT_DIR/tmp_tests"

rm -rf "$TEST_DIR"
mkdir "$TEST_DIR"

cd "$TEST_DIR"

run_tests

cd "$INITIAL_DIR"
rm -rf "$TEST_DIR"
