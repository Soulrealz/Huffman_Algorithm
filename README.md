# Huffman_Algorithm
Decompressing text from console or file using C++

Input/Output.txt are default files for i/o
treeInformation and Compressed.txt hold the necessary information to restore compressed text
Original.txt holds text after decompression

Table class responsible for counting each unique element

TreeVector class responsible for holding the building blocks of HuffmanTree, basically taking elements into pairs and counting their occurances combined

HuffmanTree class encodes input into 1s and 0s and saves the necessary restore information alongside with being responsible for the restoration itself

Compression class basically holds each step necessary for the Huffman Algorithm. Class is static as no instance of it is required
