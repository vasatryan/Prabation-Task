#!/bin/bash

# Check if two file paths are provided as arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 commonPassword.txt generatedPassword.txt"
    exit 1
fi

common_password_file="$1"
generated_password_file="$2"

# Check if both files exist
if [ ! -f "$common_password_file" ] || [ ! -f "$generated_password_file" ]; then
    echo "Error: Both files must exist."
    exit 1
fi

# Function to find common words and measure time
find_common_words() {
    start_time=$(date +%s.%N)

    # Use grep to find common words in both files
    common_words=$(grep -Fxf "$common_password_file" "$generated_password_file")

    # Print the common words
    if [ -n "$common_words" ]; then
        echo "Common words in both files:"
        echo "$common_words"
    else
        echo "No common words found."
    fi

    end_time=$(date +%s.%N)
    elapsed_time=$(echo "$end_time - $start_time" | bc)
    echo "Time taken: $elapsed_time seconds"
}

# Call the function
find_common_words
