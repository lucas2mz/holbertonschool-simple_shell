<h1  align="center">¡¡Our Shell!!</h1>

<p align="center">In this project we will implement the unix shell command line interpreter executing incoming commands that the user sends, to achieve this we will use:

tokenization of user input commands

Searching for executable commands in the path

Adding commands like env, exit..

Our shell reads the user's input, tokenizes it, and executes the specific command with system calls like execve, fork, and wait.
runs until the user closes it.</p>

<h2  align="center">What We're Working With</h2>
<p align="center">The project is divided into modular components, ensuring readability and maintainability.
<ul>
  <li>Editors: We were allowed to use only vi, vim, or emacs for writing the code, so we stick to vi.</li>
  <li>Compiler: We compiled using gcc with some strict flags (-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format).</li>
  <li>File Formatting: Each file concludes with a clean, single newline for proper formatting.</li>
  <li>Code Style: The project adheres to the Betty style guide, validated with betty-style.pl and betty-doc.pl.</li>
  <li>Coding Practices: Files were kept organized with a maximum of 5 functions each to ensure clarity and modularity.</li>
</ul>
</p>

<h2  align="center">Files</h2>
<p align="center">
  <ul>
  <li>Shell.c the main function.</li>
  <li>Functions.c, Functions2.c We group all the files that support the Shell.c function.</li>
  <li>Main.h  file in which we declare functions and libraries.</li>
  </ul>
</p>

<h2  align="center">Flow Chart</h2>
<p align="center">
  <img src="https://i.imgur.com/MDyKfYl.png" alt="Flowchart of Shell" style="max-width: 100%; height: auto;">
</p>


<h2 align="center">Authors</h2>

<p align="center">This project was co-authored by Lucas Andrada and Owen Matusevicius. Cohort 25 </p>
