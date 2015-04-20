#!/bin/bash


#assemble the sorts
nasm -f elf32 BubbleSort.asm
nasm -f elf32 SelectionSort.asm
nasm -f elf32 InsertionSort.asm
nasm -f elf32 QuickSort.asm

#compile main.c
gcc -std=c99 -m32 -c main.c

#link the project
gcc -std=c99 -m32 main.o BubbleSort.o SelectionSort.o InsertionSort.o QuickSort.o

#delete build files
rm main.o
rm BubbleSort.o
rm SelectionSort.o
rm InsertionSort.o
rm QuickSort.o
