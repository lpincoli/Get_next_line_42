# Get_next_line_42
Reading a single line from a file
<h1>Get Next Line Project</h1>
<h2>Overview</h2>
<p>The objective of this project is to create a function that reads and returns a line from a file descriptor. This project is particularly insightful as it introduces a new intriguing concept in C programming: static variables.</p>
<h2>How to Use</h2>
<ol>
  <li>Clone this repository:</li>
  <pre><code>git clone https://github.com/lpincoli/Get_next_line_42.git</code></pre>
  <li>Go to the get_next_line directory:</li>
  <pre><code>cd get_next_line</code></pre>
  <li>Compile the source code with your desired buffer size (e.g., 42) using the following command:</li>
  <pre><code>gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c</code></pre>
</ol>
<h2>Features</h2>
<p>The main function, get_next_line(int fd), returns a line from the file descriptor passed to it.</p>
<ul>
  <li>If successful, the function returns the read line.</li>
  <li>If there is nothing else to read or an error occurred, the function returns NULL.</li>
  <li>The function works with any file as well as the standard input.</li>
  <li>The returned line will include the terminating \n character, unless the end of file is reached without a final \n character.</li>
</ul>
<p>Multiple calls to get_next_line() in a loop will allow you to read the entire text file, line by line. Additionally, the function has been optimized to read as little as possible with each call, efficiently processing each line.</p>

<p>Enjoy utilizing my Get Next Line implementation in your programming endeavors! :)</p>
