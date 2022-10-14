# COMPSCI 230 Computer Systems Principles
# Assembly Language Lab

In this lab we will use `objdump` on a binary (object) file corresponding to a short C program. You will be asked to answer a few questions about the output of `objdump` on Gradescope.

**PLEASE NOTE:** You may find this lab quite challenging if you haven't started the binary bomb project. Many students might not make it past the analysis of `fibonacci()`. That's OK! But you should make a good-faith effort to get as far as possible in this lab with your group and your TA and UCA in the room, so that you come up to speed as quickly as possible with reading assembly.

To start working on this lab you must be logged in to the Edlab and in your `cs230` directory, or be in a similar environment on your local machine. 

From this directory run the command:

```
$ git clone https://github.com/marcliberatore/230-lab-assembly.git
```

to make a copy of this lab directory, or use [Github Desktop](https://desktop.github.com), or download and decompress a zip file directly from Github to use locally (the green "Code" button has a "Download ZIP" option). 


In the directory you just downloaded, you will find a binary file `fibonacci`, as well as a C file `fibonacci.c`. The C file is incomplete -- the implementation of function `count()` is left out. (Don't overwrite the binary by attempting to recompile the C file!) You will need to use `objdump` to find out what this function does.

Run the following to disassemble the binary and save the generated assembly listing
to a file `output.txt`:

```
$ objdump -d fibonacci > output.txt
```

Open the `output.txt` file and find the assembly for `main`. With the help of
`fibonacci.c`, answer the following questions on Gradescope:

1. How many bytes are assigned for the stack frame for `main` (that is, the amount of memory between the addresses indicated by `%ebp` and `%esp` inclusive) right before `fibonacci()` is called (before executing `call` instruction)?
2. How many bytes are assigned for the stack frame for `main` (that is, the amount of memory between the addresses indicated by `%ebp` and `%esp` inclusive) right before `count()` is called (before executing `call` instruction)?
3. What integer values, register values or corresponding C variables are stored at the following locations within the `main` stack frame?
  * `-0x4(%ebp)`
  * `-0xc(%ebp)`
  * `-0x10(%ebp)`

Next, find the assembly for `fibonacci`. With the help of `fibonacci.c`, answer
the following questions on Gradescope:

1. Where are the following values stored on the stack frame for `fibonacci`? Please answer using the format `D(%ebp)`, where `D` specifies displacement offset.
  * `len`
  * The address of`seq[0]`
  * `i`
2. In a couple of sentences, explain what is the purpose of each of the following instructions. Please take note of the instruction offset (e.g., 121d) so that there is no confusion exactly which instruction you are asked to explain. If an instruction contains registers, you will also need to explain what integer values or corresponding C variables are stored in these registers.
  * `121d:       c1 e0 02                shl    $0x2,%eax`
  * `1224:       e8 fc ff ff ff          call   1225 <fibonacci+0x16>`
  * `1250:       05 ff ff ff 3f          add    $0x3fffffff,%eax`
  * `1275:       01 d0                   add    %edx,%eax`
  * `128a:       89 10                   mov    %edx,(%eax)`
  * `1293:       3b 45 08                cmp    0x8(%ebp),%eax`
  * `1298:       8b 45 f0                mov    -0x10(%ebp),%eax`

The easiest way to find answers to this question is to annotate every line of the
assembly for `fibonacci` as to what each instruction does.

Finally, look at the assembly for `count`, and annotate each line of the
instructions for `count`. Do the following on Gradescope:
1. In a couple of sentences, describe what `count` does.
2. Please copy the assembly for `count`, with your annotations, into a separate text file called `annotated_count.txt`, and upload it to Gradescope. (Please include the assembly and your annotations for `count` only.)