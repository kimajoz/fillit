# fillit
Fillit is a program that take in parameter a file that describe a list of Tetriminos that he will then arrange them to form the smallest possible square.

The goal is of course to find this smallest square as quickly as possible despite a number of arrangements thats grows explosively with each additional piece.

# How to use it :

- git clone http://github.com/pbillett/fillit.git && cd fillit
- make re && ./fillit [file]
<code>

      example : ./fillit extern_file.txt
      
</code>

# How to create new file

The executable must take a parameter (and only one) file describing the list of the tetriminos to arrange. 
This file is formatted very precisely:

- Each description of an tetriminos is 4 lines
- Two tetriminos are separated by a blank line

The description of a Tetriminos should respect the rules below :

- Exactly 4 lines of 4 caracters follow by a line break.
- A Tetriminos is a piece of classic Tetris composed by 4 blocs.
- Each caracter should be, or a ’#’ when the box correspond to one of the four blocs of a Tetriminos, 
or a ’.’ when the box is empty.
- Each bloc of a Tetriminos should be in contact with at least an other bloc on one or the other of his 4 sides.

- An example of file named extern_file.txt should also be found on the root of the repository for testing.
- Here is an example of the valid tetriminos:</br>

<TABLE BORDER="1">
  <TR> 
 <TH> 
    ....</br>
    ..##</br>
    ..#.</br>
    ..#.</br>
 </TH>
 <TH>
    ####</br>
    ....</br>
    ....</br>
    ....</br>
 </TH> 
 <TH>
    ....</br>
    ....</br>
    ##..</br>
    ##..</br>
 </TH>
 <TH>
    .##.</br>
    ..##</br>
    ....</br>
    ....</br>
 </TH>
 <TH>
    ....</br>
    .##.</br>
    ##..</br>
    ....</br>
 </TH>
 <TH>
    .#..</br>
    ###.</br>
    ....</br>
    ....</br>
 </TH>
 <TH>
    ....</br>
    .##.</br>
    ..#.</br>
    ..#.</br>
 </TH>
 <TH>
    ...#</br>
    ...#</br>
    ...#</br>
    ...#</br>
 </TH>
 <TH>
    #...</br>
    ###.</br>
    ....</br>
    ....</br>
 </TH>
  </TR> 
</TABLE>
