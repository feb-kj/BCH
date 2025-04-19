# BCH 
This release is a C program that implements the BCH(15,7) code for detecting and correcting errors in a codeword. Below are the main points describing the release:
#

> **Objectives of the Release**

1. **Data encoding**: Transforms an input of 7 bits of data into a codeword of 15 bits using the _H_ matrix, which represents the code BCH(15,7). The codeword includes both data bits and control bits to detect and correct errors.
2. **Error simulation**: Introduces two random errors into the generated codeword, simulating the error conditions in a transmission channel.
3. **Error detection**: Calculate the syndrome _S_ to identify errors in the transmitted codeword.
4. **Diagnostic output**: Shows the original codeword, the codeword with simulated errors, the calculated syndrome and the locations of the detected errors.

> **Technical characteristics**
Matrix BCH:

1. The matrix _H_:
    - is declared as a matrix 8×15 containing control bits, parity bits and data bits.
    - H follows the rules of the code BCH(15,7) for the construction of the codeword.

4. Implemented Functions:
    - `calcsyn`: Calculate the syndrome _S_ by performing AND and XOR operations on the bits of the codeword and matrix _H_. The syndrome is used to diagnose errors.
    - `gene_codeword`: Generates a codeword from the bits of data provided by the user. Adds the calculated control bits.
    - `error_sim`: Introduces two random errors in the codeword, ensuring that the two errors are on different positions.

3. User Interface:
    - The user enters 7 bits of data (one at a time).
    - The program provides visual feedback in the console, such as terminal color and a custom title.

4. Structure of the Programme:
    - Statement of constants for sizing the matrix and codeword.
    - Use of global variables per iteration (indices _i_,_j_).
    - Initialization of random numbers with srand(time(NULL)) to simulate errors.

5. Output:
    - Codeword calculated.
    - Code word with simulated errors.
    - Syndrome _S_.
    - Positions of simulated errors.
