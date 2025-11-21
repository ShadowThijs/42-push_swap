#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
RESET='\033[0m'

# Default push_swap executable
PUSH_SWAP="./push_swap"

# Check if push_swap exists
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap executable not found!${RESET}"
    echo "Please compile push_swap first."
    exit 1
fi

# Clear screen
clear

echo -e "${BLUE}╔════════════════════════════════════════╗${RESET}"
echo -e "${BLUE}║    Push_Swap Benchmark Tool v1.0      ║${RESET}"
echo -e "${BLUE}╔════════════════════════════════════════╗${RESET}"
echo ""

# Get number of runs
echo -e "${CYAN}How many test runs do you want to perform?${RESET}"
read -p "Number of runs: " NUM_RUNS

# Validate input
if ! [[ "$NUM_RUNS" =~ ^[0-9]+$ ]] || [ "$NUM_RUNS" -lt 1 ]; then
    echo -e "${RED}Invalid input! Please enter a positive number.${RESET}"
    exit 1
fi

# Get number of elements
echo -e "${CYAN}How many numbers do you want to sort?${RESET}"
read -p "Number of elements: " NUM_ELEMENTS

# Validate input
if ! [[ "$NUM_ELEMENTS" =~ ^[0-9]+$ ]] || [ "$NUM_ELEMENTS" -lt 2 ]; then
    echo -e "${RED}Invalid input! Please enter a number >= 2.${RESET}"
    exit 1
fi

echo ""
echo -e "${YELLOW}Running $NUM_RUNS tests with $NUM_ELEMENTS numbers each...${RESET}"
echo ""

# Initialize variables
MIN_OPS=999999
MAX_OPS=0
TOTAL_OPS=0
FAILED_RUNS=0
WORST_CASE_INPUT=""

# Array to store all results
declare -a RESULTS

# Progress bar function
progress_bar() {
    local current=$1
    local total=$2
    local width=50
    local percentage=$((current * 100 / total))
    local completed=$((width * current / total))
    local remaining=$((width - completed))

    printf "\r${BLUE}Progress: [${RESET}"
    printf "%${completed}s" | tr ' ' 'o'
    printf "%${remaining}s" | tr ' ' '-'
    printf "${BLUE}] ${percentage}%%${RESET}"
}

# Run tests
echo -e "${CYAN}Testing in progress...${RESET}"
echo ""

for i in $(seq 1 $NUM_RUNS); do
    # Generate random unique numbers
    ARG=$(seq 1 $NUM_ELEMENTS | shuf | tr '\n' ' ')

    # Run push_swap and count operations
    OPS=$($PUSH_SWAP $ARG 2>/dev/null | wc -l)

    # Check if push_swap failed
    if [ -z "$OPS" ] || [ "$OPS" -eq 0 ]; then
        ((FAILED_RUNS++))
        continue
    fi

    # Store result
    RESULTS+=($OPS)

    # Update statistics
    TOTAL_OPS=$((TOTAL_OPS + OPS))

    if [ $OPS -lt $MIN_OPS ]; then
        MIN_OPS=$OPS
    fi

    if [ $OPS -gt $MAX_OPS ]; then
        MAX_OPS=$OPS
        WORST_CASE_INPUT="$ARG"
    fi

    # Show progress
    progress_bar $i $NUM_RUNS
done

echo ""
echo ""

# Calculate average
SUCCESSFUL_RUNS=$((NUM_RUNS - FAILED_RUNS))

if [ $SUCCESSFUL_RUNS -eq 0 ]; then
    echo -e "${RED}All tests failed!${RESET}"
    exit 1
fi

AVG_OPS=$((TOTAL_OPS / SUCCESSFUL_RUNS))

# Display results
echo -e "${GREEN}╔════════════════════════════════════════╗${RESET}"
echo -e "${GREEN}║           BENCHMARK RESULTS            ║${RESET}"
echo -e "${GREEN}╚════════════════════════════════════════╝${RESET}"
echo ""
echo -e "${CYAN}Test Configuration:${RESET}"
echo -e "  Numbers sorted:    ${YELLOW}$NUM_ELEMENTS${RESET}"
echo -e "  Total runs:        ${YELLOW}$SUCCESSFUL_RUNS${RESET}"
if [ $FAILED_RUNS -gt 0 ]; then
    echo -e "  Failed runs:       ${RED}$FAILED_RUNS${RESET}"
