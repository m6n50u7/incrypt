# incrypt
a file encryption tool using vigener cipher.<br />
how to compile for linux:
>gcc incrypt.c -o incrypt<br />
>gcc dicrypt.c -o dicrypt

how to use the tool:<br/>
to encrypt file to a new file:<br/>
>incrypt SRC DEST PASS<br />
>dicrypt SRC DEST PASS<br/>

to encrypt the file itself:<br/>
>incrypt FILE PASS<br />
>dicrypt FILE PASS<br/>

to encrypt the buffer:
>incrypt PASS<br />
>dicrypt PASS
# Features:
- password's size can have any length between 1 byte and file size.
- the algorithm is very fast.
- you can use the decryption algorithm as encryption algorithm.
- the algorithm support both ASCII and UTF8 and can support other codes.
# Notes:
- if the password's size was bigger than the file itself, the extra bytes will be useless.
- using repeated passwords like "abcabc" is just like using "abc". but this doesn't apply on passwords like "abc0abc".
- in case of the cracker knows the content of the begining of the file, he maybe able to use it to get the entire password if the part's size was bigger than password's size.
- even if the known part's size was small, knowing the password's size can let the cracker get parts of the original file.
