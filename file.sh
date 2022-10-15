function test()
{
    bash_put=$(echo $1 | bash)
    mine_put=$(echo $1 | ./minishell)


    if [ ["$bash_put"] == ["$mine_put"] ]
    then 
    {
        echo "Your Good"
    }
    fi
}

test "ls"