fi
echo ""
echo -e "${CYAN}Operation Statistics:${RESET}"
echo -e "  Minimum ops:       ${GREEN}$MIN_OPS${RESET}"
echo -e "  Maximum ops:       ${RED}$MAX_OPS${RESET}"
echo -e "  Average ops:       ${BLUE}$AVG_OPS${RESET}"
echo ""

# Determine grade based on common push_swap requirements
echo -e "${CYAN}Performance Grade:${RESET}"

get_grade() {
    local num=$1
    local ops=$2

    if [ $num -eq 3 ]; then
        if [ $ops -le 3 ]; then echo "✓ EXCELLENT"; else echo "✗ FAIL"; fi
    elif [ $num -eq 5 ]; then
        if [ $ops -le 12 ]; then echo "✓ EXCELLENT"; else echo "✗ FAIL"; fi
    elif [ $num -eq 100 ]; then
        if [ $ops -lt 700 ]; then
            echo "✓ EXCELLENT (5 points)"
        elif [ $ops -lt 900 ]; then
            echo "✓ GOOD (4 points)"
        elif [ $ops -lt 1100 ]; then
            echo "✓ OK (3 points)"
        elif [ $ops -lt 1300 ]; then
            echo "✓ PASS (2 points)"
        elif [ $ops -lt 1500 ]; then
            echo "✓ PASS (1 point)"
        else
            echo "✗ FAIL (0 points)"
        fi
    elif [ $num -eq 500 ]; then
        if [ $ops -lt 5500 ]; then
            echo "✓ EXCELLENT (5 points)"
        elif [ $ops -lt 7000 ]; then
            echo "✓ GOOD (4 points)"
        elif [ $ops -lt 8500 ]; then
            echo "✓ OK (3 points)"
        elif [ $ops -lt 10000 ]; then
            echo "✓ PASS (2 points)"
        elif [ $ops -lt 11500 ]; then
            echo "✓ PASS (1 point)"
        else
            echo "✗ FAIL (0 points)"
        fi
    else
        echo "N/A (custom size)"
    fi
}

echo -e "  Best run:          $(get_grade $NUM_ELEMENTS $MIN_OPS)"
echo -e "  Worst run:         $(get_grade $NUM_ELEMENTS $MAX_OPS)"
echo -e "  Average:           $(get_grade $NUM_ELEMENTS $AVG_OPS)"
echo ""

# Show distribution
echo -e "${CYAN}Operation Distribution:${RESET}"
echo -e "  Range: $MIN_OPS - $MAX_OPS (spread: $((MAX_OPS - MIN_OPS)))"
echo ""

# Calculate median
SORTED_RESULTS=($(printf '%s\n' "${RESULTS[@]}" | sort -n))
MEDIAN_INDEX=$((SUCCESSFUL_RUNS / 2))
MEDIAN=${SORTED_RESULTS[$MEDIAN_INDEX]}
echo -e "  Median ops:        ${BLUE}$MEDIAN${RESET}"
echo ""

# Show detailed breakdown
echo -e "${CYAN}Detailed Results (first 10 runs):${RESET}"
for i in $(seq 0 9); do
    if [ $i -lt $SUCCESSFUL_RUNS ]; then
        echo -e "  Run $((i + 1)):  ${RESULTS[$i]} operations"
    fi
done

if [ $SUCCESSFUL_RUNS -gt 10 ]; then
    echo -e "  ... (${YELLOW}$((SUCCESSFUL_RUNS - 10))${RESET} more runs)"
fi

echo ""

# Save worst case to file
if [ -n "$WORST_CASE_INPUT" ]; then
    echo "$WORST_CASE_INPUT" > output.txt
    echo -e "${YELLOW}Worst case input saved to output.txt${RESET}"
    echo -e "  Operations: ${RED}$MAX_OPS${RESET}"
    echo -e "  Test it with: ${CYAN}./push_swap \$(cat output.txt)${RESET}"
    echo ""
fi

echo -e "${GREEN}╔════════════════════════════════════════╗${RESET}"
echo -e "${GREEN}║          Benchmark Complete!           ║${RESET}"
echo -e "${GREEN}╚════════════════════════════════════════╝${RESET}"
