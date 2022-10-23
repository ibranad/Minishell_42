#!/usr/bin/expect

#Prog="minishell"
#File="test.txt"
spawn ./minishell
expect "Minishell $> "
#while read p; 
#do
#done <test.txt
send "cd\n"
expect "Minishell $> "
send "cd\n"
expect "Minishell $> "
send "cd ..\n"
expect "Minishell $> "
send "cd .\n"
expect "Minishell $> "
send "cd /Usersn\n"
expect "Minishell $> "
send "cd //\n"
expect "Minishell $> "
send "cd '//'\n"
expect "Minishell $> "
send "cd //////\n"
expect "Minishell $> "
send "cd ./././\n"
expect "Minishell $> "
send "cd /\n"
expect "Minishell $> "
send "cd '/etc'\n"
expect "Minishell $> "
send "cd '/var'\n"
expect "Minishell $> "
send "cd \"\$PWD/prompt\"\n"
expect "Minishell $> "
send "cd \"doesntexist\"\n"
expect "Minishell $> "
send "cd \"doesntexist\"\n"
expect "Minishell $> "
send "cd ../../..\n"
expect "Minishell $> "
send "cd ..\n"
expect "Minishell $> "
send "cd ..\n"
expect "Minishell $> "
send "cd ?\n"
expect "Minishell $> "
send "cd +\n"
expect "Minishell $> "
send "cd _\n"
expect "Minishell $> "
send "cd bark\n"
expect "Minishell $> "
send "cd '/'\n"
expect "Minishell $> "
send "cd \$PWD/file_tests\n"
expect "Minishell $> "
send "cd \$OLDPWD/builtins\n"
expect "Minishell $> "
send "echo\n"
expect "Minishell $> "
send "echo echo\n"
expect "Minishell $> "
send "eCho\n"
expect "Minishell $> "
send "eChO\n"
expect "Minishell $> "
send "eCHO\n"
expect "Minishell $> "
send "echo $\n"
expect "Minishell $> "
send "echo $\n"
expect "Minishell $> "
send "ECHO\n"
expect "Minishell $> "
send "echo rhobebou\n"
expect "Minishell $> "
send "echo stop\n"
expect "Minishell $> "
send "echo \"bonjour\"\n"
expect "Minishell $> "
send "echo bonjour\n"
expect "Minishell $> "
send "echo 'bonjour'\n"
expect "Minishell $> "
send "echo -n\n"
expect "Minishell $> "
send "echo -nn\n"
expect "Minishell $> "
send "echo -n\n"
expect "Minishell $> "
send "echo \"-n\"\n"
expect "Minishell $> "
send "echo -n\"-n\"\n"
expect "Minishell $> "
send "echo \"-nnnn\"\n"
expect "Minishell $> "
send "echo \"-nnnn\"\n"
expect "Minishell $> "
send "echo \"-n\n"
expect "Minishell $> "
send "echo \"-n\n"
expect "Minishell $> "
send "echo \$USER\n"
expect "Minishell $> "
send "echo \"\$USER\"\n"
expect "Minishell $> "
send "echo \"\'\$USER\'\"\n"
expect "Minishell $> "
send "echo \"\n"
expect "Minishell $> "
send "echo text\"\$USER\"\n"
expect "Minishell $> "
send "echo text\"\'\$USER'\"\n"
expect "Minishell $> "
send "echo \"text\"\n"
expect "Minishell $> "
send "echo '\n"
expect "Minishell $> "
send "echo text\n"
expect "Minishell $> "
send "echo \'\'\'\'\'\'\'\'\'\'\$USER\'\'\'\'\'\'\'\'\'\'\n"
expect "Minishell $> "
send "echo \"\"\"\"\"\"\"\"\$USER\"\"\"\"\"\"\"\"\n"
expect "Minishell $> "
send "echo \$USER'\$USER'text\n"
expect "Minishell $> "
send "echo \$USER\n"
expect "Minishell $> "
send "echo \'\n"
expect "Minishell $> "
send "echo \'\"\n"
expect "Minishell $> "
send "echo \\\"\n"
expect "Minishell $> "
send "echo \"\$USER\"\"\$USER\"\"\$USER\"\n"
expect "Minishell $> "
send "echo text\"\$USER\"test\n"
expect "Minishell $> "
send "echo \'\$USER\'\n"
expect "Minishell $> "
send "echo '\$USER'\n"
expect "Minishell $> "
send "echo \$USER\n"
expect "Minishell $> "
send "echo \"\$USER\"\"Users/\$USER/file\"\"'\$USER'\"'\$USER\n"
expect "Minishell $> "
send "echo \"\$USER\$USER\$USER\"\n"
expect "Minishell $> "
send "echo \'\$USER\'\"\$USER\"\'\$USER\'\n"
expect "Minishell $> "
send "echo '\"\$USER\"\'\'\$USER\'\"\"\"\$USER\"\n"
expect "Minishell $> "
send "echo \"\n"
expect "Minishell $> "
send "echo \"\n"
expect "Minishell $> "
send "echo \$USER=4\n"
expect "Minishell $> "
send "echo \$USER=thallard\n"
expect "Minishell $> "
send "echo \$USER\n"
expect "Minishell $> "
send "echo \$?\n"
expect "Minishell $> "
send "echo \$PWD/file\n"
expect "Minishell $> "
send "echo \"\$PWD/fil\"\n"
expect "Minishell $> "
send "echo \"text\"\n"
expect "Minishell $> "
send "echo \$PWD\n"
expect "Minishell $> "