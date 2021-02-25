#/bin/bash

GCDA=($(find . -name "*.gcda"))

echo "GCDA = ${GCDA}"

lcov -b . -d ${GCDA} -c -o result.info --rc lcov_branch_coverage=1

genhtml -o result result.info --branch-coverage
