# fortran

<4to95.c>
Simple translator file to convert fortran IV to fortran 95 code. Work in progress.
Use redirection to send in a .for file, and send the output to a new .f95 file.
Currently only:
-Converts upper to lower case
-Converts 'C' comments to '!'
-Converts .EQ. to ==    (for some reason, it is catching this in one of the comments)
