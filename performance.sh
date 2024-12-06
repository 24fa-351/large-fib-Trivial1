#!/bin/bash

echo "Type,Width,Method,Input,Result" > performance.csv

# Iterate through different integer sizes
for type in uint8_t uint16_t uint32_t uint64_t; do
    for method in i r; do
        for input in 10 20 30 40; do
            result=$(./fib $input $method)
            echo "$type,$(sizeof $type),$method,$input,$result" >> performance.csv
        done
    done
done

echo "Performance data written to performance.csv"
