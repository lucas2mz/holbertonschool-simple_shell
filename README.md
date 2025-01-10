<h1  align="center">¡Nuestra Shell!!</h1>

<p align="center">En este proyecto implementaremos la unix shell command line interpreter ejecutando comandos entrantes que el usuario mande, para lograr esto usaremos:

tokenizacion de comandos de entrada por el usuario

Buscando comandos ejecutables en el path

Agregando comandos como env, exit..

Nuestra shell lee la entrada del user, tokeniza y ejecuta el comando concreto con llamadas al sistema como execve, fork y wait.
ejecuta hasta que el usuario la cierre</p>

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
  <li>Shell.c la función principal.</li>
  <li>Functions.c, Functions2.c Agrupamos todos los archivos que auxilian la función Shell.c.</li>
  <li>Main.h  archivo en la que declaramos funciones y librerías.</li>
  </ul>
</p>

<h2  align="center">Flow Chart</h2>
<p align="center">
  <img src="https://i.imgur.com/MDyKfYl.png" alt="Flowchart of Shell" style="max-width: 100%; height: auto;">
</p>


<h2 align="center">Authors</h2>

<p align="center">Este projecto fue codeado por Lucas Andrada y Owen Matusevicius. Cohort 25 </p>
