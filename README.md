# JSON minifier 

This is a simple JSON minifier implementation that removes whitespaces from a JSON passed on the STDIN and outputs minified JSON on the STDOUT. Minifier does not parse anything but just rather uses simple state machine to remove whitespaces not contained within a string.

It's capable of processing 1Gb/s when reading from `tmpfs` on a `Ryzen 7` CPU.

Compile it with `gcc -03 json-minify.c -o json-minify`

