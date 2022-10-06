// * Redirections
// * 1 - < countries.txt grep -v ^A > nA_countries.txt

/*
 TODO * PIPELINE:
  
* {
*	path = "/usr/bin/grep";
*	args = {"grep", "-v", "^A", NULL};
*	in_fd = open("countries.txt", RDONLY);
*	outf_fd = open("nAcountries.txt", RWONLY);
*	exec = 1;
*	builtin = 0;
*	next = NULL;
* }

*/

// * 2) < infile grep ^a | sort -r | head -10 | uniq -c | wc > outfile
/*
  
* {
*	path = "/usr/bin/grep";
*	args = {"grep", "^a", NULL};
*	in_fd = open(infile);
*	outf_fd = -2;
*	exec = 1;
*	builtin = 0;
*	next = second;
* }
 
* {
*	path = "/usr/bin/sort";
*	args = {"sort", "-r"};
*	in_fd = -2;
*	outf_fd = -2;
*	exec = 1;
*	builtin = 0;
*	next = third;
* }
 
* {
*	path = "/usr/bin/head";
*	args = {"head", "-10", NULL};
*	in_fd = -2;
*	outf_fd = -2;
*	exec = 1;
*	builtin = 0;
*	next = fourth;
* }


* {
*	path = "/usr/bin/uniq";
*	args = {"uniq", "-c"};
*	in_fd = -2;
*	outf_fd = -2;
*	exec = 1;
*	builtin = 0;
*	next = fifth;
* }


* {
*	path = "/usr/bin/wc";
*	args = {"wc", NULL};
*	in_fd = -2;
*	outf_fd = open(outfile);
*	exec = 1;
*	builtin = 0;
*	next = NULL;
* }
*/